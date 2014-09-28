// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: editor_styles.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "editor_styles.pb.h"

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
namespace editor {

namespace {

const ::google::protobuf::Descriptor* StyleSetting_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  StyleSetting_reflection_ = NULL;
const ::google::protobuf::Descriptor* StyleSettings_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  StyleSettings_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_editor_5fstyles_2eproto() {
  protobuf_AddDesc_editor_5fstyles_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "editor_styles.proto");
  GOOGLE_CHECK(file != NULL);
  StyleSetting_descriptor_ = file->message_type(0);
  static const int StyleSetting_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(StyleSetting, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(StyleSetting, fill_color_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(StyleSetting, outline_color_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(StyleSetting, outline_thickness_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(StyleSetting, font_style_),
  };
  StyleSetting_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      StyleSetting_descriptor_,
      StyleSetting::default_instance_,
      StyleSetting_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(StyleSetting, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(StyleSetting, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(StyleSetting));
  StyleSettings_descriptor_ = file->message_type(1);
  static const int StyleSettings_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(StyleSettings, style_setting_),
  };
  StyleSettings_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      StyleSettings_descriptor_,
      StyleSettings::default_instance_,
      StyleSettings_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(StyleSettings, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(StyleSettings, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(StyleSettings));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_editor_5fstyles_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    StyleSetting_descriptor_, &StyleSetting::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    StyleSettings_descriptor_, &StyleSettings::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_editor_5fstyles_2eproto() {
  delete StyleSetting::default_instance_;
  delete StyleSetting_reflection_;
  delete StyleSettings::default_instance_;
  delete StyleSettings_reflection_;
}

void protobuf_AddDesc_editor_5fstyles_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::protocol::editor::protobuf_AddDesc_editor_5fsettings_2eproto();
  ::protocol::common::protobuf_AddDesc_common_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\023editor_styles.proto\022\017protocol.editor\032\025"
    "editor_settings.proto\032\014common.proto\"\251\001\n\014"
    "StyleSetting\022\n\n\002id\030\001 \001(\t\022+\n\nfill_color\030\002"
    " \001(\0132\027.protocol.common.Color4\022.\n\routline"
    "_color\030\003 \001(\0132\027.protocol.common.Color4\022\034\n"
    "\021outline_thickness\030\004 \001(\002:\0010\022\022\n\nfont_styl"
    "e\030\005 \001(\r\"E\n\rStyleSettings\0224\n\rstyle_settin"
    "g\030\001 \003(\0132\035.protocol.editor.StyleSetting", 318);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "editor_styles.proto", &protobuf_RegisterTypes);
  StyleSetting::default_instance_ = new StyleSetting();
  StyleSettings::default_instance_ = new StyleSettings();
  StyleSetting::default_instance_->InitAsDefaultInstance();
  StyleSettings::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_editor_5fstyles_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_editor_5fstyles_2eproto {
  StaticDescriptorInitializer_editor_5fstyles_2eproto() {
    protobuf_AddDesc_editor_5fstyles_2eproto();
  }
} static_descriptor_initializer_editor_5fstyles_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int StyleSetting::kIdFieldNumber;
const int StyleSetting::kFillColorFieldNumber;
const int StyleSetting::kOutlineColorFieldNumber;
const int StyleSetting::kOutlineThicknessFieldNumber;
const int StyleSetting::kFontStyleFieldNumber;
#endif  // !_MSC_VER

StyleSetting::StyleSetting()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:protocol.editor.StyleSetting)
}

void StyleSetting::InitAsDefaultInstance() {
  fill_color_ = const_cast< ::protocol::common::Color4*>(&::protocol::common::Color4::default_instance());
  outline_color_ = const_cast< ::protocol::common::Color4*>(&::protocol::common::Color4::default_instance());
}

StyleSetting::StyleSetting(const StyleSetting& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:protocol.editor.StyleSetting)
}

void StyleSetting::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  fill_color_ = NULL;
  outline_color_ = NULL;
  outline_thickness_ = 0;
  font_style_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

StyleSetting::~StyleSetting() {
  // @@protoc_insertion_point(destructor:protocol.editor.StyleSetting)
  SharedDtor();
}

void StyleSetting::SharedDtor() {
  if (id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete id_;
  }
  if (this != default_instance_) {
    delete fill_color_;
    delete outline_color_;
  }
}

void StyleSetting::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* StyleSetting::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return StyleSetting_descriptor_;
}

