#include "effect_row.hpp"
#include "editor_windows.hpp"
#include "editor.hpp"

using namespace editor;
using namespace bristol;

#pragma warning(disable: 4244)

namespace
{
  // bitmasks used for encoding control points in the selected keyframe
  const u32 SELECTED_NONE     = ~(u32)0;
  const u32 SELECTED_CP_IN    = 1u << 30;
  const u32 SELECTED_CP_OUT   = 1u << 31;
  const u32 SELECTED_CP_MASK  = ~(SELECTED_CP_IN | SELECTED_CP_OUT);

  const u32 ANIM_TYPE_LINEAR  = 0;
  const u32 ANIM_TYPE_BEZIER  = 1;
  const u32 ANIM_TYPE_STEP    = 2;

  //----------------------------------------------------------------------------------
  float log10(float x)
  {
    return logf(x) / logf(10);
  }

  //----------------------------------------------------------------------------------
  // from Graphic Gems 1
  float NiceNum(float x, bool round)
  {
    float e = floorf(log10(x));
    float f = x / powf(10, e);
    float nf = 10;
    if (round)
    {
      if (f < 1.5)
        nf = 1;
      else if (f < 3)
        nf = 2;
      else if (f < 7)
        nf = 5;
    }
    else
    {
      if (f <= 1)
        nf = 1;
      else if (f <= 2)
        nf = 2;
      else if (f <= 5)
        nf = 5;
    }

    return nf * powf(10, e);
  }

  void LooseLabel(float lower, float upper, float* tickSpacing, float* graphMin, float* graphMax)
  {
    const editor::protocol::Settings& settings = EDITOR.Settings();

    int NUM_TICKS = settings.ticks_per_interval();
    float range = NiceNum(upper - lower, false);
    float d = NiceNum(range / (NUM_TICKS-1), true);
    *tickSpacing = d;
    *graphMin = floorf(lower/d) * d;
    *graphMax = ceilf(upper/d) * d + 0.5f * d;
  }

//----------------------------------------------------------------------------------
  void DrawRow(RenderTexture& texture, float x, float y, float w, float h, const Color& color)
  {
    VertexArray curLine(sf::Lines);
    curLine.append(Vertex(Vector2f(x, y), color));
    curLine.append(Vertex(Vector2f(w, y), color));
    curLine.append(Vertex(Vector2f(x, y+h), color));
    curLine.append(Vertex(Vector2f(w, y+h), color));
    texture.draw(curLine);
  }
}

//----------------------------------------------------------------------------------
RowVar::RowVar(
    const Font& font,
    const string& name,
    FloatAnim* anim)
    : _font(font)
    , _name(name)
    , _value(0)
    , _anim(anim)
    , _selectedKeyframe(SELECTED_NONE)
{
  _text.setFont(font);
  _text.setCharacterSize(16);
}

//----------------------------------------------------------------------------------
void RowVar::Draw(RenderTexture& texture, bool drawKeyframes)
{
  const editor::protocol::Settings& settings = EDITOR.Settings();
  const Vector2f& windowSize = TimelineWindow::_instance->GetSize();

  Color bgCol = ::FromProtocol(_flags.IsSet(VarFlagsF::Selected)
      ? settings.effect_view_background_color_selected()
      : settings.effect_view_background_color());

  // draw background
  RectangleShape bgRect;
  bgRect.setPosition(_bounds.left, _bounds.top);
  bgRect.setSize(Vector2f(_bounds.width, _bounds.height));
  bgRect.setFillColor(bgCol);
  texture.draw(bgRect);

  // draw animating icon
  _text.setString("A");
  if (_flags.IsSet(VarFlagsF::Animating))
  {
    _text.setStyle(sf::Text::Bold);
    _text.setColor(Color(200, 200, 0));
  }
  else
  {
    _text.setStyle(sf::Text::Regular);
    _text.setColor(Color(200, 200, 200));
  }
  _text.setPosition(_bounds.left, _bounds.top);
  texture.draw(_text);

  // draw value
  const StyleSetting* style = _flags.IsSet(VarFlagsF::Editing)
    ? STYLE_FACTORY.GetStyle("var_text_editing")
    : STYLE_FACTORY.GetStyle("var_text_normal");

  _text.setString(to_string("%s: %.2f", _name.c_str(), _value).c_str());
  _text.setColor(style->fillColor);
  _text.setStyle(style->fontStyle);

  Vector2f pos(_bounds.left + 20, _bounds.top);
  _text.setPosition(pos.x, pos.y);
  texture.draw(_text);

  // draw row indicator
  DrawRow(texture, 0, pos.y, drawKeyframes ? windowSize.x : settings.effect_view_width(),
      _bounds.height, ::FromProtocol(settings.effect_line_color()));
}

