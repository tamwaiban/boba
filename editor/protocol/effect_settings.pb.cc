// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: effect_settings.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "effect_settings.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace protocol {
namespace effect {

namespace {

const ::google::protobuf::Descriptor* EffectSetting_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  EffectSetting_reflection_ = NULL;
struct EffectSettingOneofInstance {
  const ::protocol::effect::plexus::PlexusConfig* plexus_config_;
  const ::protocol::effect::generator::PlaneConfig* generator_plane_config_;
  const ::protocol::effect::generator::SpikyConfig* generator_spiky_config_;
  const ::protocol::effect::particle::ParticleConfig* particle_config_;
}* EffectSetting_default_oneof_instance_ = NULL;
const ::google::protobuf::EnumDescriptor* EffectSetting_Type_descriptor_ = NULL;
const ::google::protobuf::Descriptor* EffectSettings_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  EffectSettings_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_effect_5fsettings_2eproto() {
  protobuf_AddDesc_effect_5fsettings_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "effect_settings.proto");
  GOOGLE_CHECK(file != NULL);
  EffectSetting_descriptor_ = file->message_type(0);
  static const int EffectSetting_offsets_[10] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EffectSetting, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EffectSetting, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EffectSetting, name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EffectSetting, start_time_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EffectSetting, end_time_),
    PROTO2_GENERATED_DEFAULT_ONEOF_FIELD_OFFSET(EffectSetting_default_oneof_instance_, plexus_config_),
    PROTO2_GENERATED_DEFAULT_ONEOF_FIELD_OFFSET(EffectSetting_default_oneof_instance_, generator_plane_config_),
    PROTO2_GENERATED_DEFAULT_ONEOF_FIELD_OFFSET(EffectSetting_default_oneof_instance_, generator_spiky_config_),
    PROTO2_GENERATED_DEFAULT_ONEOF_FIELD_OFFSET(EffectSetting_default_oneof_instance_, particle_config_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EffectSetting, config_),
  };
  EffectSetting_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      EffectSetting_descriptor_,
      EffectSetting::default_instance_,
      EffectSetting_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EffectSetting, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EffectSetting, _unknown_fields_),
      -1,
      EffectSetting_default_oneof_instance_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EffectSetting, _oneof_case_[0]),
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(EffectSetting));
  EffectSetting_Type_descriptor_ = EffectSetting_descriptor_->enum_type(0);
  EffectSettings_descriptor_ = file->message_type(1);
  static const int EffectSettings_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EffectSettings, effect_setting_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EffectSettings, soundtrack_),
  };
  EffectSettings_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      EffectSettings_descriptor_,
      EffectSettings::default_instance_,
      EffectSettings_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EffectSettings, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EffectSettings, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(EffectSettings));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_effect_5fsettings_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    EffectSetting_descriptor_, &EffectSetting::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    EffectSettings_descriptor_, &EffectSettings::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_effect_5fsettings_2eproto() {
  delete EffectSetting::default_instance_;
  delete EffectSetting_default_oneof_instance_;
  delete EffectSetting_reflection_;
  delete EffectSettings::default_instance_;
  delete EffectSettings_reflection_;
}

