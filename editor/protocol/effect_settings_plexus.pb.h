// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: effect_settings_plexus.proto

#ifndef PROTOBUF_effect_5fsettings_5fplexus_2eproto__INCLUDED
#define PROTOBUF_effect_5fsettings_5fplexus_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "common.pb.h"
// @@protoc_insertion_point(includes)

namespace effect {
namespace plexus {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_effect_5fsettings_5fplexus_2eproto();
void protobuf_AssignDesc_effect_5fsettings_5fplexus_2eproto();
void protobuf_ShutdownFile_effect_5fsettings_5fplexus_2eproto();

class Plexus;
class TextPath;
class NoiseEffector;

enum NoiseEffector_ApplyTo {
  NoiseEffector_ApplyTo_POSITION = 1,
  NoiseEffector_ApplyTo_SCALE = 2
};
bool NoiseEffector_ApplyTo_IsValid(int value);
const NoiseEffector_ApplyTo NoiseEffector_ApplyTo_ApplyTo_MIN = NoiseEffector_ApplyTo_POSITION;
const NoiseEffector_ApplyTo NoiseEffector_ApplyTo_ApplyTo_MAX = NoiseEffector_ApplyTo_SCALE;
const int NoiseEffector_ApplyTo_ApplyTo_ARRAYSIZE = NoiseEffector_ApplyTo_ApplyTo_MAX + 1;

const ::google::protobuf::EnumDescriptor* NoiseEffector_ApplyTo_descriptor();
inline const ::std::string& NoiseEffector_ApplyTo_Name(NoiseEffector_ApplyTo value) {
  return ::google::protobuf::internal::NameOfEnum(
    NoiseEffector_ApplyTo_descriptor(), value);
}
inline bool NoiseEffector_ApplyTo_Parse(
    const ::std::string& name, NoiseEffector_ApplyTo* value) {
  return ::google::protobuf::internal::ParseNamedEnum<NoiseEffector_ApplyTo>(
    NoiseEffector_ApplyTo_descriptor(), name, value);
}
// ===================================================================

class Plexus : public ::google::protobuf::Message {
 public:
  Plexus();
  virtual ~Plexus();

  Plexus(const Plexus& from);

  inline Plexus& operator=(const Plexus& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Plexus& default_instance();

  void Swap(Plexus* other);

  // implements Message ----------------------------------------------

  Plexus* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Plexus& from);
  void MergeFrom(const Plexus& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .effect.plexus.TextPath text_path = 1;
  inline int text_path_size() const;
  inline void clear_text_path();
  static const int kTextPathFieldNumber = 1;
  inline const ::effect::plexus::TextPath& text_path(int index) const;
  inline ::effect::plexus::TextPath* mutable_text_path(int index);
  inline ::effect::plexus::TextPath* add_text_path();
  inline const ::google::protobuf::RepeatedPtrField< ::effect::plexus::TextPath >&
      text_path() const;
  inline ::google::protobuf::RepeatedPtrField< ::effect::plexus::TextPath >*
      mutable_text_path();

  // repeated .effect.plexus.NoiseEffector noise_effector = 2;
  inline int noise_effector_size() const;
  inline void clear_noise_effector();
  static const int kNoiseEffectorFieldNumber = 2;
  inline const ::effect::plexus::NoiseEffector& noise_effector(int index) const;
  inline ::effect::plexus::NoiseEffector* mutable_noise_effector(int index);
  inline ::effect::plexus::NoiseEffector* add_noise_effector();
  inline const ::google::protobuf::RepeatedPtrField< ::effect::plexus::NoiseEffector >&
      noise_effector() const;
  inline ::google::protobuf::RepeatedPtrField< ::effect::plexus::NoiseEffector >*
      mutable_noise_effector();

  // @@protoc_insertion_point(class_scope:effect.plexus.Plexus)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::effect::plexus::TextPath > text_path_;
  ::google::protobuf::RepeatedPtrField< ::effect::plexus::NoiseEffector > noise_effector_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_effect_5fsettings_5fplexus_2eproto();
  friend void protobuf_AssignDesc_effect_5fsettings_5fplexus_2eproto();
  friend void protobuf_ShutdownFile_effect_5fsettings_5fplexus_2eproto();

  void InitAsDefaultInstance();
  static Plexus* default_instance_;
};
// -------------------------------------------------------------------

class TextPath : public ::google::protobuf::Message {
 public:
  TextPath();
  virtual ~TextPath();

  TextPath(const TextPath& from);