//----------------------------------------------------------------------------------
Vector2f RowVar::ToLocal(int x, int y) const
{
  TimelineWindow* timeline = TimelineWindow::_instance;

  const Vector2f& windowPos = timeline->GetPosition();
  int xx = (int)(x - windowPos.x);
  int yy = (int)(y - windowPos.y);
  return Vector2f(xx, yy);
}

//----------------------------------------------------------------------------------
void RowVar::DrawKeyframes(RenderTexture& texture)
{
  _flags.Clear(VarFlagsF::GraphMode);

  const editor::protocol::Settings& settings = EDITOR.Settings();
  float h = settings.effect_row_height();
  int s = settings.keyframe_size();
  float ofs = (h - s) / 2;
  float y = _bounds.top;

  const StyleSetting* defaultStyle = STYLE_FACTORY.GetStyle("keyframe_style");
  const StyleSetting* selectedStyle = STYLE_FACTORY.GetStyle("keyframe_style_selected");

  _keyframeRect._rect.setSize(Vector2f(settings.keyframe_size(), settings.keyframe_size()));

  // draw the keyframes
  const Vector2f& windowSize = TimelineWindow::_instance->GetSize();
  for (u32 i = 0; i < _anim->keyframe.size(); ++i)
  {
    const FloatKeyframe& keyframe = _anim->keyframe[i];
    int keyX = TimelineWindow::_instance->TimeToPixel(keyframe.key.time);
    if (keyX >= settings.effect_view_width() && keyX < windowSize.x)
    {
      ApplyStyle(i == _selectedKeyframe ? selectedStyle : defaultStyle, &_keyframeRect._rect);

      _keyframeRect._rect.setPosition(keyX - s/2, y + ofs);
      texture.draw(_keyframeRect._rect);
    }
  }
}

//----------------------------------------------------------------------------------
bool RowVar::OnMouseButtonPressed(const Event &event)
{
  TimelineWindow* timeline = TimelineWindow::_instance;
  const editor::protocol::Settings& settings = EDITOR.Settings();
  Vector2f mousePos = ToLocal(event.mouseButton.x, event.mouseButton.y);
  Vector2f windowSize = timeline->GetSize();
  float x = mousePos.x, y = mousePos.y;

  _selectedKeyframe = SELECTED_NONE;

  int ofs = settings.keyframe_size();

  if (y >= _bounds.top && y < _bounds.top + _bounds.height)
  {
    // check for animation toggle
    FloatRect r(_bounds.left, _bounds.top, 10, _bounds.height);
    if (r.contains(mousePos))
    {
      _flags.Toggle(VarFlagsF::Animating);
      return true;
    }

    // check for variable edit
    r.left += 15;
    r.width = 50;
    if (r.contains(mousePos))
    {
      _flags.Set(VarFlagsF::PreEdit);
      return true;
    }

    // check for hit on the var window
    if (_bounds.contains(mousePos))
    {
      timeline->SendEffectEvent(this, EffectRowEvent(EffectRowEvent::Type::VarSelected));
      _flags.Toggle(VarFlagsF::Selected);
      return true;
    }

    if (!_flags.IsSet(VarFlagsF::GraphMode))
    {
      // check for keyframe intersection
      s64 t0 = timeline->PixelToTimeMs(x - ofs/2);
      s64 t1 = timeline->PixelToTimeMs(x + ofs/2);

      for (u32 i = 0; i < _anim->keyframe.size(); ++i)
      {
        FloatKeyframe& keyframe = _anim->keyframe[i];
        if (keyframe.key.time >= t0 && keyframe.key.time < t1)
        {
          _selectedKeyframe = i;
          return true;
        }
      }
    }
  }

  if (_flags.IsSet(VarFlagsF::GraphMode))
  {
    // if shift is pressed, create a new control point at the cursor pos
    if (Keyboard::isKeyPressed(Keyboard::Key::LShift))
    {
      s64 t = timeline->PixelToTimeMs(event.mouseButton.x);
      float y = event.mouseButton.y - timeline->GetPosition().y;
      float v = PixelToValue(y);

      switch (_anim->type)
      {
        case ANIM_TYPE_LINEAR:
          AddKeyframe<float>(milliseconds(t), v, true, _anim);
          break;

        case ANIM_TYPE_BEZIER:
        {
          // In bezier mode, evaluate the spline slightly before/after the new keyframe
          // to get good values for the control points..
          s64 t0 = max((s64)0, t - 250);
          s64 t1 = t + 250;
          float v0 = Interpolate<float>(*_anim, t0);
          float v1 = Interpolate<float>(*_anim, t1);

          FloatKeyframe* f = AddKeyframe<float>(milliseconds(t), v, true, _anim);
          f->cpIn  = { t0, v0 };
          f->cpOut = { t1, v1 };
          break;
        }

        case ANIM_TYPE_STEP:
          break;
      }

      return true;
    }

    // check for hit on keyframe/control point
    switch (_anim->type)
    {
      case ANIM_TYPE_LINEAR:
        for (u32 i = 0; i < _anim->keyframe.size(); ++i)
        {
          FloatKeyframe &keyframe = _anim->keyframe[i];
          if (KeyframeRect(keyframe.key, ofs).contains(mousePos))
          {
            _selectedKeyframe = i;
            _prevKeyframe = keyframe;
            return true;
          }
        }
        break;

      case ANIM_TYPE_BEZIER:
        // if in bezier, check for hits on control points
        for (u32 i = 0; i < _anim->keyframe.size(); ++i)
        {
          FloatKeyframe &keyframe = _anim->keyframe[i];

          s64 minT = min3(keyframe.cpIn.time, keyframe.key.time, keyframe.cpOut.time);
          s64 maxT = max3(keyframe.cpIn.time, keyframe.key.time, keyframe.cpOut.time);

          if (timeline->TimeToPixel(minT) < 0)
            continue;

          if (timeline->TimeToPixel(maxT) > windowSize.x)
            break;

          if (KeyframeRect(keyframe.key, ofs).contains(mousePos))
          {
            _selectedKeyframe = i;
            _prevKeyframe = keyframe;
            return true;
          }

          if (KeyframeRect(keyframe.cpIn, ofs).contains(mousePos))
          {
            _selectedKeyframe = i | SELECTED_CP_IN;
            _prevKeyframe = keyframe;
            return true;
          }

          if (KeyframeRect(keyframe.cpOut, ofs).contains(mousePos))
          {
            _selectedKeyframe = i | SELECTED_CP_OUT;
            _prevKeyframe = keyframe;
            return true;
          }
        }
        break;

      case ANIM_TYPE_STEP:
        break;
    }
  }

  return false;
}