const StyleSetting& StyleSetting::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_editor_5fstyles_2eproto();
  return *default_instance_;
}

StyleSetting* StyleSetting::default_instance_ = NULL;

StyleSetting* StyleSetting::New() const {
  return new StyleSetting;
}

void StyleSetting::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<StyleSetting*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 31) {
    ZR_(outline_thickness_, font_style_);
    if (has_id()) {
      if (id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        id_->clear();
      }
    }
    if (has_fill_color()) {
      if (fill_color_ != NULL) fill_color_->::protocol::common::Color4::Clear();
    }
    if (has_outline_color()) {
      if (outline_color_ != NULL) outline_color_->::protocol::common::Color4::Clear();
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool StyleSetting::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:protocol.editor.StyleSetting)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_id()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->id().data(), this->id().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "id");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_fill_color;
        break;
      }

      // optional .protocol.common.Color4 fill_color = 2;
      case 2: {
        if (tag == 18) {
         parse_fill_color:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_fill_color()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_outline_color;
        break;
      }

      // optional .protocol.common.Color4 outline_color = 3;
      case 3: {
        if (tag == 26) {
         parse_outline_color:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_outline_color()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(37)) goto parse_outline_thickness;
        break;
      }

      // optional float outline_thickness = 4 [default = 0];
      case 4: {
        if (tag == 37) {
         parse_outline_thickness:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &outline_thickness_)));
          set_has_outline_thickness();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_font_style;
        break;
      }

      // optional uint32 font_style = 5;
      case 5: {
        if (tag == 40) {
         parse_font_style:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &font_style_)));
          set_has_font_style();
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
  // @@protoc_insertion_point(parse_success:protocol.editor.StyleSetting)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:protocol.editor.StyleSetting)
  return false;
#undef DO_
}

void StyleSetting::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:protocol.editor.StyleSetting)
  // optional string id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->id().data(), this->id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->id(), output);
  }

  // optional .protocol.common.Color4 fill_color = 2;
  if (has_fill_color()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->fill_color(), output);
  }

  // optional .protocol.common.Color4 outline_color = 3;
  if (has_outline_color()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->outline_color(), output);
  }

  // optional float outline_thickness = 4 [default = 0];
  if (has_outline_thickness()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(4, this->outline_thickness(), output);
  }

  // optional uint32 font_style = 5;
  if (has_font_style()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(5, this->font_style(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:protocol.editor.StyleSetting)
}

::google::protobuf::uint8* StyleSetting::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:protocol.editor.StyleSetting)
  // optional string id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->id().data(), this->id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->id(), target);
  }

  // optional .protocol.common.Color4 fill_color = 2;
  if (has_fill_color()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->fill_color(), target);
  }

  // optional .protocol.common.Color4 outline_color = 3;
  if (has_outline_color()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->outline_color(), target);
  }

  // optional float outline_thickness = 4 [default = 0];
  if (has_outline_thickness()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(4, this->outline_thickness(), target);
  }

  // optional uint32 font_style = 5;
  if (has_font_style()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(5, this->font_style(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protocol.editor.StyleSetting)
  return target;
}

int StyleSetting::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional string id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->id());
    }

    // optional .protocol.common.Color4 fill_color = 2;
    if (has_fill_color()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->fill_color());
    }

    // optional .protocol.common.Color4 outline_color = 3;
    if (has_outline_color()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->outline_color());
    }

    // optional float outline_thickness = 4 [default = 0];
    if (has_outline_thickness()) {
      total_size += 1 + 4;
    }

    // optional uint32 font_style = 5;
    if (has_font_style()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->font_style());
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