  inline TextPath& operator=(const TextPath& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const TextPath& default_instance();

  void Swap(TextPath* other);

  // implements Message ----------------------------------------------

  TextPath* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const TextPath& from);
  void MergeFrom(const TextPath& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string text = 1;
  inline bool has_text() const;
  inline void clear_text();
  static const int kTextFieldNumber = 1;
  inline const ::std::string& text() const;
  inline void set_text(const ::std::string& value);
  inline void set_text(const char* value);
  inline void set_text(const char* value, size_t size);
  inline ::std::string* mutable_text();
  inline ::std::string* release_text();
  inline void set_allocated_text(::std::string* text);

  // @@protoc_insertion_point(class_scope:effect.plexus.TextPath)
 private:
  inline void set_has_text();
  inline void clear_has_text();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* text_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_effect_5fsettings_5fplexus_2eproto();
  friend void protobuf_AssignDesc_effect_5fsettings_5fplexus_2eproto();
  friend void protobuf_ShutdownFile_effect_5fsettings_5fplexus_2eproto();

  void InitAsDefaultInstance();
  static TextPath* default_instance_;
};
// -------------------------------------------------------------------

class NoiseEffector : public ::google::protobuf::Message {
 public:
  NoiseEffector();
  virtual ~NoiseEffector();

  NoiseEffector(const NoiseEffector& from);