//----------------------------------------------------------------------------------
bool RowVar::OnMouseButtonReleased(const Event &event)
{
//  _selectedKeyframe = SELECTED_NONE;

  if (_flags.IsSet(VarFlagsF::Animating) && _flags.IsSet(VarFlagsF::Editing))
  {
    AddKeyframe<float>(EDITOR.CurTime(), _value, false, _anim);
    _flags.Clear(VarFlagsF::PreEdit);
    _flags.Clear(VarFlagsF::Editing);
  }

  return false;
}

//----------------------------------------------------------------------------------
bool RowVar::OnMouseMoved(const Event &event)
{
  Vector2f mousePos = ToLocal(event.mouseMove.x, event.mouseMove.y);
  TimelineWindow* timeline = TimelineWindow::_instance;

  if (_selectedKeyframe != SELECTED_NONE)
  {
    vector<FloatKeyframe>& keyframes = _anim->keyframe;

    s64 t = timeline->PixelToTime(mousePos.x).total_milliseconds();

    if (_flags.IsSet(VarFlagsF::GraphMode))
    {
      if (_anim->type == 0)
      {
        // if moving past the previous or next keyframe, swap to it
        if (_selectedKeyframe > 0 && t < keyframes[_selectedKeyframe-1].key.time)
        {
          keyframes[_selectedKeyframe] = _prevKeyframe;
          _prevKeyframe = keyframes[--_selectedKeyframe];
        }

        if (_selectedKeyframe < keyframes.size() -1 && t >= keyframes[_selectedKeyframe+1].key.time)
        {
          keyframes[_selectedKeyframe] = _prevKeyframe;
          _prevKeyframe = keyframes[++_selectedKeyframe];
        }

        float y = event.mouseMove.y - timeline->GetPosition().y;
        keyframes[_selectedKeyframe].key = {t, PixelToValue(y)};
      }
      else
      {
        // bezier
        float y = event.mouseMove.y - timeline->GetPosition().y;
        u32 k = _selectedKeyframe & SELECTED_CP_MASK;

        if (_selectedKeyframe & SELECTED_CP_IN)
        {
          keyframes[k].cpIn = { t, PixelToValue(y) };
        }
        else if (_selectedKeyframe & SELECTED_CP_OUT)
        {
          keyframes[k].cpOut = { t, PixelToValue(y) };
        }
        else
        {
          s64 dx = t - keyframes[k].key.time;
          float dy = PixelToValue(y) - keyframes[k].key.value;
          keyframes[k].key = {t, PixelToValue(y)};

          keyframes[k].cpIn.time += dx;
          keyframes[k].cpIn.value += dy;

          keyframes[k].cpOut.time += dx;
          keyframes[k].cpOut.value += dy;
        }
      }
    }
    else
    {
      // don't allow the keyframe to move outside its neighbours
      if (_selectedKeyframe > 0)
        t = max(t, keyframes[_selectedKeyframe-1].key.time);

      if (_selectedKeyframe < keyframes.size() -1)
        t = min(t, keyframes[_selectedKeyframe+1].key.time);

      keyframes[_selectedKeyframe].key.time = t;
    }

    return true;
  }

  if (_flags.IsSet(VarFlagsF::PreEdit))
  {
    _flags.Clear(VarFlagsF::PreEdit);
    _flags.Set(VarFlagsF::Editing);
    _prevPos = mousePos;
  }

  if (_flags.IsSet(VarFlagsF::Editing))
  {
    Vector2f delta = mousePos - _prevPos;
    _prevPos = mousePos;
    _value += delta.x;
    return true;
  }

  return false;
}

