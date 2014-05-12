// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: common.proto

#ifndef PROTOBUF_common_2eproto__INCLUDED
#define PROTOBUF_common_2eproto__INCLUDED

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
// @@protoc_insertion_point(includes)

namespace common {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_common_2eproto();
void protobuf_AssignDesc_common_2eproto();
void protobuf_ShutdownFile_common_2eproto();

class Vector2;
class Vector3;
class Vector4;
class Matrix3x3;
class Matrix4x4;

// ===================================================================

class Vector2 : public ::google::protobuf::Message {
 public:
  Vector2();
  virtual ~Vector2();

  Vector2(const Vector2& from);

  inline Vector2& operator=(const Vector2& from) {
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
  static const Vector2& default_instance();

  void Swap(Vector2* other);

  // implements Message ----------------------------------------------

  Vector2* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Vector2& from);
  void MergeFrom(const Vector2& from);
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

  // optional float x = 1;
  inline bool has_x() const;
  inline void clear_x();
  static const int kXFieldNumber = 1;
  inline float x() const;
  inline void set_x(float value);

  // optional float y = 2;
  inline bool has_y() const;
  inline void clear_y();
  static const int kYFieldNumber = 2;
  inline float y() const;
  inline void set_y(float value);

  // @@protoc_insertion_point(class_scope:common.Vector2)
 private:
  inline void set_has_x();
  inline void clear_has_x();
  inline void set_has_y();
  inline void clear_has_y();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  float x_;
  float y_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_common_2eproto();
  friend void protobuf_AssignDesc_common_2eproto();
  friend void protobuf_ShutdownFile_common_2eproto();

  void InitAsDefaultInstance();
  static Vector2* default_instance_;
};
// -------------------------------------------------------------------

class Vector3 : public ::google::protobuf::Message {
 public:
  Vector3();
  virtual ~Vector3();

  Vector3(const Vector3& from);

  inline Vector3& operator=(const Vector3& from) {
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
  static const Vector3& default_instance();

  void Swap(Vector3* other);

  // implements Message ----------------------------------------------

  Vector3* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Vector3& from);
  void MergeFrom(const Vector3& from);
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

  // optional float x = 1;
  inline bool has_x() const;
  inline void clear_x();
  static const int kXFieldNumber = 1;
  inline float x() const;
  inline void set_x(float value);

  // optional float y = 2;
  inline bool has_y() const;
  inline void clear_y();
  static const int kYFieldNumber = 2;
  inline float y() const;
  inline void set_y(float value);

  // optional float z = 3;
  inline bool has_z() const;
  inline void clear_z();
  static const int kZFieldNumber = 3;
  inline float z() const;
  inline void set_z(float value);

  // @@protoc_insertion_point(class_scope:common.Vector3)
 private:
  inline void set_has_x();
  inline void clear_has_x();
  inline void set_has_y();
  inline void clear_has_y();
  inline void set_has_z();
  inline void clear_has_z();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  float x_;
  float y_;
  float z_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_common_2eproto();
  friend void protobuf_AssignDesc_common_2eproto();
  friend void protobuf_ShutdownFile_common_2eproto();

  void InitAsDefaultInstance();
  static Vector3* default_instance_;
};
// -------------------------------------------------------------------

class Vector4 : public ::google::protobuf::Message {
 public:
  Vector4();
  virtual ~Vector4();

  Vector4(const Vector4& from);

  inline Vector4& operator=(const Vector4& from) {
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
  static const Vector4& default_instance();

  void Swap(Vector4* other);

  // implements Message ----------------------------------------------

  Vector4* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Vector4& from);
  void MergeFrom(const Vector4& from);
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

  // optional float x = 1;
  inline bool has_x() const;
  inline void clear_x();
  static const int kXFieldNumber = 1;
  inline float x() const;
  inline void set_x(float value);

  // optional float y = 2;
  inline bool has_y() const;
  inline void clear_y();
  static const int kYFieldNumber = 2;
  inline float y() const;
  inline void set_y(float value);

  // optional float z = 3;
  inline bool has_z() const;
  inline void clear_z();
  static const int kZFieldNumber = 3;
  inline float z() const;
  inline void set_z(float value);

  // optional float w = 4;
  inline bool has_w() const;
  inline void clear_w();
  static const int kWFieldNumber = 4;
  inline float w() const;
  inline void set_w(float value);

