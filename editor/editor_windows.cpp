#include "editor_windows.hpp"
#include "editor.hpp"

#include "protocol/effects_proto.hpp"
#include "effect_row.hpp"

using namespace editor;
using namespace bristol;

#pragma warning(disable: 4244)



//----------------------------------------------------------------------------------
PropertyWindow::PropertyWindow(
  const string& title,
  const Vector2f& pos,
  const Vector2f& size)
    : VirtualWindow(title, pos, size, bristol::WindowFlags(bristol::WindowFlag::StaticWindow))
{
}

//----------------------------------------------------------------------------------
PreviewWindow::PreviewWindow(
  const string& title,
  const Vector2f& pos,
  const Vector2f& size)
    : VirtualWindow(title, pos, size, bristol::WindowFlags(bristol::WindowFlag::StaticWindow))
{
}

TimelineWindow* TimelineWindow::_instance;

//----------------------------------------------------------------------------------
TimelineWindow::TimelineWindow(
  const string& title,
  const Vector2f& pos,
  const Vector2f& size)
    : VirtualWindow(title, pos, size, bristol::WindowFlags(bristol::WindowFlag::StaticWindow))
    , _panelOffset(seconds(0))
    , _pixelsPerSecond(EDITOR.Settings().timeline_zoom_default())
    , _curRow(nullptr)
    , _lastDragPos(-1, -1)
//    , _editRow(nullptr)
    , _tickerRect(nullptr)
    , _statusBar(nullptr)
//    , _movingKeyframe(nullptr)
//    , _selectedRow(nullptr)
    , _displayMode(DisplayMode::Keyframe)
    , _selectedVar(nullptr)
{
  _instance = this;
}

//----------------------------------------------------------------------------------
TimelineWindow::~TimelineWindow()
{
}

//----------------------------------------------------------------------------------
bool TimelineWindow::Init()
{
  if (!VirtualWindow::Init())
    return false;

  _windowManager->RegisterHandler(Event::MouseButtonPressed, nullptr, bind(&TimelineWindow::OnMouseButtonPressed, this, _1));
  _windowManager->RegisterHandler(Event::MouseMoved, nullptr, bind(&TimelineWindow::OnMouseMoved, this, _1));
  _windowManager->RegisterHandler(Event::MouseButtonReleased, nullptr, bind(&TimelineWindow::OnMouseButtonReleased, this, _1));
  _windowManager->RegisterHandler(Event::MouseWheelMoved, nullptr, bind(&TimelineWindow::OnMouseWheelMoved, this, _1));
  _windowManager->RegisterHandler(Event::KeyReleased, nullptr, bind(&TimelineWindow::OnKeyReleased, this, _1));

  if (!_font.loadFromFile(EDITOR.GetAppRoot() + "gfx/coders_crux.ttf"))
    return false;

  const editor::protocol::Settings& settings = EDITOR.Settings();
  int width = settings.effect_view_width();

  const Vector2f& windowSize = GetSize();

  _tickerRect._style = STYLE_FACTORY.CreateStyle("default_row_color");
  _tickerRect._rect.setPosition(width, 0);
  _tickerRect._rect.setSize(Vector2f(_size.x - width, settings.ticker_height()));

  _statusBar = STYLE_FACTORY.CreateStyle("status_bar_style");
  _statusBar._rect.setPosition(0, windowSize.y - settings.status_bar_height());
  _statusBar._rect.setSize(Vector2f(windowSize.x, settings.status_bar_height()));

  // add temporary effect rows until we get the websocket update
  string str;
  for (int i = 0; i < 5; ++i)
  {
    EffectRow* parent = new EffectRowPlexus(_font, "PLEXUS");
    _effectRows.push_back(parent);

    str = to_string("TextPath: %s", "test");
    parent->_children.push_back(new EffectRowTextPath(_font, str, parent));

    NoiseEffector e;
    e.applyTo = NoiseEffector::ApplyTo::Position;

    str = to_string("Noise (%s)", e.applyTo == NoiseEffector::ApplyTo::Position ? "POS" : "SCALE");
    EffectRowNoise* n = new EffectRowNoise(_font, str, parent);
    e.displacement.x.type = 1;
    e.displacement.y.type = 1;
    e.displacement.z.type = 1;
    s32 t = randf(0.f, 500.f);
    for (u32 j = 0; j < 50; ++j)
    {
      e.displacement.x.keyframe.push_back({ t, randf(-10.f, 20.f) });
      t += randf(150.f, 1000.f);
      e.displacement.y.keyframe.push_back({ t, randf(-10.f, 20.f) });
      t += randf(150.f, 1000.f);
      e.displacement.z.keyframe.push_back({ t, randf(-10.f, 20.f) });
      t += randf(150.f, 1000.f);

      float d;
      s32 t;

      float s = 250;
      if (j == 0)
      {
        d = e.displacement.x.keyframe[1].value - e.displacement.x.keyframe[0].value;
        t = e.displacement.x.keyframe[1].time - e.displacement.x.keyframe[0].time;
        float len = sqrtf(d*d+t*t) / s;

        e.displacement.x.keyframe.back().cpOutValue = e.displacement.x.keyframe[0].value + d / len;
        e.displacement.x.keyframe.back().cpOutTime = e.displacement.x.keyframe[0].time + t / len;


      }
      else if (j == 48)
      {

      }
      else
      {
        d = e.displacement.x.keyframe[j+1].value - e.displacement.x.keyframe[j-1].value;
        t = e.displacement.x.keyframe[j+1].time - e.displacement.x.keyframe[j-1].time;
        float len = sqrtf(d*d+t*t) / s;

        e.displacement.x.keyframe.back().cpInValue = e.displacement.x.keyframe[j].value - d / len;
        e.displacement.x.keyframe.back().cpInTime = e.displacement.x.keyframe[j].time - t / len;
        e.displacement.x.keyframe.back().cpOutValue = e.displacement.x.keyframe[j].value + d / len;
        e.displacement.x.keyframe.back().cpOutTime = e.displacement.x.keyframe[j].time + t / len;
      }
    }
    n->_effector = e;
    parent->_children.push_back(n);
  }

  RecalcEffecRows();

  return true;
}

