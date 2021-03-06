#pragma once

#include "object_handle.hpp"

namespace boba
{
  template <typename T, size_t Size>
  class IdBuffer
  {
    typedef function<void(T)> Deleter;

    static_assert(sizeof(T) >= sizeof(u32), "sizeof(T) must be larger than sizeof(u32)");

  public:

    static const u32 INVALID_INDEX  = ~0;
    static const u32 FREE_MASK      = 0x3;

    //------------------------------------------------------------------------------
    IdBuffer(const Deleter& deleter)
      : _deleter(deleter)
      , _nextFree(0)
    {
      // Write free pointers into the elements
      for (size_t i = 0; i < Size; ++i)
      {
        u32* ptr = (u32*)&_elems[i];
        // Note, we set the lower 2 bits to indicate that the element is free
        *ptr = i != Size-1 ? (((i+1) << 2) | FREE_MASK) : INVALID_INDEX;
      }
    }

    //------------------------------------------------------------------------------
    ~IdBuffer()
    {
      for (size_t i = 0; i < Size; ++i)
      {
        if (!IsFree(i))
          _deleter(_elems[i]);
      }
    }

    //------------------------------------------------------------------------------
    T Get(ObjectHandle h)
    {
      return _elems[h.id()];
    }

    //------------------------------------------------------------------------------
    void Update(ObjectHandle h, T res)
    {
      _elems[h.id()] = res;
    }

    //------------------------------------------------------------------------------
    T Get(u32 idx)
    {
      return _elems[idx];
    }

    //------------------------------------------------------------------------------
    bool Get(const string& name, T* out)
    {
      auto it = _nameToIdx.find(name);
      if (it != _nameToIdx.end())
      {
        *out = _elems[it->second];
        return true;
      }
      *out = T();
      return false;
    }

    //------------------------------------------------------------------------------
    u32 Insert(const string& name, T res)
    {
      // insert element at next free pos, and update the freelist to point to the next element
      u32 tmp = _nextFree;

      // Update the next free index
      u32* ptr = (u32*)&_elems[_nextFree];
      _nextFree = (*ptr) >> 2;

      _elems[tmp] = res;
      _nameToIdx[name] = tmp;

      return tmp;
    }

    //------------------------------------------------------------------------------
    u32 Insert(T res)
    {
      return Insert("[[unnamed]]", res);
    }

    //------------------------------------------------------------------------------
    bool HasKey(const string& key)
    {
      return _nameToIdx.find(key) != _nameToIdx.end();
    }

    //------------------------------------------------------------------------------
    u32 IndexFromKey(const string& key)
    {
      auto it = _nameToIdx.find(key);
      return it == _nameToIdx.end() ? INVALID_INDEX : it->second;
    }

    //------------------------------------------------------------------------------
    u32 Find(const function<bool (const T&)>& fn)
    {
      for (size_t i = 0; i < Size; ++i)
      {
        if (!IsFree(i) && fn(_elems[i]))
          return i;
      }

      return INVALID_INDEX;
    }

  private:

    int IsFree(int idx) const
    {
      u32* ptr = (u32*)&_elems[idx];
      u32 val = *ptr;
      return val & FREE_MASK;
    }

    Deleter _deleter;
    u32 _nextFree;
    T _elems[Size];
    unordered_map<string, u32> _nameToIdx;
  };
}