//----------------------------------------------------------------------------------
bool RowVar::OnKeyReleased(const Event& event)
{
  switch (event.key.code)
  {
    case Keyboard::Key::Delete:
      if (_selectedKeyframe != SELECTED_NONE)
      {
        u32 idx = _selectedKeyframe & SELECTED_CP_MASK;
        _anim->keyframe.erase(_anim->keyframe.begin() + idx);
        _selectedKeyframe = SELECTED_NONE;
      }
      break;
  }
  return false;
}

//----------------------------------------------------------------------------------
void RowVar::OnEvent(RowVar* sender, const EffectRowEvent& event)
{
  if (event.type == EffectRowEvent::Type::VarSelected)
  {
    _flags.Clear(VarFlagsF::Selected);
    _flags.Clear(VarFlagsF::Editing);
    _flags.Clear(VarFlagsF::Animating);
    _flags.Clear(VarFlagsF::PreEdit);
  }
}

//----------------------------------------------------------------------------------
float RowVar::PixelToValue(float y) const
{
  // x = bottom - h * (value - minValue) / span
  // x - bottom = -h..
  // ==> value = (bottom - x) * span / h + minValue

  Vector2f size = TimelineWindow::_instance->GetSize();
  const editor::protocol::Settings& settings = EDITOR.Settings();
  float topY = settings.ticker_height();
  float h = size.y - settings.status_bar_height() - topY;
  float bottom = size.y - 1 - settings.status_bar_height();

  float span = _maxValue - _minValue;
  return (bottom - y) * span / h + _minValue;
}

//----------------------------------------------------------------------------------
float RowVar::ValueToPixel(float value) const
{
  // x = bottom - h * (value - minValue) / span

  Vector2f size = TimelineWindow::_instance->GetSize();
  const editor::protocol::Settings& settings = EDITOR.Settings();
  float topY = settings.ticker_height();
  float h = size.y - settings.status_bar_height() - topY;
  float bottom = size.y - 1 - settings.status_bar_height();

  float span = _maxValue - _minValue;
  float v = value - _minValue;
  return bottom - h * v / span;
}

//----------------------------------------------------------------------------------

void RowVar::VisibleKeyframes(
    const Vector2f& size,
    bool addBorderPoints,
    bool addOutsidePoints,
    vector<VisibleKeyframe>* keyframes)
{

  const editor::protocol::Settings& settings = EDITOR.Settings();
  float ofs = settings.effect_view_width();

  TimelineWindow* timeline = TimelineWindow::_instance;

  // find min/max values for keyframes within the view
  s64 minTime = timeline->PixelToTimeMs(0);
  s64 maxTime = timeline->PixelToTimeMs(size.x);

  float value0 = Interpolate<float>(*_anim, minTime);
  float valueLast = Interpolate<float>(*_anim, maxTime);

  _minValue = min(value0, valueLast);
  _maxValue = max(value0, valueLast);

  //vector<const FloatKeyframe*> validKeyframes;

  const FloatKeyframe* prevFrame = nullptr;
  const FloatKeyframe* keyframe = nullptr;
  u32 flags = 0;
  u32 prevFlags = 0;

  if (addBorderPoints)
    keyframes->push_back({Vector2f(ofs, ValueToPixel(value0)), nullptr, VisibleKeyframe::FLAG_VIRTUAL});

  u32 numKeyframes = _anim->keyframe.size();
  for (u32 i = 0; i < numKeyframes; ++i, prevFrame = keyframe, prevFlags = flags)
  {
    flags = i == 0 ? VisibleKeyframe::FLAG_FIRST : i == numKeyframes - 1 ? VisibleKeyframe::FLAG_LAST : 0;
    flags |= ((_selectedKeyframe & SELECTED_CP_MASK) == i) ? VisibleKeyframe::FLAG_SELECTED : 0;
    keyframe = &_anim->keyframe[i];

    if (keyframe->key.time < minTime)
      continue;

    if (keyframe->key.time > maxTime)
      break;

    // If this is the first inside keyframe, add the previous one of 'addOutsidePoints' is specified
    if (prevFrame && prevFrame->key.time < minTime && addOutsidePoints)
    {
      Vector2f p = Vector2f(timeline->TimeToPixel(prevFrame->key.time), ValueToPixel(prevFrame->key.value));
      keyframes->push_back({p, prevFrame, prevFlags});
    }

    Vector2f p = Vector2f(timeline->TimeToPixel(keyframe->key.time), ValueToPixel(keyframe->key.value));
    keyframes->push_back({p, keyframe, flags});

    switch (_anim->type)
    {
      case ANIM_TYPE_LINEAR:
        _minValue = min(_minValue, keyframe->key.value);
        _maxValue = max(_maxValue, keyframe->key.value);
        break;

      case ANIM_TYPE_BEZIER:
        if (flags & VisibleKeyframe::FLAG_FIRST)
        {
          _minValue = min3(_minValue, keyframe->key.value, keyframe->cpOut.value);
          _maxValue = max3(_maxValue, keyframe->key.value, keyframe->cpOut.value);
        }
        else if (flags & VisibleKeyframe::FLAG_LAST)
        {
          _minValue = min3(_minValue, keyframe->key.value, keyframe->cpIn.value);
          _maxValue = max3(_maxValue, keyframe->key.value, keyframe->cpIn.value);
        }
        else
        {
          _minValue = min4(_minValue, keyframe->key.value, keyframe->cpIn.value, keyframe->cpOut.value);
          _maxValue = max4(_maxValue, keyframe->key.value, keyframe->cpIn.value, keyframe->cpOut.value);
        }
        break;
    }
  }

  if (addOutsidePoints)
  {
    Vector2f p = Vector2f(timeline->TimeToPixel(keyframe->key.time), ValueToPixel(keyframe->key.value));
    keyframes->push_back({p, keyframe, flags});
  }

  if (addBorderPoints)
    keyframes->push_back({Vector2f(size.x, ValueToPixel(valueLast)), nullptr, VisibleKeyframe::FLAG_VIRTUAL});

  _realMinValue = _minValue;
  _realMaxValue = _maxValue;

  float step;
  LooseLabel(_minValue, _maxValue, &step, &_minValue, &_maxValue);
}