//----------------------------------------------------------------------------------
void TimelineWindow::RecalcEffecRows()
{
  const editor::protocol::Settings& settings = EDITOR.Settings();
  float rowHeight = settings.effect_row_height();

  float curY = settings.ticker_height();

  for (EffectRow* row : _effectRows)
  {
    row->Reposition(curY, rowHeight);
    curY += row->RowHeight(rowHeight);
  }
}

//----------------------------------------------------------------------------------
bool TimelineWindow::OnKeyReleased(const Event &event)
{
  if (_curRow)
  {
    if (_curRow->OnKeyReleased(event))
      return true;
  }

  // The current row didn't handle the key..
  Keyboard::Key code = event.key.code;

  if (code == Keyboard::U)
  {
    _displayMode = NextEnum(_displayMode);
  }
  else if (code == Keyboard::R)
  {
    _displayMode = DisplayMode::Keyframe;
  }



//  Keyboard::Key code = event.key.code;
//
//  // escape aborts the pending operation
//  if (code == Keyboard::Escape)
//  {
//    if (_editRow)
//    {
//      _editRow->EndEditVars(false);
//    }
//    else if (_movingKeyframe)
//    {
//      _movingKeyframe->EndKeyframeUpdate(false);
//    }
//
//    _selectedRow = nullptr;
//    _movingKeyframe = nullptr;
//  }
//  else
//  {
//    if (_editRow)
//    {
//      if (code == Keyboard::Return)
//      {
//        _editRow->EndEditVars(true);
//        _editRow = nullptr;
//      }
//      else
//      {
//        _editRow->UpdateEditVar(event.key.code);
//      }
//    }
//    else
//    {
//      if (code == Keyboard::U && !_selectedRows.IsEmpty())
//      {
//        _displayMode = _selectedRows.Next() ? DisplayMode::Graph : DisplayMode::Keyframe;
//      }
//      else if (code == Keyboard::R)
//      {
//        _displayMode = DisplayMode::Keyframe;
//        for (EffectRow* r : _selectedRows.backingSet)
//        {
//          r->ToggleGraphView(false);
//        }
//      }
//    }
//  }

  return true;
}