  // @@protoc_insertion_point(class_scope:common.Vector4)
 private:
  inline void set_has_x();
  inline void clear_has_x();
  inline void set_has_y();
  inline void clear_has_y();
  inline void set_has_z();
  inline void clear_has_z();
  inline void set_has_w();
  inline void clear_has_w();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  float x_;
  float y_;
  float z_;
  float w_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];

  friend void  protobuf_AddDesc_common_2eproto();
  friend void protobuf_AssignDesc_common_2eproto();
  friend void protobuf_ShutdownFile_common_2eproto();

  void InitAsDefaultInstance();
  static Vector4* default_instance_;
};
// -------------------------------------------------------------------

class Matrix3x3 : public ::google::protobuf::Message {
 public:
  Matrix3x3();
  virtual ~Matrix3x3();

  Matrix3x3(const Matrix3x3& from);

  inline Matrix3x3& operator=(const Matrix3x3& from) {
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
  static const Matrix3x3& default_instance();

  void Swap(Matrix3x3* other);

  // implements Message ----------------------------------------------

  Matrix3x3* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Matrix3x3& from);
  void MergeFrom(const Matrix3x3& from);
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

  // optional .common.Vector3 row_1 = 1;
  inline bool has_row_1() const;
  inline void clear_row_1();
  static const int kRow1FieldNumber = 1;
  inline const ::common::Vector3& row_1() const;
  inline ::common::Vector3* mutable_row_1();
  inline ::common::Vector3* release_row_1();
  inline void set_allocated_row_1(::common::Vector3* row_1);

  // optional .common.Vector3 row_2 = 2;
  inline bool has_row_2() const;
  inline void clear_row_2();
  static const int kRow2FieldNumber = 2;
  inline const ::common::Vector3& row_2() const;
  inline ::common::Vector3* mutable_row_2();
  inline ::common::Vector3* release_row_2();
  inline void set_allocated_row_2(::common::Vector3* row_2);

  // optional .common.Vector3 row_3 = 3;
  inline bool has_row_3() const;
  inline void clear_row_3();
  static const int kRow3FieldNumber = 3;
  inline const ::common::Vector3& row_3() const;
  inline ::common::Vector3* mutable_row_3();
  inline ::common::Vector3* release_row_3();
  inline void set_allocated_row_3(::common::Vector3* row_3);

  // @@protoc_insertion_point(class_scope:common.Matrix3x3)
 private:
  inline void set_has_row_1();
  inline void clear_has_row_1();
  inline void set_has_row_2();
  inline void clear_has_row_2();
  inline void set_has_row_3();
  inline void clear_has_row_3();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::common::Vector3* row_1_;
  ::common::Vector3* row_2_;
  ::common::Vector3* row_3_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_common_2eproto();
  friend void protobuf_AssignDesc_common_2eproto();
  friend void protobuf_ShutdownFile_common_2eproto();

  void InitAsDefaultInstance();
  static Matrix3x3* default_instance_;
};
// -------------------------------------------------------------------

class Matrix4x4 : public ::google::protobuf::Message {
 public:
  Matrix4x4();
  virtual ~Matrix4x4();

  Matrix4x4(const Matrix4x4& from);

  inline Matrix4x4& operator=(const Matrix4x4& from) {
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
  static const Matrix4x4& default_instance();

  void Swap(Matrix4x4* other);

  // implements Message ----------------------------------------------

  Matrix4x4* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Matrix4x4& from);
  void MergeFrom(const Matrix4x4& from);
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

  // optional .common.Vector4 row_1 = 1;
  inline bool has_row_1() const;
  inline void clear_row_1();
  static const int kRow1FieldNumber = 1;
  inline const ::common::Vector4& row_1() const;
  inline ::common::Vector4* mutable_row_1();
  inline ::common::Vector4* release_row_1();
  inline void set_allocated_row_1(::common::Vector4* row_1);

  // optional .common.Vector4 row_2 = 2;
  inline bool has_row_2() const;
  inline void clear_row_2();
  static const int kRow2FieldNumber = 2;
  inline const ::common::Vector4& row_2() const;
  inline ::common::Vector4* mutable_row_2();
  inline ::common::Vector4* release_row_2();
  inline void set_allocated_row_2(::common::Vector4* row_2);