void protobuf_AddDesc_effect_5fsettings_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::protocol::effect::plexus::protobuf_AddDesc_effect_5fsettings_5fplexus_2eproto();
  ::protocol::effect::generator::protobuf_AddDesc_effect_5fsettings_5fgenerator_2eproto();
  ::protocol::effect::particle::protobuf_AddDesc_effect_5fsettings_5fparticle_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\025effect_settings.proto\022\017protocol.effect"
    "\032\034effect_settings_plexus.proto\032\037effect_s"
    "ettings_generator.proto\032\036effect_settings"
    "_particle.proto\"\342\003\n\rEffectSetting\0221\n\004typ"
    "e\030\001 \001(\0162#.protocol.effect.EffectSetting."
    "Type\022\n\n\002id\030\003 \001(\r\022\014\n\004name\030\004 \001(\t\022\022\n\nstart_"
    "time\030\005 \001(\r\022\020\n\010end_time\030\006 \001(\r\022=\n\rplexus_c"
    "onfig\030d \001(\0132$.protocol.effect.plexus.Ple"
    "xusConfigH\000\022H\n\026generator_plane_config\030e "
    "\001(\0132&.protocol.effect.generator.PlaneCon"
    "figH\000\022H\n\026generator_spiky_config\030f \001(\0132&."
    "protocol.effect.generator.SpikyConfigH\000\022"
    "C\n\017particle_config\030g \001(\0132(.protocol.effe"
    "ct.particle.ParticleConfigH\000\"<\n\004Type\022\013\n\007"
    "Unknown\020\000\022\n\n\006Plexus\020\001\022\014\n\010Particle\020\002\022\r\n\tG"
    "enerator\020\003B\010\n\006config\"\\\n\016EffectSettings\0226"
    "\n\016effect_setting\030\001 \003(\0132\036.protocol.effect"
    ".EffectSetting\022\022\n\nsoundtrack\030\002 \001(\t", 714);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "effect_settings.proto", &protobuf_RegisterTypes);
  EffectSetting::default_instance_ = new EffectSetting();
  EffectSetting_default_oneof_instance_ = new EffectSettingOneofInstance;
  EffectSettings::default_instance_ = new EffectSettings();
  EffectSetting::default_instance_->InitAsDefaultInstance();
  EffectSettings::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_effect_5fsettings_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_effect_5fsettings_2eproto {
  StaticDescriptorInitializer_effect_5fsettings_2eproto() {
    protobuf_AddDesc_effect_5fsettings_2eproto();
  }
} static_descriptor_initializer_effect_5fsettings_2eproto_;

// ===================================================================

const ::google::protobuf::EnumDescriptor* EffectSetting_Type_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return EffectSetting_Type_descriptor_;
}
bool EffectSetting_Type_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const EffectSetting_Type EffectSetting::Unknown;
const EffectSetting_Type EffectSetting::Plexus;
const EffectSetting_Type EffectSetting::Particle;
const EffectSetting_Type EffectSetting::Generator;
const EffectSetting_Type EffectSetting::Type_MIN;
const EffectSetting_Type EffectSetting::Type_MAX;
const int EffectSetting::Type_ARRAYSIZE;
#endif  // _MSC_VER
#ifndef _MSC_VER
const int EffectSetting::kTypeFieldNumber;
const int EffectSetting::kIdFieldNumber;
const int EffectSetting::kNameFieldNumber;
const int EffectSetting::kStartTimeFieldNumber;
const int EffectSetting::kEndTimeFieldNumber;
const int EffectSetting::kPlexusConfigFieldNumber;
const int EffectSetting::kGeneratorPlaneConfigFieldNumber;
const int EffectSetting::kGeneratorSpikyConfigFieldNumber;
const int EffectSetting::kParticleConfigFieldNumber;
#endif  // !_MSC_VER

EffectSetting::EffectSetting()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:protocol.effect.EffectSetting)
}

void EffectSetting::InitAsDefaultInstance() {
  EffectSetting_default_oneof_instance_->plexus_config_ = const_cast< ::protocol::effect::plexus::PlexusConfig*>(&::protocol::effect::plexus::PlexusConfig::default_instance());
  EffectSetting_default_oneof_instance_->generator_plane_config_ = const_cast< ::protocol::effect::generator::PlaneConfig*>(&::protocol::effect::generator::PlaneConfig::default_instance());
  EffectSetting_default_oneof_instance_->generator_spiky_config_ = const_cast< ::protocol::effect::generator::SpikyConfig*>(&::protocol::effect::generator::SpikyConfig::default_instance());
  EffectSetting_default_oneof_instance_->particle_config_ = const_cast< ::protocol::effect::particle::ParticleConfig*>(&::protocol::effect::particle::ParticleConfig::default_instance());
}

EffectSetting::EffectSetting(const EffectSetting& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:protocol.effect.EffectSetting)
}

void EffectSetting::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  type_ = 0;
  id_ = 0u;
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  start_time_ = 0u;
  end_time_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  clear_has_config();
}

EffectSetting::~EffectSetting() {
  // @@protoc_insertion_point(destructor:protocol.effect.EffectSetting)
  SharedDtor();
}

void EffectSetting::SharedDtor() {
  if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete name_;
  }
  if (has_config()) {
    clear_config();
  }
  if (this != default_instance_) {
  }
}

