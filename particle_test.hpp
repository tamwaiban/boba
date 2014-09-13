#pragma once

#include "effect.hpp"

#pragma warning(push)
#pragma warning(disable: 4244 4267)
#include "protocol/particle.pb.h"
#pragma warning(pop)

namespace boba
{
  class DeferredContext;

  class ParticleTest : public Effect
  {
  public:

    ParticleTest(const string &name, u32 id);
    ~ParticleTest();
    virtual bool Show();
    virtual bool Hide();
    virtual bool Init(const char* config) override;
    virtual bool Update(const UpdateState& state) override;
    virtual bool Render() override;
    virtual bool Close() override;

    virtual bool SaveSettings() override;

    static const char* Name();
    static Effect* Create(const char* name, u32 id);

  private:
    string _configName;
    particle::Config _config;
    ObjectHandle _texture;
    ObjectHandle _vs;
    ObjectHandle _ps;
    ObjectHandle _samplerState;
    ObjectHandle _cbuffer;
  };

}