  // optional .common.Vector4 row_3 = 3;
  inline bool has_row_3() const;
  inline void clear_row_3();
  static const int kRow3FieldNumber = 3;
  inline const ::common::Vector4& row_3() const;
  inline ::common::Vector4* mutable_row_3();
  inline ::common::Vector4* release_row_3();
  inline void set_allocated_row_3(::common::Vector4* row_3);

  // optional .common.Vector4 row_4 = 4;
  inline bool has_row_4() const;
  inline void clear_row_4();
  static const int kRow4FieldNumber = 4;
  inline const ::common::Vector4& row_4() const;
  inline ::common::Vector4* mutable_row_4();
  inline ::common::Vector4* release_row_4();
  inline void set_allocated_row_4(::common::Vector4* row_4);

  // @@protoc_insertion_point(class_scope:common.Matrix4x4)
 private:
  inline void set_has_row_1();
  inline void clear_has_row_1();
  inline void set_has_row_2();
  inline void clear_has_row_2();
  inline void set_has_row_3();
  inline void clear_has_row_3();
  inline void set_has_row_4();
  inline void clear_has_row_4();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::common::Vector4* row_1_;
  ::common::Vector4* row_2_;
  ::common::Vector4* row_3_;
  ::common::Vector4* row_4_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];

  friend void  protobuf_AddDesc_common_2eproto();
  friend void protobuf_AssignDesc_common_2eproto();
  friend void protobuf_ShutdownFile_common_2eproto();

  void InitAsDefaultInstance();
  static Matrix4x4* default_instance_;
};
// ===================================================================


// ===================================================================

// Vector2

// optional float x = 1;
inline bool Vector2::has_x() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Vector2::set_has_x() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Vector2::clear_has_x() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Vector2::clear_x() {
  x_ = 0;
  clear_has_x();
}
inline float Vector2::x() const {
  return x_;
}
inline void Vector2::set_x(float value) {
  set_has_x();
  x_ = value;
}

// optional float y = 2;
inline bool Vector2::has_y() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Vector2::set_has_y() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Vector2::clear_has_y() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Vector2::clear_y() {
  y_ = 0;
  clear_has_y();
}
inline float Vector2::y() const {
  return y_;
}
inline void Vector2::set_y(float value) {
  set_has_y();
  y_ = value;
}

// -------------------------------------------------------------------

// Vector3

// optional float x = 1;
inline bool Vector3::has_x() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Vector3::set_has_x() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Vector3::clear_has_x() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Vector3::clear_x() {
  x_ = 0;
  clear_has_x();
}
inline float Vector3::x() const {
  return x_;
}
inline void Vector3::set_x(float value) {
  set_has_x();
  x_ = value;
}

// optional float y = 2;
inline bool Vector3::has_y() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Vector3::set_has_y() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Vector3::clear_has_y() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Vector3::clear_y() {
  y_ = 0;
  clear_has_y();
}
inline float Vector3::y() const {
  return y_;
}
inline void Vector3::set_y(float value) {
  set_has_y();
  y_ = value;
}

// optional float z = 3;
inline bool Vector3::has_z() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Vector3::set_has_z() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Vector3::clear_has_z() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Vector3::clear_z() {
  z_ = 0;
  clear_has_z();
}
inline float Vector3::z() const {
  return z_;
}
inline void Vector3::set_z(float value) {
  set_has_z();
  z_ = value;
}

// -------------------------------------------------------------------

// Vector4

// optional float x = 1;
inline bool Vector4::has_x() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Vector4::set_has_x() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Vector4::clear_has_x() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Vector4::clear_x() {
  x_ = 0;
  clear_has_x();
}
inline float Vector4::x() const {
  return x_;
}
inline void Vector4::set_x(float value) {
  set_has_x();
  x_ = value;
}

// optional float y = 2;
inline bool Vector4::has_y() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Vector4::set_has_y() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Vector4::clear_has_y() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Vector4::clear_y() {
  y_ = 0;
  clear_has_y();
}
inline float Vector4::y() const {
  return y_;
}
inline void Vector4::set_y(float value) {
  set_has_y();
  y_ = value;
}