void EffectSetting::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* EffectSetting::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return EffectSetting_descriptor_;
}

const EffectSetting& EffectSetting::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_effect_5fsettings_2eproto();
  return *default_instance_;
}

EffectSetting* EffectSetting::default_instance_ = NULL;

EffectSetting* EffectSetting::New() const {
  return new EffectSetting;
}

void EffectSetting::clear_config() {
  switch(config_case()) {
    case kPlexusConfig: {
      delete config_.plexus_config_;
      break;
    }
    case kGeneratorPlaneConfig: {
      delete config_.generator_plane_config_;
      break;
    }
    case kGeneratorSpikyConfig: {
      delete config_.generator_spiky_config_;
      break;
    }
    case kParticleConfig: {
      delete config_.particle_config_;
      break;
    }
    case CONFIG_NOT_SET: {
      break;
    }
  }
  _oneof_case_[0] = CONFIG_NOT_SET;
}


void EffectSetting::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<EffectSetting*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 31) {
    ZR_(type_, id_);
    ZR_(start_time_, end_time_);
    if (has_name()) {
      if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        name_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  clear_config();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool EffectSetting::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:protocol.effect.EffectSetting)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(16383);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .protocol.effect.EffectSetting.Type type = 1;
      case 1: {
        if (tag == 8) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::protocol::effect::EffectSetting_Type_IsValid(value)) {
            set_type(static_cast< ::protocol::effect::EffectSetting_Type >(value));
          } else {
            mutable_unknown_fields()->AddVarint(1, value);
          }
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_id;
        break;
      }

      // optional uint32 id = 3;
      case 3: {
        if (tag == 24) {
         parse_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_name;
        break;
      }

      // optional string name = 4;
      case 4: {
        if (tag == 34) {
         parse_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->name().data(), this->name().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "name");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_start_time;
        break;
      }

      // optional uint32 start_time = 5;
      case 5: {
        if (tag == 40) {
         parse_start_time:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &start_time_)));
          set_has_start_time();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_end_time;
        break;
      }

      // optional uint32 end_time = 6;
      case 6: {
        if (tag == 48) {
         parse_end_time:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &end_time_)));
          set_has_end_time();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(802)) goto parse_plexus_config;
        break;
      }

      // optional .protocol.effect.plexus.PlexusConfig plexus_config = 100;
      case 100: {
        if (tag == 802) {
         parse_plexus_config:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_plexus_config()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(810)) goto parse_generator_plane_config;
        break;
      }

      // optional .protocol.effect.generator.PlaneConfig generator_plane_config = 101;
      case 101: {
        if (tag == 810) {
         parse_generator_plane_config:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_generator_plane_config()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(818)) goto parse_generator_spiky_config;
        break;
      }

      // optional .protocol.effect.generator.SpikyConfig generator_spiky_config = 102;
      case 102: {
        if (tag == 818) {
         parse_generator_spiky_config:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_generator_spiky_config()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(826)) goto parse_particle_config;
        break;
      }

      // optional .protocol.effect.particle.ParticleConfig particle_config = 103;
      case 103: {
        if (tag == 826) {
         parse_particle_config:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_particle_config()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:protocol.effect.EffectSetting)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:protocol.effect.EffectSetting)
  return false;
#undef DO_
}

void EffectSetting::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:protocol.effect.EffectSetting)
  // optional .protocol.effect.EffectSetting.Type type = 1;
  if (has_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->type(), output);
  }

  // optional uint32 id = 3;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->id(), output);
  }

  // optional string name = 4;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->name(), output);
  }

  // optional uint32 start_time = 5;
  if (has_start_time()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(5, this->start_time(), output);
  }

  // optional uint32 end_time = 6;
  if (has_end_time()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(6, this->end_time(), output);
  }

  // optional .protocol.effect.plexus.PlexusConfig plexus_config = 100;
  if (has_plexus_config()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      100, this->plexus_config(), output);
  }

  // optional .protocol.effect.generator.PlaneConfig generator_plane_config = 101;
  if (has_generator_plane_config()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      101, this->generator_plane_config(), output);
  }

  // optional .protocol.effect.generator.SpikyConfig generator_spiky_config = 102;
  if (has_generator_spiky_config()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      102, this->generator_spiky_config(), output);
  }

  // optional .protocol.effect.particle.ParticleConfig particle_config = 103;
  if (has_particle_config()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      103, this->particle_config(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:protocol.effect.EffectSetting)
}