void StyleSetting::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const StyleSetting* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const StyleSetting*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void StyleSetting::MergeFrom(const StyleSetting& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_fill_color()) {
      mutable_fill_color()->::protocol::common::Color4::MergeFrom(from.fill_color());
    }
    if (from.has_outline_color()) {
      mutable_outline_color()->::protocol::common::Color4::MergeFrom(from.outline_color());
    }
    if (from.has_outline_thickness()) {
      set_outline_thickness(from.outline_thickness());
    }
    if (from.has_font_style()) {
      set_font_style(from.font_style());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void StyleSetting::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void StyleSetting::CopyFrom(const StyleSetting& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool StyleSetting::IsInitialized() const {

  return true;
}

void StyleSetting::Swap(StyleSetting* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(fill_color_, other->fill_color_);
    std::swap(outline_color_, other->outline_color_);
    std::swap(outline_thickness_, other->outline_thickness_);
    std::swap(font_style_, other->font_style_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata StyleSetting::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = StyleSetting_descriptor_;
  metadata.reflection = StyleSetting_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int StyleSettings::kStyleSettingFieldNumber;
#endif  // !_MSC_VER

StyleSettings::StyleSettings()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:protocol.editor.StyleSettings)
}

void StyleSettings::InitAsDefaultInstance() {
}

StyleSettings::StyleSettings(const StyleSettings& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:protocol.editor.StyleSettings)
}

void StyleSettings::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

StyleSettings::~StyleSettings() {
  // @@protoc_insertion_point(destructor:protocol.editor.StyleSettings)
  SharedDtor();
}

void StyleSettings::SharedDtor() {
  if (this != default_instance_) {
  }
}

void StyleSettings::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* StyleSettings::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return StyleSettings_descriptor_;
}

const StyleSettings& StyleSettings::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_editor_5fstyles_2eproto();
  return *default_instance_;
}

StyleSettings* StyleSettings::default_instance_ = NULL;

StyleSettings* StyleSettings::New() const {
  return new StyleSettings;
}

void StyleSettings::Clear() {
  style_setting_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool StyleSettings::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:protocol.editor.StyleSettings)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .protocol.editor.StyleSetting style_setting = 1;
      case 1: {
        if (tag == 10) {
         parse_style_setting:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_style_setting()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_style_setting;
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
  // @@protoc_insertion_point(parse_success:protocol.editor.StyleSettings)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:protocol.editor.StyleSettings)
  return false;
#undef DO_
}

void StyleSettings::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:protocol.editor.StyleSettings)
  // repeated .protocol.editor.StyleSetting style_setting = 1;
  for (int i = 0; i < this->style_setting_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->style_setting(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:protocol.editor.StyleSettings)
}

::google::protobuf::uint8* StyleSettings::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:protocol.editor.StyleSettings)
  // repeated .protocol.editor.StyleSetting style_setting = 1;
  for (int i = 0; i < this->style_setting_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->style_setting(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protocol.editor.StyleSettings)
  return target;
}

int StyleSettings::ByteSize() const {
  int total_size = 0;

  // repeated .protocol.editor.StyleSetting style_setting = 1;
  total_size += 1 * this->style_setting_size();
  for (int i = 0; i < this->style_setting_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->style_setting(i));
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

void StyleSettings::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const StyleSettings* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const StyleSettings*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void StyleSettings::MergeFrom(const StyleSettings& from) {
  GOOGLE_CHECK_NE(&from, this);
  style_setting_.MergeFrom(from.style_setting_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void StyleSettings::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void StyleSettings::CopyFrom(const StyleSettings& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool StyleSettings::IsInitialized() const {

  return true;
}

void StyleSettings::Swap(StyleSettings* other) {
  if (other != this) {
    style_setting_.Swap(&other->style_setting_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata StyleSettings::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = StyleSettings_descriptor_;
  metadata.reflection = StyleSettings_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace editor
}  // namespace protocol

// @@protoc_insertion_point(global_scope)