//----------------------------------------------------------------------------------
void RowVar::DrawGraph(RenderTexture& texture)
{
  _flags.Set(VarFlagsF::GraphMode);

  const editor::protocol::Settings& settings = EDITOR.Settings();
  int ofs = settings.effect_view_width();
  float rw = settings.keyframe_size() / 2.0f;

  TimelineWindow* timeline = TimelineWindow::_instance;
  Vector2f size = timeline->GetSize();

  // draw the background
  RectangleShape rect;
  rect.setPosition(settings.effect_view_width(), settings.ticker_height());
  rect.setSize(Vector2f(
      size.x - settings.effect_view_width(),
      size.y - settings.ticker_height()));

  rect.setFillColor(::FromProtocol(settings.timeline_view_background_color()));
  texture.draw(rect);

  // get the visible keyframes
  vector<VisibleKeyframe> keyframes;
  VisibleKeyframes(size, false, true, &keyframes);

  VertexArray gridLines(sf::Lines);

  float step;
  LooseLabel(_realMinValue, _realMaxValue, &step, &_minValue, &_maxValue);

  Color c(100, 100, 100, 255);
  Text label;
  label.setFont(_font);
  label.setCharacterSize(16);
  label.setColor(c);

  // draw min/max lines
  float curY = _maxValue;
  while (true)
  {
    if (curY < _minValue - step)
      break;

    float y = ValueToPixel(curY);
    gridLines.append(Vertex(Vector2f(ofs, y), c));
    gridLines.append(Vertex(Vector2f(size.x, y), c));

    label.setPosition(ofs + 10, y + 25);
    label.setString(to_string("%.2f", curY).c_str());
    texture.draw(label);

    curY -= step;
  }

  texture.draw(gridLines);

  const StyleSetting* defaultStyle = STYLE_FACTORY.GetStyle("keyframe_style");
  const StyleSetting* selectedStyle = STYLE_FACTORY.GetStyle("keyframe_style_selected");

  // draw the keyframes normalized to the min/max values
  switch (_anim->type)
  {
    case ANIM_TYPE_LINEAR:
    {
      VertexArray curLine(sf::LinesStrip);

      for (const auto& pp : keyframes)
      {
        const Vector2f& p = pp.p;
        curLine.append(Vertex(p));

        // if the point corresponds to a proper keyframe, draw the keyframe
        if (!(pp.flags & VisibleKeyframe::FLAG_VIRTUAL))
        {
          _keyframeRect._rect.setPosition(p.x - rw, p.y - rw);
          texture.draw(_keyframeRect._rect);
        }
      }

      texture.draw(curLine);
      break;
    }

    case ANIM_TYPE_BEZIER:
    {
      VertexArray controlPoints(sf::Lines);
      Color c = ::FromProtocol(settings.keyframe_control_color());

      LineStrip curve(4, ::FromProtocol(settings.graph_color()));

      u32 lastIdx = keyframes.size() - 2;
      for (u32 i = 0; i <= lastIdx; ++i)
      {
        u32 flags = keyframes[i].flags;

        const FloatKeyframe* k0 = keyframes[i+0].keyframe;
        const FloatKeyframe* k1 = keyframes[i+1].keyframe;

        if (!(k0 && k1))
          continue;

        const Vector2f& p0 = KeyToPoint(k0->key);
        const Vector2f& p1 = KeyToPoint(k0->cpOut);
        const Vector2f& p2 = KeyToPoint(k1->cpIn);
        const Vector2f& p3 = KeyToPoint(k1->key);

        ApplyStyle(flags & VisibleKeyframe::FLAG_SELECTED ? selectedStyle : defaultStyle, &_keyframeRect._rect);

        // draw key-in
        if (!(flags & VisibleKeyframe::FLAG_FIRST))
        {
          const Vector2f& keyIn = KeyToPoint(k0->cpIn);

          controlPoints.append(Vertex(keyIn, c));
          controlPoints.append(Vertex(p0, c));

          _keyframeRect._rect.setPosition(keyIn.x - rw, keyIn.y - rw);
          texture.draw(_keyframeRect._rect);
        }

        // draw key
        _keyframeRect._rect.setPosition(p0.x - rw, p0.y - rw);
        texture.draw(_keyframeRect._rect);

        // draw key-out
        if (!(flags & VisibleKeyframe::FLAG_LAST))
        {
          const Vector2f& keyOut = KeyToPoint(k0->cpOut);

          controlPoints.append(Vertex(p0, c));
          controlPoints.append(Vertex(keyOut, c));

          _keyframeRect._rect.setPosition(keyOut.x - rw, keyOut.y - rw);
          texture.draw(_keyframeRect._rect);
        }

        if (i == 0)
        {
          Vector2f v = Bezier(p0, p1, p2, p3, 0);
          curve.addPoint({p0.x, v.y});
        }

        for (u32 j = 1; j <= 20; ++j)
        {
          float t = j / 20.0f;
          Vector2f v = Bezier(p0, p1, p2, p3, t);
          curve.addPoint({lerp(p0.x, p3.x, t), v.y});
        }
      }
      texture.draw(curve);
      texture.draw(controlPoints);
      break;
    }
  }
}