// optional float z = 3;
inline bool Vector4::has_z() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Vector4::set_has_z() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Vector4::clear_has_z() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Vector4::clear_z() {
  z_ = 0;
  clear_has_z();
}
inline float Vector4::z() const {
  return z_;
}
inline void Vector4::set_z(float value) {
  set_has_z();
  z_ = value;
}

// optional float w = 4;
inline bool Vector4::has_w() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Vector4::set_has_w() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Vector4::clear_has_w() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Vector4::clear_w() {
  w_ = 0;
  clear_has_w();
}
inline float Vector4::w() const {
  return w_;
}
inline void Vector4::set_w(float value) {
  set_has_w();
  w_ = value;
}

// -------------------------------------------------------------------

// Matrix3x3

// optional .common.Vector3 row_1 = 1;
inline bool Matrix3x3::has_row_1() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Matrix3x3::set_has_row_1() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Matrix3x3::clear_has_row_1() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Matrix3x3::clear_row_1() {
  if (row_1_ != NULL) row_1_->::common::Vector3::Clear();
  clear_has_row_1();
}
inline const ::common::Vector3& Matrix3x3::row_1() const {
  return row_1_ != NULL ? *row_1_ : *default_instance_->row_1_;
}
inline ::common::Vector3* Matrix3x3::mutable_row_1() {
  set_has_row_1();
  if (row_1_ == NULL) row_1_ = new ::common::Vector3;
  return row_1_;
}
inline ::common::Vector3* Matrix3x3::release_row_1() {
  clear_has_row_1();
  ::common::Vector3* temp = row_1_;
  row_1_ = NULL;
  return temp;
}
inline void Matrix3x3::set_allocated_row_1(::common::Vector3* row_1) {
  delete row_1_;
  row_1_ = row_1;
  if (row_1) {
    set_has_row_1();
  } else {
    clear_has_row_1();
  }
}

// optional .common.Vector3 row_2 = 2;
inline bool Matrix3x3::has_row_2() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Matrix3x3::set_has_row_2() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Matrix3x3::clear_has_row_2() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Matrix3x3::clear_row_2() {
  if (row_2_ != NULL) row_2_->::common::Vector3::Clear();
  clear_has_row_2();
}
inline const ::common::Vector3& Matrix3x3::row_2() const {
  return row_2_ != NULL ? *row_2_ : *default_instance_->row_2_;
}
inline ::common::Vector3* Matrix3x3::mutable_row_2() {
  set_has_row_2();
  if (row_2_ == NULL) row_2_ = new ::common::Vector3;
  return row_2_;
}
inline ::common::Vector3* Matrix3x3::release_row_2() {
  clear_has_row_2();
  ::common::Vector3* temp = row_2_;
  row_2_ = NULL;
  return temp;
}
inline void Matrix3x3::set_allocated_row_2(::common::Vector3* row_2) {
  delete row_2_;
  row_2_ = row_2;
  if (row_2) {
    set_has_row_2();
  } else {
    clear_has_row_2();
  }
}

// optional .common.Vector3 row_3 = 3;
inline bool Matrix3x3::has_row_3() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Matrix3x3::set_has_row_3() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Matrix3x3::clear_has_row_3() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Matrix3x3::clear_row_3() {
  if (row_3_ != NULL) row_3_->::common::Vector3::Clear();
  clear_has_row_3();
}
inline const ::common::Vector3& Matrix3x3::row_3() const {
  return row_3_ != NULL ? *row_3_ : *default_instance_->row_3_;
}
inline ::common::Vector3* Matrix3x3::mutable_row_3() {
  set_has_row_3();
  if (row_3_ == NULL) row_3_ = new ::common::Vector3;
  return row_3_;
}
inline ::common::Vector3* Matrix3x3::release_row_3() {
  clear_has_row_3();
  ::common::Vector3* temp = row_3_;
  row_3_ = NULL;
  return temp;
}
inline void Matrix3x3::set_allocated_row_3(::common::Vector3* row_3) {
  delete row_3_;
  row_3_ = row_3;
  if (row_3) {
    set_has_row_3();
  } else {
    clear_has_row_3();
  }
}

// -------------------------------------------------------------------

// Matrix4x4

