// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: editor_styles.proto

#ifndef PROTOBUF_editor_5fstyles_2eproto__INCLUDED
#define PROTOBUF_editor_5fstyles_2eproto__INCLUDED

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
#include <google/protobuf/unknown_field_set.h>
#include "editor_settings.pb.h"
// @@protoc_insertion_point(includes)

namespace editor {
namespace protocol {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_editor_5fstyles_2eproto();
void protobuf_AssignDesc_editor_5fstyles_2eproto();
void protobuf_ShutdownFile_editor_5fstyles_2eproto();

class Style;
class Styles;

// ===================================================================

class Style : public ::google::protobuf::Message {
 public:
  Style();
  virtual ~Style();

  Style(const Style& from);

  inline Style& operator=(const Style& from) {
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
  static const Style& default_instance();

  void Swap(Style* other);

  // implements Message ----------------------------------------------

  Style* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Style& from);
  void MergeFrom(const Style& from);
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

  // optional string id = 1;
  inline bool has_id() const;
  inline void clear_id();
  static const int kIdFieldNumber = 1;
  inline const ::std::string& id() const;
  inline void set_id(const ::std::string& value);
  inline void set_id(const char* value);
  inline void set_id(const char* value, size_t size);
  inline ::std::string* mutable_id();
  inline ::std::string* release_id();
  inline void set_allocated_id(::std::string* id);

  // optional .editor.protocol.Color4 fill_color = 2;
  inline bool has_fill_color() const;
  inline void clear_fill_color();
  static const int kFillColorFieldNumber = 2;
  inline const ::editor::protocol::Color4& fill_color() const;
  inline ::editor::protocol::Color4* mutable_fill_color();
  inline ::editor::protocol::Color4* release_fill_color();
  inline void set_allocated_fill_color(::editor::protocol::Color4* fill_color);

  // optional .editor.protocol.Color4 outline_color = 3;
  inline bool has_outline_color() const;
  inline void clear_outline_color();
  static const int kOutlineColorFieldNumber = 3;
  inline const ::editor::protocol::Color4& outline_color() const;
  inline ::editor::protocol::Color4* mutable_outline_color();
  inline ::editor::protocol::Color4* release_outline_color();
  inline void set_allocated_outline_color(::editor::protocol::Color4* outline_color);

  // optional float outline_thickness = 4 [default = 0];
  inline bool has_outline_thickness() const;
  inline void clear_outline_thickness();
  static const int kOutlineThicknessFieldNumber = 4;
  inline float outline_thickness() const;
  inline void set_outline_thickness(float value);

  // optional uint32 font_style = 5;
  inline bool has_font_style() const;
  inline void clear_font_style();
  static const int kFontStyleFieldNumber = 5;
  inline ::google::protobuf::uint32 font_style() const;
  inline void set_font_style(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:editor.protocol.Style)
 private:
  inline void set_has_id();
  inline void clear_has_id();
  inline void set_has_fill_color();
  inline void clear_has_fill_color();
  inline void set_has_outline_color();
  inline void clear_has_outline_color();
  inline void set_has_outline_thickness();
  inline void clear_has_outline_thickness();
  inline void set_has_font_style();
  inline void clear_has_font_style();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* id_;
  ::editor::protocol::Color4* fill_color_;
  ::editor::protocol::Color4* outline_color_;
  float outline_thickness_;
  ::google::protobuf::uint32 font_style_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(5 + 31) / 32];

  friend void  protobuf_AddDesc_editor_5fstyles_2eproto();
  friend void protobuf_AssignDesc_editor_5fstyles_2eproto();
  friend void protobuf_ShutdownFile_editor_5fstyles_2eproto();

  void InitAsDefaultInstance();
  static Style* default_instance_;
};
// -------------------------------------------------------------------

class Styles : public ::google::protobuf::Message {
 public:
  Styles();
  virtual ~Styles();

  Styles(const Styles& from);

  inline Styles& operator=(const Styles& from) {
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
  static const Styles& default_instance();

  void Swap(Styles* other);

  // implements Message ----------------------------------------------

  Styles* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Styles& from);
  void MergeFrom(const Styles& from);
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

  // repeated .editor.protocol.Style styles = 1;
  inline int styles_size() const;
  inline void clear_styles();
  static const int kStylesFieldNumber = 1;
  inline const ::editor::protocol::Style& styles(int index) const;
  inline ::editor::protocol::Style* mutable_styles(int index);
  inline ::editor::protocol::Style* add_styles();
  inline const ::google::protobuf::RepeatedPtrField< ::editor::protocol::Style >&
      styles() const;
  inline ::google::protobuf::RepeatedPtrField< ::editor::protocol::Style >*
      mutable_styles();

  // @@protoc_insertion_point(class_scope:editor.protocol.Styles)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::editor::protocol::Style > styles_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_editor_5fstyles_2eproto();
  friend void protobuf_AssignDesc_editor_5fstyles_2eproto();
  friend void protobuf_ShutdownFile_editor_5fstyles_2eproto();