//----------------------------------------------------------------------------------
FloatRect RowVar::KeyframeRect(const FloatKey& k, float ofs)
{
  TimelineWindow* timeline = TimelineWindow::_instance;
  return FloatRect(timeline->TimeToPixel(k.time) - ofs/2, ValueToPixel(k.value) - ofs/2, ofs, ofs);
}

//----------------------------------------------------------------------------------
Vector2f RowVar::KeyToPoint(const FloatKey& k)
{
  TimelineWindow* timeline = TimelineWindow::_instance;
  return Vector2f(timeline->TimeToPixel(k.time), ValueToPixel(k.value));
}

//----------------------------------------------------------------------------------
EffectRow::EffectRow(const Font& font, const string& str, EffectRow* parent)
    : _str(str)
    , _parent(parent)
    , _font(font)
    , _level(0)
    , _id(0)
{
  _rect._style = STYLE_FACTORY.CreateStyle("default_row_color");
  _keyframeRect._style = STYLE_FACTORY.CreateStyle("keyframe_style");
  _keyframeRect._rect.setSize(Vector2f(6, 6));

  _text.setFont(font);
  _text.setCharacterSize(16);
  _flags.Set(EffectRow::RowFlagsF::Expanded);

  if (parent)
    _level = parent->_level + 1;
}

//----------------------------------------------------------------------------------
EffectRow::~EffectRow()
{
  for (EffectRow* e : _children)
    delete e;

  _children.clear();
}

//----------------------------------------------------------------------------------
void EffectRow::Flatten(vector<EffectRow*>* res)
{
  deque<EffectRow*> q({this});
  while (!q.empty())
  {
    EffectRow* cur = q.front();
    q.pop_front();

    res->push_back(cur);
    for (EffectRow* c : cur->_children)
      q.push_back(c);
  }
}

//----------------------------------------------------------------------------------
void EffectRow::Reposition(float curY, float rowHeight)
{
  // Set position and size of current and child rows and vars
  // This will depend on scroll position and row's expanded state

  const editor::protocol::Settings& settings = EDITOR.Settings();
  const Vector2f windowSize = TimelineWindow::_instance->GetSize();

  deque<EffectRow*> q({this});
  while (!q.empty())
  {
    EffectRow* cur = q.front();
    q.pop_front();

    cur->_rect._rect.setPosition(0, curY);
    cur->_rect._rect.setSize(Vector2f(windowSize.x, (1 + cur->NumVars()) * rowHeight));
    curY += rowHeight;

    // If row is expanded, add children
    if (cur->_flags.IsSet(EffectRow::RowFlagsF::Expanded))
    {
      for (EffectRow* c : cur->_children)
        q.push_back(c);
    }

    const RectangleShape& shape = cur->_rect._rect;

    cur->_expandRect = FloatRect(
        cur->_level * 15 + shape.getPosition().x,
        shape.getPosition().y,
        15,
        15);

    // Set bounds for the vars
    for (u32 i = 0; i < cur->_vars.size(); ++i)
    {
      RowVar* var = cur->_vars[i];
      float x = 40 + cur->_level * 15 + shape.getPosition().x;
      var->_bounds = FloatRect(
          x,
          shape.getPosition().y + (i + 1) * rowHeight,
          settings.effect_view_width() - x,
          rowHeight);
    }
  }
}