// optional .common.Vector4 row_1 = 1;
inline bool Matrix4x4::has_row_1() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Matrix4x4::set_has_row_1() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Matrix4x4::clear_has_row_1() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Matrix4x4::clear_row_1() {
  if (row_1_ != NULL) row_1_->::common::Vector4::Clear();
  clear_has_row_1();
}
inline const ::common::Vector4& Matrix4x4::row_1() const {
  return row_1_ != NULL ? *row_1_ : *default_instance_->row_1_;
}
inline ::common::Vector4* Matrix4x4::mutable_row_1() {
  set_has_row_1();
  if (row_1_ == NULL) row_1_ = new ::common::Vector4;
  return row_1_;
}
inline ::common::Vector4* Matrix4x4::release_row_1() {
  clear_has_row_1();
  ::common::Vector4* temp = row_1_;
  row_1_ = NULL;
  return temp;
}
inline void Matrix4x4::set_allocated_row_1(::common::Vector4* row_1) {
  delete row_1_;
  row_1_ = row_1;
  if (row_1) {
    set_has_row_1();
  } else {
    clear_has_row_1();
  }
}

// optional .common.Vector4 row_2 = 2;
inline bool Matrix4x4::has_row_2() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Matrix4x4::set_has_row_2() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Matrix4x4::clear_has_row_2() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Matrix4x4::clear_row_2() {
  if (row_2_ != NULL) row_2_->::common::Vector4::Clear();
  clear_has_row_2();
}
inline const ::common::Vector4& Matrix4x4::row_2() const {
  return row_2_ != NULL ? *row_2_ : *default_instance_->row_2_;
}
inline ::common::Vector4* Matrix4x4::mutable_row_2() {
  set_has_row_2();
  if (row_2_ == NULL) row_2_ = new ::common::Vector4;
  return row_2_;
}
inline ::common::Vector4* Matrix4x4::release_row_2() {
  clear_has_row_2();
  ::common::Vector4* temp = row_2_;
  row_2_ = NULL;
  return temp;
}
inline void Matrix4x4::set_allocated_row_2(::common::Vector4* row_2) {
  delete row_2_;
  row_2_ = row_2;
  if (row_2) {
    set_has_row_2();
  } else {
    clear_has_row_2();
  }
}

// optional .common.Vector4 row_3 = 3;
inline bool Matrix4x4::has_row_3() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Matrix4x4::set_has_row_3() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Matrix4x4::clear_has_row_3() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Matrix4x4::clear_row_3() {
  if (row_3_ != NULL) row_3_->::common::Vector4::Clear();
  clear_has_row_3();
}
inline const ::common::Vector4& Matrix4x4::row_3() const {
  return row_3_ != NULL ? *row_3_ : *default_instance_->row_3_;
}
inline ::common::Vector4* Matrix4x4::mutable_row_3() {
  set_has_row_3();
  if (row_3_ == NULL) row_3_ = new ::common::Vector4;
  return row_3_;
}
inline ::common::Vector4* Matrix4x4::release_row_3() {
  clear_has_row_3();
  ::common::Vector4* temp = row_3_;
  row_3_ = NULL;
  return temp;
}
inline void Matrix4x4::set_allocated_row_3(::common::Vector4* row_3) {
  delete row_3_;
  row_3_ = row_3;
  if (row_3) {
    set_has_row_3();
  } else {
    clear_has_row_3();
  }
}

// optional .common.Vector4 row_4 = 4;
inline bool Matrix4x4::has_row_4() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Matrix4x4::set_has_row_4() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Matrix4x4::clear_has_row_4() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Matrix4x4::clear_row_4() {
  if (row_4_ != NULL) row_4_->::common::Vector4::Clear();
  clear_has_row_4();
}
inline const ::common::Vector4& Matrix4x4::row_4() const {
  return row_4_ != NULL ? *row_4_ : *default_instance_->row_4_;
}
inline ::common::Vector4* Matrix4x4::mutable_row_4() {
  set_has_row_4();
  if (row_4_ == NULL) row_4_ = new ::common::Vector4;
  return row_4_;
}
inline ::common::Vector4* Matrix4x4::release_row_4() {
  clear_has_row_4();
  ::common::Vector4* temp = row_4_;
  row_4_ = NULL;
  return temp;
}
inline void Matrix4x4::set_allocated_row_4(::common::Vector4* row_4) {
  delete row_4_;
  row_4_ = row_4;
  if (row_4) {
    set_has_row_4();
  } else {
    clear_has_row_4();
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace common

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_common_2eproto__INCLUDED