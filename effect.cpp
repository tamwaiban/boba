#include "effect.hpp"
#include "graphics.hpp"

using namespace boba;

//------------------------------------------------------------------------------
Effect::Effect(const string& name, GraphicsObjectHandle swapChain)
  : _name(name)
  , _swapChain(swapChain)
  , _running(false)
  , _mouse_horiz(0)
  , _mouse_vert(0)
  , _mouse_lbutton(false)
  , _mouse_rbutton(false)
  , _mouse_pos_prev(~0)
  , _ctx(GRAPHICS.CreateDeferredContext(false))
  , _first_tick(true)
{
  ZeroMemory(_keystate, sizeof(_keystate));
}

//------------------------------------------------------------------------------
Effect::~Effect()
{
  GRAPHICS.DestroyDeferredContext(_ctx);
}

//------------------------------------------------------------------------------
bool Effect::Init()
{
  return true;
}

//------------------------------------------------------------------------------
bool Effect::Reset()
{
  return true; 
}

//------------------------------------------------------------------------------
bool Effect::Update(const UpdateState& state)
{
  return true;
}

//------------------------------------------------------------------------------
bool Effect::Render()
{
  return true; 
}

//------------------------------------------------------------------------------
bool Effect::Close()
{
  return true; 
}

//------------------------------------------------------------------------------
void Effect::SetDuration(time_duration startTime, time_duration endTime)
{
  _startTime = startTime;
  _endTime = endTime;
}

//------------------------------------------------------------------------------
void Effect::SetStartTime(time_duration startTime)
{
  _startTime = startTime;
}

//------------------------------------------------------------------------------
void Effect::WndProc(UINT message, WPARAM wParam, LPARAM lParam)
{
  switch (message)
  {
    case WM_KEYDOWN:
      // ignore keyup/down if ctrl is pressed
      if (!(GetKeyState(VK_CONTROL) & (1 << 15)))
      {
        if (wParam <= 255)
          _keystate[wParam] = 1;
      }
      break;

    case WM_KEYUP:
      if (!(GetKeyState(VK_CONTROL) & (1 << 15)))
      {
        if (wParam <= 255)
          _keystate[wParam] = 0;
        switch (wParam) {
        case 'F':
          break;
        }
      }
      break;

    case WM_MOUSEMOVE:
      if (_mouse_pos_prev != ~0) {
        _mouse_horiz = LOWORD(lParam) - LOWORD(_mouse_pos_prev);
        _mouse_vert = HIWORD(lParam) - HIWORD(_mouse_pos_prev);
      }
      _mouse_pos_prev = lParam;
      break;

    case WM_LBUTTONDOWN:
      _mouse_lbutton = true;
      break;

    case WM_LBUTTONUP:
      _mouse_lbutton = false;
      break;

    case WM_RBUTTONDOWN:
      _mouse_rbutton = true;
      break;

    case WM_RBUTTONUP:
      _mouse_rbutton = false;
      break;
  }
}


//------------------------------------------------------------------------------
bool Effect::Running() const
{
  return _running; 
}

//------------------------------------------------------------------------------
void Effect::SetRunning(bool b)
{ 
  _running = b; 
}