//----------------------------------------------------------------------------------
float EffectRow::RowHeight(float rowHeight)
{
  float res = 0;

  deque<EffectRow*> q({this});
  while (!q.empty())
  {
    EffectRow* cur = q.front();
    q.pop_front();

    if (cur->_flags.IsSet(EffectRow::RowFlagsF::Expanded))
    {
      res += (1 + cur->NumVars()) * rowHeight;
      for (EffectRow* c : cur->_children)
        q.push_back(c);
    }
    else
    {
      res += rowHeight;
    }
  }

  return res;
}

//----------------------------------------------------------------------------------
bool EffectRow::OnMouseButtonPressed(const Event &event)
{
  const Vector2f& windowPos = TimelineWindow::_instance->GetPosition();
  int x = (int)(event.mouseButton.x - windowPos.x);
  int y = (int)(event.mouseButton.y - windowPos.y);
  Vector2f mousePos(x, y);

  if (_expandRect.contains(mousePos))
  {
    _flags.Toggle(EffectRow::RowFlagsF::Expanded);
    return true;
  }

  // check the vars
  for (RowVar* v : _vars)
  {
    if (v->OnMouseButtonPressed(event))
      return true;
  }

  if (_varEditRect.contains(mousePos))
  {
//    BeginEditVars(x, y);
    return true;
  }

  return false;
}

//----------------------------------------------------------------------------------
bool EffectRow::OnMouseMoved(const Event& event)
{
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
  {
    for (RowVar* v : _vars)
    {
      if (v->OnMouseMoved(event))
        return true;
    }
  }

  return false;
}

//----------------------------------------------------------------------------------
bool EffectRow::OnMouseButtonReleased(const Event &event)
{
  TimelineWindow* timeline = TimelineWindow::_instance;
  TimelineWindow::DisplayMode displayMode = timeline->GetDisplayMode();

  if (displayMode == TimelineWindow::DisplayMode::Graph)
  {
  }
  else
  {
    for (RowVar* v : _vars)
    {
      v->OnMouseButtonReleased(event);
    }
  }
  return false;
}

//----------------------------------------------------------------------------------
bool EffectRow::OnKeyReleased(const Event& event)
{

  for (RowVar* var : _vars)
  {
    if (var->OnKeyReleased(event))
      return true;
  }

  int a = 10;
//  Keyboard::Key code = event.key.code;

//  if (_flags.IsSet(RowFlagsF::Editing))
//  {
//    // escape aborts the pending operation
//    if (code == Keyboard::Escape)
//    {
//      EndEditVars(false);
//      EndKeyframeUpdate(false);
//    }
//
//    if (code == Keyboard::Return)
//    {
//      EndEditVars(true);
//    }
//    else
//    {
//      UpdateEditVar(event.key.code);
//    }
//
//    return true;
//  }

  return false;
}

//----------------------------------------------------------------------------------
void EffectRow::Draw(RenderTexture& texture, bool drawKeyframes)
{
  // Draw the keyframes before anything else so we can cheese a bit and draw over
  // any potential errant keyframes :)
  if (drawKeyframes)
  {
    for (RowVar* var : _vars)
      var->DrawKeyframes(texture);
  }

  const editor::protocol::Settings& settings = EDITOR.Settings();
  Color bgCol = ::FromProtocol(settings.effect_view_background_color());

  // draw background
  float w = settings.effect_view_width();
  _rect._rect.setFillColor(bgCol);
  Vector2f size = _rect._rect.getSize();
  Vector2f windowSize = TimelineWindow::_instance->GetSize();
  _rect._rect.setSize(Vector2f(w, size.y));
  texture.draw(_rect._rect);

  // draw text
  _text.setString(_str);
  _text.setPosition(_rect._rect.getPosition() + Vector2f(20 + _level * 15, 0) );
  _text.setColor(::FromProtocol(settings.var_text_color()));
  texture.draw(_text);

  FloatRect bounds = _rect._rect.getGlobalBounds();
  DrawRow(texture, bounds.left, bounds.top, drawKeyframes ? windowSize.x : w, bounds.height, ::FromProtocol(settings.effect_line_color()));

  // draw expanded indicator
  VertexArray tri(sf::Triangles);
  float left = _level * 15 + _rect._rect.getPosition().x;
  float top = _rect._rect.getPosition().y;
  float y = top;

  if (!_flags.IsSet(EffectRow::RowFlagsF::Expanded))
  {
    const StyleSetting* s = STYLE_FACTORY.GetStyle("effect_icon_collapsed_color");
    // y increases downwards
    tri.append(Vertex(Vector2f(left+5, y+5), s->fillColor));
    tri.append(Vertex(Vector2f(left+5, y+15), s->fillColor));
    tri.append(Vertex(Vector2f(left+15, y+10), s->fillColor));
    texture.draw(tri);
  }
  else
  {
    // Row is expanded, so draw the Vars and children
    const StyleSetting* s = STYLE_FACTORY.GetStyle("effect_icon_expanded_color");
    tri.append(Vertex(Vector2f(left+5, y+5), s->fillColor));
    tri.append(Vertex(Vector2f(left+15, y+5), s->fillColor));
    tri.append(Vertex(Vector2f(left+10, y+15), s->fillColor));
    texture.draw(tri);

    DrawVars(texture, drawKeyframes);

    for (EffectRow* child : _children)
    {
      child->Draw(texture, drawKeyframes);
    }
  }
}