//----------------------------------------------------------------------------------
bool TimelineWindow::OnMouseButtonPressed(const Event& event)
{
  const editor::protocol::Settings& settings = EDITOR.Settings();

  int x = (int)(event.mouseButton.x - _pos.x);
  int y = (int)(event.mouseButton.y - _pos.y);

  // check for a click in the ticker
  if (y < (int)settings.ticker_height())
  {
    time_duration t = PixelToTime(event.mouseButton.x - (int)_pos.x);
    if (!t.is_not_a_date_time())
    {
      EDITOR.SetCurTime(t);
    }
    return true;
  }

  vector<EffectRow*> effects;
  for (EffectRow* row : _effectRows)
    row->Flatten(&effects);

  // check for hits on an effect row
  for (EffectRow* row : effects)
  {
    if (row->OnMouseButtonPressed(event))
    {
      RecalcEffecRows();
      return true;
    }
  }

//  if (x < (int)settings.effect_view_width())
//  {
//    // Check for hits in the effect view
//    EffectRow* rowHit = nullptr;
//    for (EffectRow* row : effects)
//    {
//      if (row->_expandRect.contains(mousePos))
//      {
//        row->_flags.Toggle(EffectRow::RowFlagsF::Expanded);
//        rowHit = row;
//        break;
//      }
//      else if (row->_varEditRect.contains(mousePos))
//      {
//        row->BeginEditVars(x, y);
//        rowHit = row;
//        _editRow = row;
//        break;
//      }
//      else if (row->_rect->_shape.getGlobalBounds().contains(mousePos))
//      {
//        _selectedRows.Toggle(row);
//        row->_flags.Toggle(EffectRow::RowFlagsF::Selected);
//        rowHit = row;
//        break;
//      }
//    }

//    if (rowHit)
//    {
//      // if a new row is hit, end any current editing
//      if (_editRow && rowHit != _editRow)
//      {
//        _editRow->EndEditVars(true);
//      }
//
//      RecalcEffecRows();
//    }
//    else
//    {
//      _editRow = nullptr;
//    }
//  }
//  else
//  {
//    if (_displayMode == DisplayMode::Graph)
//    {
//      _selectedRows.CurRow()->OnMouseButtonPressed(event);
//    }
//    else
//    {
////      int a = 10;
//    }
//
//    if (_selectedRow)
//    {
//      _selectedRow->DeselectKeyframe();
//      _selectedRow = nullptr;
//    }
//
//    for (EffectRow* row : effects)
//    {
//      if (row->KeyframeIntersect(mousePos, _size))
//      {
//        _selectedRow = row;
//        break;
//      }
//    }
//
//  }
  return false;
}

//----------------------------------------------------------------------------------
bool TimelineWindow::OnMouseMoved(const Event& event)
{
//  Vector2i posModule = PointToLocal<int>(event.mouseMove.x, event.mouseMove.y);

  // Check if the timeline is being dragged
  if (sf::Mouse::isButtonPressed(sf::Mouse::Middle))
  {
    if (_lastDragPos.x == -1)
    {
      _lastDragPos = Vector2i(event.mouseMove.x, event.mouseMove.y);
      return true;
    }
    int delta = event.mouseMove.x - _lastDragPos.x;
    time_duration d = AbsPixelToTime(delta);
    if (_panelOffset + d < seconds(0))
      _panelOffset = seconds(0);
    else 
    _panelOffset += AbsPixelToTime(delta);

    _lastDragPos = Vector2i(event.mouseMove.x, event.mouseMove.y);
    return true;
  }

  vector<EffectRow*> effects;
  for (EffectRow* row : _effectRows)
    row->Flatten(&effects);

  for (EffectRow* row : effects)
  {
    if (row->OnMouseMoved(event))
    {
      return true;
    }
  }


  if (_curRow && _curRow->OnMouseMoved(event))
    return true;

//  if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//  {
//
//    if (_displayMode == DisplayMode::Keyframe && _selectedRow)
//    {
//      if (!_movingKeyframe)
//      {
//        // send the BeginKeyframeUpdate, and check if we're copying or moving
//        _selectedRow->BeginKeyframeUpdate(Keyboard::isKeyPressed(Keyboard::Key::LShift));
//        _movingKeyframe = _selectedRow;
//      }
//
//      _movingKeyframe->UpdateKeyframe(curTime);
//    }
//    else if (_displayMode == DisplayMode::Graph && _selectedRows.CurRow())
//    {
//      _selectedRows.CurRow()->OnMouseMoved(event);
//    }
//  }

  return false;
}

