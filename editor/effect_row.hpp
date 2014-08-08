#pragma once

#include "protocol/effects_proto.hpp"

namespace editor
{
  struct StyledRectangle;

  struct EffectRow
  {
    enum class DisplayMode
    {
      Keyframe,
      Graph
    };

    struct RowFlagsF
    {
      enum Enum { Expanded = 1 << 0, Selected = 1 << 1 };
      struct Bits { u32 expanded : 1; u32 selected; };
    };

    typedef Flags<RowFlagsF> RowFlags;

    EffectRow(
        const Font& font,
        const string& str,
        EffectRow* parent = nullptr);

    void Draw(RenderTexture& texture);
    static void Flatten(EffectRow* cur, vector<EffectRow*>* res);
    static void Reposition(EffectRow* cur, float curY, float rowHeight);
    static float RowHeight(EffectRow* cur, float rowHeight);
    virtual void DrawVars(RenderTexture& texture, const Vector2f& size) {}
    virtual u32 NumVars() { return 0; }
    virtual void BeginEditVars(float x, float y) {}
    virtual void UpdateEditVar(Keyboard::Key key) {}
    virtual void EndEditVars(bool commit) {}

    virtual bool KeyframeIntersect(const Vector2f& pt, const Vector2f& size) { return false; }
    virtual void BeginKeyframeUpdate(bool copy) {}
    virtual void UpdateKeyframe(const time_duration& t) {}
    virtual void EndKeyframeUpdate(bool commit) {}
    virtual void DeselectKeyframe() {}
    virtual void DeleteKeyframe() {}

    virtual void ToggleDisplayMode() {}
    virtual void GraphMouseMove(const Event& event) {}

    DisplayMode CurrentDisplayMode() { return displayMode; }

    string str;
    RowFlags flags;
    EffectRow* parent;
    StyledRectangle* rect;
    vector<EffectRow*> children;
    Text text;
    int level;
    FloatRect expandRect;
    FloatRect varEditRect;
    StyledRectangle* keyframeRect;
    DisplayMode displayMode;
  };

  struct EffectRowNoise : public EffectRow
  {
    EffectRowNoise(
        const Font& font,
        const string& str,
        EffectRow* parent = nullptr);

    virtual void DrawVars(RenderTexture& texture, const Vector2f& size);
    virtual u32 NumVars();
    virtual void BeginEditVars(float x, float y);
    virtual void EndEditVars(bool commit);
    virtual void UpdateEditVar(Keyboard::Key key);

    virtual bool KeyframeIntersect(const Vector2f& pt, const Vector2f& size);
    virtual void BeginKeyframeUpdate(bool copy);
    virtual void UpdateKeyframe(const time_duration& t);
    virtual void EndKeyframeUpdate(bool commit);
    virtual void DeselectKeyframe();
    virtual void DeleteKeyframe();

    virtual void ToggleDisplayMode();
    virtual void GraphMouseMove(const Event& event);

    void DrawKeyframes(RenderTexture& texture, const Vector2f& size);
    void DrawGraph(RenderTexture& texture, const Vector2f& size);

    int editingIdx;

    NoiseEffector effector;
    Vector3f prevValue;
    string curEdit;
    Vector3Keyframe* selectedKeyframe;
    Vector3Keyframe oldKeyframe;
    bool copyingKeyframe;

    u32 graphMode;
  };

}