//----------------------------------------------------------------------------------
void EffectRow::DrawVars(RenderTexture& texture, bool drawKeyframes)
{
  for (RowVar* var : _vars)
  {
    var->Draw(texture, drawKeyframes);
  }
}

//----------------------------------------------------------------------------------
void EffectRow::SendEvent(RowVar* sender, const EffectRowEvent& event)
{
  for (RowVar* var : _vars)
  {
    var->OnEvent(sender, event);
  }

  for (EffectRow* e : _children)
    e->SendEvent(sender, event);
}


//----------------------------------------------------------------------------------
EffectRowPlexus::EffectRowPlexus(
    const Font& font,
    const string& str,
    EffectRow* parent)
    : EffectRow(font, str, parent)
{
}

//----------------------------------------------------------------------------------
bool EffectRowPlexus::ToProtocol(google::protobuf::Message* msg) const
{
  effect::protocol::EffectSetting* proto = static_cast<effect::protocol::EffectSetting*>(msg);
  assert(!_parent);
  proto->set_type(effect::protocol::EffectSetting_Type_Plexus);

  effect::protocol::plexus::Plexus plexus;
  for (const EffectRow* row : _children)
  {
    row->ToProtocol(&plexus);
  }

  proto->set_config_msg(plexus.SerializeAsString());

  return true;
}

//----------------------------------------------------------------------------------
bool EffectRowPlexus::FromProtocol(const google::protobuf::Message& proto)
{
  const effect::protocol::plexus::Plexus& p =
      static_cast<const effect::protocol::plexus::Plexus&>(proto);

  for (const effect::protocol::plexus::TextPath& textPath : p.text_paths())
  {
    string str = to_string("TextPath: %s", textPath.text().c_str());

    _children.push_back(new EffectRowTextPath(_font, str, this));
    _children.back()->FromProtocol(textPath);
  }

  for (const effect::protocol::plexus::NoiseEffector& effector : p.noise_effectors())
  {
    string str = to_string("Noise (%s)",
      effector.apply_to() == effect::protocol::plexus::NoiseEffector_ApplyTo_Position
          ? "POS" : "SCALE");

    _children.push_back(new EffectRowNoise(_font, str, this));
    _children.back()->FromProtocol(effector);
  }

  return true;
}

//----------------------------------------------------------------------------------
EffectRowTextPath::EffectRowTextPath(
    const Font& font,
    const string& str,
    EffectRow* parent)
  : EffectRow(font, str, parent)
{
}

//----------------------------------------------------------------------------------
bool EffectRowTextPath::ToProtocol(google::protobuf::Message* msg) const
{
  effect::protocol::plexus::Plexus* proto = static_cast<effect::protocol::plexus::Plexus*>(msg);
  proto->add_text_paths()->set_text(_str);
  return true;
}

//----------------------------------------------------------------------------------
bool EffectRowTextPath::FromProtocol(const google::protobuf::Message& proto)
{
  const effect::protocol::plexus::TextPath& p = static_cast<const effect::protocol::plexus::TextPath&>(proto);
  _textPath = ::FromProtocol(p);
  return true;
}

//----------------------------------------------------------------------------------
EffectRowNoise::EffectRowNoise(
    const Font& font,
    const string& str,
    EffectRow* parent)
    : EffectRow(font, str, parent)
{
  _vars.push_back(new RowVar(_font, "x", &_effector.displacement.x));
  _vars.push_back(new RowVar(_font, "y", &_effector.displacement.y));
  _vars.push_back(new RowVar(_font, "z", &_effector.displacement.z));
}

//----------------------------------------------------------------------------------
bool EffectRowNoise::FromProtocol(const google::protobuf::Message& proto)
{
  const effect::protocol::plexus::NoiseEffector& p = static_cast<const effect::protocol::plexus::NoiseEffector&>(proto);
  _effector = ::FromProtocol(p);
  return true;
}

//----------------------------------------------------------------------------------
bool EffectRowNoise::ToProtocol(google::protobuf::Message* msg) const
{
  effect::protocol::plexus::Plexus* proto = static_cast<effect::protocol::plexus::Plexus*>(msg);

  ::ToProtocol(_effector, proto->add_noise_effectors());
  return true;
}