//----------------------------------------------------------------------------------
bool TimelineWindow::OnMouseButtonReleased(const Event& event)
{
  vector<EffectRow*> effects;
  for (EffectRow* row : _effectRows)
    row->Flatten(&effects);

  // check for hits on an effect row
  for (EffectRow* row : effects)
  {
    if (row->OnMouseButtonReleased(event))
    {
      RecalcEffecRows();
      return true;
    }
  }

//  if (_displayMode == DisplayMode::Graph)
//  {
//    if (_selectedRows.CurRow())
//      return _selectedRows.CurRow()->OnMouseButtonReleased(event);
//  }
//  else
//  {
//    if (_movingKeyframe)
//    {
//      _movingKeyframe->EndKeyframeUpdate(true);
//      _movingKeyframe = nullptr;
//    }
//    return true;
//  }
  return false;
}

//----------------------------------------------------------------------------------
bool TimelineWindow::OnMouseWheelMoved(const Event& event)
{
  const editor::protocol::Settings& settings = EDITOR.Settings();

  if (event.mouseWheel.delta < 0)
    _pixelsPerSecond *= 2;
  else if (event.mouseWheel.delta > 0)
    _pixelsPerSecond /= 2;

  _pixelsPerSecond = Clamp(settings.timeline_zoom_min(), settings.timeline_zoom_max(), _pixelsPerSecond);

  return true;
}

//----------------------------------------------------------------------------------
void TimelineWindow::DrawTimeline()
{
  const editor::protocol::Settings& settings = EDITOR.Settings();

  time_duration curTime = EDITOR.CurTime();

  // draw the ticker
  _texture.draw(_tickerRect._rect);

  VertexArray lines(sf::Lines);
  int x = settings.effect_view_width();
  int y = settings.ticker_height() - 25;
  int minorInc = settings.ticker_interval() / settings.ticks_per_interval();
  Text text;
  text.setFont(_font);
  text.setCharacterSize(16);

  // calc rounded starting time
  while (x < _size.x)
  {
    time_duration t = PixelToTime(x);

    // round to nearest 0.250s
    int ms = t.total_milliseconds() / 250 * 250;
    t = milliseconds(ms);
    int tmpX = x;
    x = TimeToPixel(t);

    text.setString(to_string("%.2f", t.total_milliseconds() / 1000.0f));
    text.setPosition(x, y-20);
    _texture.draw(text);

    lines.append(sf::Vertex(Vector2f(x, y + 0)));
    lines.append(sf::Vertex(Vector2f(x, y + 20)));
    for (int i = 0; i < (int)settings.ticks_per_interval(); ++i)
    {
      lines.append(sf::Vertex(Vector2f(x + i * minorInc, y + 5)));
      lines.append(sf::Vertex(Vector2f(x + i * minorInc, y + 15)));
    }
    x = tmpX + settings.ticker_interval();
  }
  _texture.draw(lines);

  // draw time line
  VertexArray curLine(sf::Lines);
  int w = _size.x;
  y = settings.ticker_height() - 25;
  while (TimeToPixel(curTime - _panelOffset) > w)
  {
    _panelOffset += PixelToTime(w);
  }

  x = settings.effect_view_width();
  curLine.append(sf::Vertex(Vector2f(x, y), Color::White));
  curLine.append(sf::Vertex(Vector2f(x, _size.y), Color::White));

  x = TimeToPixel(EDITOR.CurTime());
  curLine.append(sf::Vertex(Vector2f(x, y), Color::Red));
  curLine.append(sf::Vertex(Vector2f(x, _size.y), Color::Red));
  _texture.draw(curLine);
}

//----------------------------------------------------------------------------------
void TimelineWindow::DrawEffects()
{
  // draw the header
  time_duration t = EDITOR.CurTime();
  Text text(to_string("TIME: %.3f, OFS: %.3f, SCALE: %.3f",
    t.total_milliseconds() / 1000.0f,
    _panelOffset.total_milliseconds() / 1000.0f,
    _pixelsPerSecond / 100.0f), _font);
  text.setPosition(10, 0);
  text.setCharacterSize(14);
  _texture.draw(text);

  for (EffectRow* row : _effectRows)
  {
    row->Draw(_texture, _displayMode == DisplayMode::Keyframe);
  }

  if (_displayMode == DisplayMode::Graph && _selectedVar)
  {
    _selectedVar->DrawGraph(_texture);
  }
}

