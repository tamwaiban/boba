#pragma once

namespace editor
{

  //----------------------------------------------------------------------------------
  class PropertyWindow : public VirtualWindow
  {
  public:
    PropertyWindow(
        const string& title,
        const Vector2f& pos,
        const Vector2f& size);
  };

  //----------------------------------------------------------------------------------
  class PreviewWindow : public VirtualWindow
  {
  public:
    PreviewWindow(
        const string& title,
        const Vector2f& pos,
        const Vector2f& size);
  };

  //----------------------------------------------------------------------------------
  class TimelineWindow : public VirtualWindow
  {
  public:
    TimelineWindow(
        const string& title,
        const Vector2f& pos,
        const Vector2f& size);

    virtual bool Init();
    virtual void Draw();

    int TimeToPixel(const time_duration& t);
    time_duration PixelToTime(int x);

  private:

    void DrawComponents();
    void DrawTimeline();

    struct ModuleFlagsF
    {
      enum Enum { Selected = 1 << 0, Dragging = 1 << 1, InvalidDrop = 1 << 2, };
      struct Bits { u32 selected : 1; u32 dragging : 1; u32 invalidDrop : 1; };
    };

    typedef Flags<ModuleFlagsF> ModuleFlags;

    struct Module
    {
      u32 id;
      string name;
      IntRect rect;
      ModuleFlags flags;
    };

    struct RowFlagsF
    {
      enum Enum { Expanded = 1 << 0 };
      struct Bits { u32 expanded : 1; };
    };

    typedef Flags<RowFlagsF> RowFlags;

    struct EffectInstance
    {
      time_duration startTime;
      time_duration endTime;
      Module* module;
    };

    struct Row
    {
      // given the start/end, determines an end value
      // that doesn't overlap with any existing effect
      time_duration AvailableSlot(const time_duration& start, const time_duration& end);
      void AddEffect(const EffectInstance& effect);
      u32 id;
      IntRect rect;
      RowFlags flags;
      vector<EffectInstance> effects;
    };

    struct DraggingModule
    {
      DraggingModule() { Reset(); }
      void Reset() { module = nullptr; dragStart = not_a_date_time; dragEnd = not_a_date_time; }
      Module* module;
      Vector2i dragPos;
      time_duration dragStart;
      time_duration dragEnd;
    };

    struct TimelineFlagsF
    {
      enum Enum { PendingDrag = 1 << 0, };
      struct Bits { u32 pendingDraw : 1; };
    };

    typedef Flags<TimelineFlagsF> TimelineFlags;


    bool OnMouseButtonPressed(const Event& event);
    bool OnMouseMoved(const Event& event);
    bool OnMouseButtonReleased(const Event& event);

    void DrawModule(float x, float y, const Module& m);
    void DrawModule(const IntRect& rect, const string& name, ModuleFlags flags);

    void ResetDragDrop();

    template<typename T>
    sf::Vector2<T> PointToLocal(int x, int y)
    {
      return sf::Vector2<T>((T)(x - _pos.x), (T)(y - _pos.y));
    }

    time_duration _panelOffset;
    u32 _pixelsPerSecond;
    Font _font;
    vector<Module> _modules;
    vector<Row> _rows;

    TimelineFlags _timelineFlags;

    DraggingModule _draggingModule;
    Module* _selectedModule;
    Row* _hoverRow;
  };


}