::google::protobuf::uint8* EffectSetting::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:protocol.effect.EffectSetting)
  // optional .protocol.effect.EffectSetting.Type type = 1;
  if (has_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->type(), target);
  }

  // optional uint32 id = 3;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->id(), target);
  }

  // optional string name = 4;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->name(), target);
  }

  // optional uint32 start_time = 5;
  if (has_start_time()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(5, this->start_time(), target);
  }

  // optional uint32 end_time = 6;
  if (has_end_time()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(6, this->end_time(), target);
  }

  // optional .protocol.effect.plexus.PlexusConfig plexus_config = 100;
  if (has_plexus_config()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        100, this->plexus_config(), target);
  }

  // optional .protocol.effect.generator.PlaneConfig generator_plane_config = 101;
  if (has_generator_plane_config()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        101, this->generator_plane_config(), target);
  }

  // optional .protocol.effect.generator.SpikyConfig generator_spiky_config = 102;
  if (has_generator_spiky_config()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        102, this->generator_spiky_config(), target);
  }

  // optional .protocol.effect.particle.ParticleConfig particle_config = 103;
  if (has_particle_config()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        103, this->particle_config(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protocol.effect.EffectSetting)
  return target;
}

int EffectSetting::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .protocol.effect.EffectSetting.Type type = 1;
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->type());
    }

    // optional uint32 id = 3;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->id());
    }

    // optional string name = 4;
    if (has_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name());
    }

    // optional uint32 start_time = 5;
    if (has_start_time()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->start_time());
    }

    // optional uint32 end_time = 6;
    if (has_end_time()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->end_time());
    }

  }
  switch (config_case()) {
    // optional .protocol.effect.plexus.PlexusConfig plexus_config = 100;
    case kPlexusConfig: {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->plexus_config());
      break;
    }
    // optional .protocol.effect.generator.PlaneConfig generator_plane_config = 101;
    case kGeneratorPlaneConfig: {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->generator_plane_config());
      break;
    }
    // optional .protocol.effect.generator.SpikyConfig generator_spiky_config = 102;
    case kGeneratorSpikyConfig: {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->generator_spiky_config());
      break;
    }
    // optional .protocol.effect.particle.ParticleConfig particle_config = 103;
    case kParticleConfig: {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->particle_config());
      break;
    }
    case CONFIG_NOT_SET: {
      break;
    }
  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void EffectSetting::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const EffectSetting* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const EffectSetting*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void EffectSetting::MergeFrom(const EffectSetting& from) {
  GOOGLE_CHECK_NE(&from, this);
  switch (from.config_case()) {
    case kPlexusConfig: {
      mutable_plexus_config()->::protocol::effect::plexus::PlexusConfig::MergeFrom(from.plexus_config());
      break;
    }
    case kGeneratorPlaneConfig: {
      mutable_generator_plane_config()->::protocol::effect::generator::PlaneConfig::MergeFrom(from.generator_plane_config());
      break;
    }
    case kGeneratorSpikyConfig: {
      mutable_generator_spiky_config()->::protocol::effect::generator::SpikyConfig::MergeFrom(from.generator_spiky_config());
      break;
    }
    case kParticleConfig: {
      mutable_particle_config()->::protocol::effect::particle::ParticleConfig::MergeFrom(from.particle_config());
      break;
    }
    case CONFIG_NOT_SET: {
      break;
    }
  }
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_type()) {
      set_type(from.type());
    }
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_name()) {
      set_name(from.name());
    }
    if (from.has_start_time()) {
      set_start_time(from.start_time());
    }
    if (from.has_end_time()) {
      set_end_time(from.end_time());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void EffectSetting::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void EffectSetting::CopyFrom(const EffectSetting& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool EffectSetting::IsInitialized() const {

  return true;
}

void EffectSetting::Swap(EffectSetting* other) {
  if (other != this) {
    std::swap(type_, other->type_);
    std::swap(id_, other->id_);
    std::swap(name_, other->name_);
    std::swap(start_time_, other->start_time_);
    std::swap(end_time_, other->end_time_);
    std::swap(config_, other->config_);
    std::swap(_oneof_case_[0], other->_oneof_case_[0]);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata EffectSetting::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = EffectSetting_descriptor_;
  metadata.reflection = EffectSetting_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int EffectSettings::kEffectSettingFieldNumber;
const int EffectSettings::kSoundtrackFieldNumber;
#endif  // !_MSC_VER

EffectSettings::EffectSettings()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:protocol.effect.EffectSettings)
}

void EffectSettings::InitAsDefaultInstance() {
}

EffectSettings::EffectSettings(const EffectSettings& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:protocol.effect.EffectSettings)
}

void EffectSettings::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  soundtrack_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

EffectSettings::~EffectSettings() {
  // @@protoc_insertion_point(destructor:protocol.effect.EffectSettings)
  SharedDtor();
}

void EffectSettings::SharedDtor() {
  if (soundtrack_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete soundtrack_;
  }
  if (this != default_instance_) {
  }
}

void EffectSettings::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* EffectSettings::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return EffectSettings_descriptor_;
}