  void InitAsDefaultInstance();
  static Styles* default_instance_;
};
// ===================================================================


// ===================================================================

// Style

// optional string id = 1;
inline bool Style::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Style::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Style::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Style::clear_id() {
  if (id_ != &::google::protobuf::internal::kEmptyString) {
    id_->clear();
  }
  clear_has_id();
}
inline const ::std::string& Style::id() const {
  return *id_;
}
inline void Style::set_id(const ::std::string& value) {
  set_has_id();
  if (id_ == &::google::protobuf::internal::kEmptyString) {
    id_ = new ::std::string;
  }
  id_->assign(value);
}
inline void Style::set_id(const char* value) {
  set_has_id();
  if (id_ == &::google::protobuf::internal::kEmptyString) {
    id_ = new ::std::string;
  }
  id_->assign(value);
}
inline void Style::set_id(const char* value, size_t size) {
  set_has_id();
  if (id_ == &::google::protobuf::internal::kEmptyString) {
    id_ = new ::std::string;
  }
  id_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Style::mutable_id() {
  set_has_id();
  if (id_ == &::google::protobuf::internal::kEmptyString) {
    id_ = new ::std::string;
  }
  return id_;
}
inline ::std::string* Style::release_id() {
  clear_has_id();
  if (id_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = id_;
    id_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Style::set_allocated_id(::std::string* id) {
  if (id_ != &::google::protobuf::internal::kEmptyString) {
    delete id_;
  }
  if (id) {
    set_has_id();
    id_ = id;
  } else {
    clear_has_id();
    id_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional .editor.protocol.Color4 fill_color = 2;
inline bool Style::has_fill_color() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Style::set_has_fill_color() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Style::clear_has_fill_color() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Style::clear_fill_color() {
  if (fill_color_ != NULL) fill_color_->::editor::protocol::Color4::Clear();
  clear_has_fill_color();
}
inline const ::editor::protocol::Color4& Style::fill_color() const {
  return fill_color_ != NULL ? *fill_color_ : *default_instance_->fill_color_;
}
inline ::editor::protocol::Color4* Style::mutable_fill_color() {
  set_has_fill_color();
  if (fill_color_ == NULL) fill_color_ = new ::editor::protocol::Color4;
  return fill_color_;
}
inline ::editor::protocol::Color4* Style::release_fill_color() {
  clear_has_fill_color();
  ::editor::protocol::Color4* temp = fill_color_;
  fill_color_ = NULL;
  return temp;
}
inline void Style::set_allocated_fill_color(::editor::protocol::Color4* fill_color) {
  delete fill_color_;
  fill_color_ = fill_color;
  if (fill_color) {
    set_has_fill_color();
  } else {
    clear_has_fill_color();
  }
}

// optional .editor.protocol.Color4 outline_color = 3;
inline bool Style::has_outline_color() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Style::set_has_outline_color() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Style::clear_has_outline_color() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Style::clear_outline_color() {
  if (outline_color_ != NULL) outline_color_->::editor::protocol::Color4::Clear();
  clear_has_outline_color();
}
inline const ::editor::protocol::Color4& Style::outline_color() const {
  return outline_color_ != NULL ? *outline_color_ : *default_instance_->outline_color_;
}
inline ::editor::protocol::Color4* Style::mutable_outline_color() {
  set_has_outline_color();
  if (outline_color_ == NULL) outline_color_ = new ::editor::protocol::Color4;
  return outline_color_;
}
inline ::editor::protocol::Color4* Style::release_outline_color() {
  clear_has_outline_color();
  ::editor::protocol::Color4* temp = outline_color_;
  outline_color_ = NULL;
  return temp;
}
inline void Style::set_allocated_outline_color(::editor::protocol::Color4* outline_color) {
  delete outline_color_;
  outline_color_ = outline_color;
  if (outline_color) {
    set_has_outline_color();
  } else {
    clear_has_outline_color();
  }
}

// optional float outline_thickness = 4 [default = 0];
inline bool Style::has_outline_thickness() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Style::set_has_outline_thickness() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Style::clear_has_outline_thickness() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Style::clear_outline_thickness() {
  outline_thickness_ = 0;
  clear_has_outline_thickness();
}
inline float Style::outline_thickness() const {
  return outline_thickness_;
}
inline void Style::set_outline_thickness(float value) {
  set_has_outline_thickness();
  outline_thickness_ = value;
}

// optional uint32 font_style = 5;
inline bool Style::has_font_style() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void Style::set_has_font_style() {
  _has_bits_[0] |= 0x00000010u;
}
inline void Style::clear_has_font_style() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void Style::clear_font_style() {
  font_style_ = 0u;
  clear_has_font_style();
}
inline ::google::protobuf::uint32 Style::font_style() const {
  return font_style_;
}
inline void Style::set_font_style(::google::protobuf::uint32 value) {
  set_has_font_style();
  font_style_ = value;
}

// -------------------------------------------------------------------

// Styles

// repeated .editor.protocol.Style styles = 1;
inline int Styles::styles_size() const {
  return styles_.size();
}
inline void Styles::clear_styles() {
  styles_.Clear();
}
inline const ::editor::protocol::Style& Styles::styles(int index) const {
  return styles_.Get(index);
}
inline ::editor::protocol::Style* Styles::mutable_styles(int index) {
  return styles_.Mutable(index);
}
inline ::editor::protocol::Style* Styles::add_styles() {
  return styles_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::editor::protocol::Style >&
Styles::styles() const {
  return styles_;
}
inline ::google::protobuf::RepeatedPtrField< ::editor::protocol::Style >*
Styles::mutable_styles() {
  return &styles_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol
}  // namespace editor

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_editor_5fstyles_2eproto__INCLUDED
