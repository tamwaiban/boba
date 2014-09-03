#pragma once
#include "imgui.hpp"

namespace editor
{
  struct RowVar;
  struct EffectRowEvent;
  struct FloatAnim;
  struct FloatKeyframe;

  //----------------------------------------------------------------------------------
  class PropertyWindow : public VirtualWindow
  {
  public:
    PropertyWindow(
        const string& title,
        const Vector2f& pos,
        const Vector2f& size);

    virtual bool Init();
    virtual void Draw();
    virtual void Update();

    void SendEffectEvent(RowVar* sender, const EffectRowEvent& event);

    bool OnMouseButtonPressed(const Event& event);
    bool OnMouseMoved(const Event& event);
    bool OnMouseButtonReleased(const Event& event);
    bool OnKeyReleased(const Event& event);
    bool OnTextEntered(const Event& event);

    string _varTime;
    string _varValue;
    RowVar* _var;
    FloatAnim* _anim;
    FloatKeyframe* _keyframe;

    ImGui _gui;

    bool _keyboardFocus = false;
  };

}