const EffectSettings& EffectSettings::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_effect_5fsettings_2eproto();
  return *default_instance_;
}

EffectSettings* EffectSettings::default_instance_ = NULL;

EffectSettings* EffectSettings::New() const {
  return new EffectSettings;
}

void EffectSettings::Clear() {
  if (has_soundtrack()) {
    if (soundtrack_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
      soundtrack_->clear();
    }
  }
  effect_setting_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool EffectSettings::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:protocol.effect.EffectSettings)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .protocol.effect.EffectSetting effect_setting = 1;
      case 1: {
        if (tag == 10) {
         parse_effect_setting:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_effect_setting()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_effect_setting;
        if (input->ExpectTag(18)) goto parse_soundtrack;
        break;
      }

      // optional string soundtrack = 2;
      case 2: {
        if (tag == 18) {
         parse_soundtrack:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_soundtrack()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->soundtrack().data(), this->soundtrack().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "soundtrack");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:protocol.effect.EffectSettings)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:protocol.effect.EffectSettings)
  return false;
#undef DO_
}

void EffectSettings::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:protocol.effect.EffectSettings)
  // repeated .protocol.effect.EffectSetting effect_setting = 1;
  for (int i = 0; i < this->effect_setting_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->effect_setting(i), output);
  }

  // optional string soundtrack = 2;
  if (has_soundtrack()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->soundtrack().data(), this->soundtrack().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "soundtrack");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->soundtrack(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:protocol.effect.EffectSettings)
}

::google::protobuf::uint8* EffectSettings::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:protocol.effect.EffectSettings)
  // repeated .protocol.effect.EffectSetting effect_setting = 1;
  for (int i = 0; i < this->effect_setting_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->effect_setting(i), target);
  }

  // optional string soundtrack = 2;
  if (has_soundtrack()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->soundtrack().data(), this->soundtrack().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "soundtrack");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->soundtrack(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protocol.effect.EffectSettings)
  return target;
}

int EffectSettings::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    // optional string soundtrack = 2;
    if (has_soundtrack()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->soundtrack());
    }

  }
  // repeated .protocol.effect.EffectSetting effect_setting = 1;
  total_size += 1 * this->effect_setting_size();
  for (int i = 0; i < this->effect_setting_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->effect_setting(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void EffectSettings::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const EffectSettings* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const EffectSettings*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void EffectSettings::MergeFrom(const EffectSettings& from) {
  GOOGLE_CHECK_NE(&from, this);
  effect_setting_.MergeFrom(from.effect_setting_);
  if (from._has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    if (from.has_soundtrack()) {
      set_soundtrack(from.soundtrack());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void EffectSettings::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void EffectSettings::CopyFrom(const EffectSettings& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool EffectSettings::IsInitialized() const {

  return true;
}

void EffectSettings::Swap(EffectSettings* other) {
  if (other != this) {
    effect_setting_.Swap(&other->effect_setting_);
    std::swap(soundtrack_, other->soundtrack_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata EffectSettings::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = EffectSettings_descriptor_;
  metadata.reflection = EffectSettings_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace effect
}  // namespace protocol

// @@protoc_insertion_point(global_scope)
