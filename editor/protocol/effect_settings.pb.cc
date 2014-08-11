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

namespace effect {
namespace protocol {

namespace {

const ::google::protobuf::Descriptor* EffectSetting_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  EffectSetting_reflection_ = NULL;
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
  static const int EffectSetting_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EffectSetting, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EffectSetting, msg_),
  };
  EffectSetting_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      EffectSetting_descriptor_,
      EffectSetting::default_instance_,
      EffectSetting_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EffectSetting, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EffectSetting, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(EffectSetting));
  EffectSetting_Type_descriptor_ = EffectSetting_descriptor_->enum_type(0);
  EffectSettings_descriptor_ = file->message_type(1);
  static const int EffectSettings_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EffectSettings, effect_settings_),
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
  delete EffectSetting_reflection_;
  delete EffectSettings::default_instance_;
  delete EffectSettings_reflection_;
}

void protobuf_AddDesc_effect_5fsettings_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\025effect_settings.proto\022\017effect.protocol"
    "\"c\n\rEffectSetting\0221\n\004type\030\001 \001(\0162#.effect"
    ".protocol.EffectSetting.Type\022\013\n\003msg\030\002 \001("
    "\014\"\022\n\004Type\022\n\n\006Plexus\020\001\"I\n\016EffectSettings\022"
    "7\n\017effect_settings\030\001 \003(\0132\036.effect.protoc"
    "ol.EffectSetting", 216);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "effect_settings.proto", &protobuf_RegisterTypes);
  EffectSetting::default_instance_ = new EffectSetting();
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
    case 1:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const EffectSetting_Type EffectSetting::Plexus;
const EffectSetting_Type EffectSetting::Type_MIN;
const EffectSetting_Type EffectSetting::Type_MAX;
const int EffectSetting::Type_ARRAYSIZE;
#endif  // _MSC_VER
#ifndef _MSC_VER
const int EffectSetting::kTypeFieldNumber;
const int EffectSetting::kMsgFieldNumber;
#endif  // !_MSC_VER

EffectSetting::EffectSetting()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void EffectSetting::InitAsDefaultInstance() {
}

EffectSetting::EffectSetting(const EffectSetting& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void EffectSetting::SharedCtor() {
  _cached_size_ = 0;
  type_ = 1;
  msg_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

EffectSetting::~EffectSetting() {
  SharedDtor();
}

void EffectSetting::SharedDtor() {
  if (msg_ != &::google::protobuf::internal::kEmptyString) {
    delete msg_;
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

void EffectSetting::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    type_ = 1;
    if (has_msg()) {
      if (msg_ != &::google::protobuf::internal::kEmptyString) {
        msg_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool EffectSetting::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .effect.protocol.EffectSetting.Type type = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::effect::protocol::EffectSetting_Type_IsValid(value)) {
            set_type(static_cast< ::effect::protocol::EffectSetting_Type >(value));
          } else {
            mutable_unknown_fields()->AddVarint(1, value);
          }
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_msg;
        break;
      }

      // optional bytes msg = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_msg:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_msg()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void EffectSetting::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional .effect.protocol.EffectSetting.Type type = 1;
  if (has_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->type(), output);
  }

  // optional bytes msg = 2;
  if (has_msg()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      2, this->msg(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* EffectSetting::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional .effect.protocol.EffectSetting.Type type = 1;
  if (has_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->type(), target);
  }

  // optional bytes msg = 2;
  if (has_msg()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        2, this->msg(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int EffectSetting::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .effect.protocol.EffectSetting.Type type = 1;
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->type());
    }

    // optional bytes msg = 2;
    if (has_msg()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->msg());
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
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_type()) {
      set_type(from.type());
    }
    if (from.has_msg()) {
      set_msg(from.msg());
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
    std::swap(msg_, other->msg_);
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
const int EffectSettings::kEffectSettingsFieldNumber;
#endif  // !_MSC_VER

EffectSettings::EffectSettings()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void EffectSettings::InitAsDefaultInstance() {
}

EffectSettings::EffectSettings(const EffectSettings& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void EffectSettings::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

EffectSettings::~EffectSettings() {
  SharedDtor();
}

void EffectSettings::SharedDtor() {
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
  effect_settings_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool EffectSettings::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .effect.protocol.EffectSetting effect_settings = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_effect_settings:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_effect_settings()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(10)) goto parse_effect_settings;
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void EffectSettings::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated .effect.protocol.EffectSetting effect_settings = 1;
  for (int i = 0; i < this->effect_settings_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->effect_settings(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* EffectSettings::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // repeated .effect.protocol.EffectSetting effect_settings = 1;
  for (int i = 0; i < this->effect_settings_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->effect_settings(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int EffectSettings::ByteSize() const {
  int total_size = 0;

  // repeated .effect.protocol.EffectSetting effect_settings = 1;
  total_size += 1 * this->effect_settings_size();
  for (int i = 0; i < this->effect_settings_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->effect_settings(i));
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
  effect_settings_.MergeFrom(from.effect_settings_);
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
    effect_settings_.Swap(&other->effect_settings_);
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

}  // namespace protocol
}  // namespace effect

// @@protoc_insertion_point(global_scope)