  inline NoiseEffector& operator=(const NoiseEffector& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const NoiseEffector& default_instance();

  void Swap(NoiseEffector* other);

  // implements Message ----------------------------------------------

  NoiseEffector* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const NoiseEffector& from);
  void MergeFrom(const NoiseEffector& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  typedef NoiseEffector_ApplyTo ApplyTo;
  static const ApplyTo POSITION = NoiseEffector_ApplyTo_POSITION;
  static const ApplyTo SCALE = NoiseEffector_ApplyTo_SCALE;
  static inline bool ApplyTo_IsValid(int value) {
    return NoiseEffector_ApplyTo_IsValid(value);
  }
  static const ApplyTo ApplyTo_MIN =
    NoiseEffector_ApplyTo_ApplyTo_MIN;
  static const ApplyTo ApplyTo_MAX =
    NoiseEffector_ApplyTo_ApplyTo_MAX;
  static const int ApplyTo_ARRAYSIZE =
    NoiseEffector_ApplyTo_ApplyTo_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  ApplyTo_descriptor() {
    return NoiseEffector_ApplyTo_descriptor();
  }
  static inline const ::std::string& ApplyTo_Name(ApplyTo value) {
    return NoiseEffector_ApplyTo_Name(value);
  }
  static inline bool ApplyTo_Parse(const ::std::string& name,
      ApplyTo* value) {
    return NoiseEffector_ApplyTo_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // optional .effect.plexus.NoiseEffector.ApplyTo apply_to = 1 [default = POSITION];
  inline bool has_apply_to() const;
  inline void clear_apply_to();
  static const int kApplyToFieldNumber = 1;
  inline ::effect::plexus::NoiseEffector_ApplyTo apply_to() const;
  inline void set_apply_to(::effect::plexus::NoiseEffector_ApplyTo value);

  // optional .common.Vector3Anim displacement = 2;
  inline bool has_displacement() const;
  inline void clear_displacement();
  static const int kDisplacementFieldNumber = 2;
  inline const ::common::Vector3Anim& displacement() const;
  inline ::common::Vector3Anim* mutable_displacement();
  inline ::common::Vector3Anim* release_displacement();
  inline void set_allocated_displacement(::common::Vector3Anim* displacement);

  // @@protoc_insertion_point(class_scope:effect.plexus.NoiseEffector)
 private:
  inline void set_has_apply_to();
  inline void clear_has_apply_to();
  inline void set_has_displacement();
  inline void clear_has_displacement();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::common::Vector3Anim* displacement_;
  int apply_to_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_effect_5fsettings_5fplexus_2eproto();
  friend void protobuf_AssignDesc_effect_5fsettings_5fplexus_2eproto();
  friend void protobuf_ShutdownFile_effect_5fsettings_5fplexus_2eproto();

  void InitAsDefaultInstance();
  static NoiseEffector* default_instance_;
};
// ===================================================================


// ===================================================================

// Plexus

// repeated .effect.plexus.TextPath text_path = 1;
inline int Plexus::text_path_size() const {
  return text_path_.size();
}
inline void Plexus::clear_text_path() {
  text_path_.Clear();
}
inline const ::effect::plexus::TextPath& Plexus::text_path(int index) const {
  return text_path_.Get(index);
}
inline ::effect::plexus::TextPath* Plexus::mutable_text_path(int index) {
  return text_path_.Mutable(index);
}
inline ::effect::plexus::TextPath* Plexus::add_text_path() {
  return text_path_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::effect::plexus::TextPath >&
Plexus::text_path() const {
  return text_path_;
}
inline ::google::protobuf::RepeatedPtrField< ::effect::plexus::TextPath >*
Plexus::mutable_text_path() {
  return &text_path_;
}

// repeated .effect.plexus.NoiseEffector noise_effector = 2;
inline int Plexus::noise_effector_size() const {
  return noise_effector_.size();
}
inline void Plexus::clear_noise_effector() {
  noise_effector_.Clear();
}
inline const ::effect::plexus::NoiseEffector& Plexus::noise_effector(int index) const {
  return noise_effector_.Get(index);
}
inline ::effect::plexus::NoiseEffector* Plexus::mutable_noise_effector(int index) {
  return noise_effector_.Mutable(index);
}
inline ::effect::plexus::NoiseEffector* Plexus::add_noise_effector() {
  return noise_effector_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::effect::plexus::NoiseEffector >&
Plexus::noise_effector() const {
  return noise_effector_;
}
inline ::google::protobuf::RepeatedPtrField< ::effect::plexus::NoiseEffector >*
Plexus::mutable_noise_effector() {
  return &noise_effector_;
}

// -------------------------------------------------------------------

// TextPath

// optional string text = 1;
inline bool TextPath::has_text() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void TextPath::set_has_text() {
  _has_bits_[0] |= 0x00000001u;
}
inline void TextPath::clear_has_text() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void TextPath::clear_text() {
  if (text_ != &::google::protobuf::internal::kEmptyString) {
    text_->clear();
  }
  clear_has_text();
}
inline const ::std::string& TextPath::text() const {
  return *text_;
}
inline void TextPath::set_text(const ::std::string& value) {
  set_has_text();
  if (text_ == &::google::protobuf::internal::kEmptyString) {
    text_ = new ::std::string;
  }
  text_->assign(value);
}
inline void TextPath::set_text(const char* value) {
  set_has_text();
  if (text_ == &::google::protobuf::internal::kEmptyString) {
    text_ = new ::std::string;
  }
  text_->assign(value);
}
inline void TextPath::set_text(const char* value, size_t size) {
  set_has_text();
  if (text_ == &::google::protobuf::internal::kEmptyString) {
    text_ = new ::std::string;
  }
  text_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* TextPath::mutable_text() {
  set_has_text();
  if (text_ == &::google::protobuf::internal::kEmptyString) {
    text_ = new ::std::string;
  }
  return text_;
}
inline ::std::string* TextPath::release_text() {
  clear_has_text();
  if (text_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = text_;
    text_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void TextPath::set_allocated_text(::std::string* text) {
  if (text_ != &::google::protobuf::internal::kEmptyString) {
    delete text_;
  }
  if (text) {
    set_has_text();
    text_ = text;
  } else {
    clear_has_text();
    text_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// -------------------------------------------------------------------

// NoiseEffector

// optional .effect.plexus.NoiseEffector.ApplyTo apply_to = 1 [default = POSITION];
inline bool NoiseEffector::has_apply_to() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void NoiseEffector::set_has_apply_to() {
  _has_bits_[0] |= 0x00000001u;
}
inline void NoiseEffector::clear_has_apply_to() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void NoiseEffector::clear_apply_to() {
  apply_to_ = 1;
  clear_has_apply_to();
}
inline ::effect::plexus::NoiseEffector_ApplyTo NoiseEffector::apply_to() const {
  return static_cast< ::effect::plexus::NoiseEffector_ApplyTo >(apply_to_);
}
inline void NoiseEffector::set_apply_to(::effect::plexus::NoiseEffector_ApplyTo value) {
  assert(::effect::plexus::NoiseEffector_ApplyTo_IsValid(value));
  set_has_apply_to();
  apply_to_ = value;
}

// optional .common.Vector3Anim displacement = 2;
inline bool NoiseEffector::has_displacement() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void NoiseEffector::set_has_displacement() {
  _has_bits_[0] |= 0x00000002u;
}
inline void NoiseEffector::clear_has_displacement() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void NoiseEffector::clear_displacement() {
  if (displacement_ != NULL) displacement_->::common::Vector3Anim::Clear();
  clear_has_displacement();
}
inline const ::common::Vector3Anim& NoiseEffector::displacement() const {
  return displacement_ != NULL ? *displacement_ : *default_instance_->displacement_;
}
inline ::common::Vector3Anim* NoiseEffector::mutable_displacement() {
  set_has_displacement();
  if (displacement_ == NULL) displacement_ = new ::common::Vector3Anim;
  return displacement_;
}
inline ::common::Vector3Anim* NoiseEffector::release_displacement() {
  clear_has_displacement();
  ::common::Vector3Anim* temp = displacement_;
  displacement_ = NULL;
  return temp;
}
inline void NoiseEffector::set_allocated_displacement(::common::Vector3Anim* displacement) {
  delete displacement_;
  displacement_ = displacement;
  if (displacement) {
    set_has_displacement();
  } else {
    clear_has_displacement();
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace plexus
}  // namespace effect

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< ::effect::plexus::NoiseEffector_ApplyTo>() {
  return ::effect::plexus::NoiseEffector_ApplyTo_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_effect_5fsettings_5fplexus_2eproto__INCLUDED