//----------------------------------------------------------------------------------
void TimelineWindow::DrawStatusBar()
{
  const editor::protocol::Settings& settings = EDITOR.Settings();

  // draw the background
  _texture.draw(_statusBar._rect);

  Text t;
  t.setFont(_font);
  t.setCharacterSize(16);

  // draw the status texts
  float x = 10;
  float y = GetPosition().y - settings.status_bar_height();
  for (const string& str : _statusBarValues)
  {
    t.setPosition(x, y);
    t.setString(str);
    _texture.draw(t);
  }

}

//----------------------------------------------------------------------------------
int TimelineWindow::TimeToPixel(const time_duration& t) const
{
  int w = EDITOR.Settings().effect_view_width();

  // p = s * (t + a) + m
  // t = (p - m) / s - a
  double s = (double)_pixelsPerSecond / 1000.0;
  return (int)(w + s * (t.total_milliseconds() - _panelOffset.total_milliseconds()));
}

//----------------------------------------------------------------------------------
time_duration TimelineWindow::PixelToTime(int x) const
{
  double s = (double)_pixelsPerSecond / 1000.0;

  x -= EDITOR.Settings().effect_view_width();
  if (x < 0)
    return milliseconds(0);

  return milliseconds(x / s) + _panelOffset;
}

//----------------------------------------------------------------------------------
time_duration TimelineWindow::AbsPixelToTime(int x) const
{
  return milliseconds(1000 * x / (int)_pixelsPerSecond);
}

//----------------------------------------------------------------------------------
void TimelineWindow::DrawBackground()
{
  const editor::protocol::Settings& settings = EDITOR.Settings();
  float w = settings.effect_view_width();

  RectangleShape s;
  s.setPosition(0, 0);
  s.setSize(Vector2f(w, _size.y));
  s.setFillColor(::FromProtocol(settings.effect_view_background_color()));
  _texture.draw(s);

  s.setPosition(w, 0);
  s.setSize(Vector2f(_size.x - w, _size.y));
  s.setFillColor(::FromProtocol(settings.timeline_view_background_color()));
  _texture.draw(s);
}

//----------------------------------------------------------------------------------
void TimelineWindow::Draw()
{
  _texture.clear();

  DrawBackground();
  DrawEffects();
  DrawTimeline();
  DrawStatusBar();

  _texture.display();
}

//----------------------------------------------------------------------------------
void TimelineWindow::UpdateStatusBar(int segment, const string& value)
{
  if (segment >= _statusBarValues.size())
    _statusBarValues.resize(segment + 1);

  _statusBarValues[segment] = value;
}

//----------------------------------------------------------------------------------
void TimelineWindow::KeyframesModified()
{
  effect::protocol::EffectSettings settings;
  for (const EffectRow* row : _effectRows)
  {
    effect::protocol::EffectSetting* setting = settings.add_effect_setting();
    setting->set_id(row->_id);
    row->ToProtocol(setting);
  }

  EDITOR.SettingsUpdated(settings);
}

//----------------------------------------------------------------------------------
void TimelineWindow::Reset(const effect::protocol::EffectSettings& settings)
{
  for (EffectRow* e : _effectRows)
    delete e;
  _effectRows.clear();

  for (const effect::protocol::EffectSetting& setting : settings.effect_setting())
  {
    switch (setting.type())
    {
      case 0:
        break;

      case 1:
        effect::protocol::plexus::Plexus p;
        const string& str = setting.config_msg();
        p.ParseFromArray(str.data(), (int)str.size());

        EffectRow* parent = new EffectRowPlexus(_font, "PLEXUS");
        parent->_id = setting.id();
        _effectRows.push_back(parent);
        parent->FromProtocol(p);

        break;
    }
  }

  RecalcEffecRows();
}

//----------------------------------------------------------------------------------
void TimelineWindow::SendEffectEvent(RowVar* sender, const EffectRowEvent& event)
{
  if (event.type == EffectRowEvent::Type::VarSelected)
    _selectedVar = sender;

  for (EffectRow* e : _effectRows)
    e->SendEvent(sender, event);
}
