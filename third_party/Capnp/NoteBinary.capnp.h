// Generated by Cap'n Proto compiler, DO NOT EDIT
// source: NoteBinary.capnp

#pragma once

#include <capnp/generated-header-support.h>
#include <kj/windows-sanity.h>

#ifndef CAPNP_VERSION
#error "CAPNP_VERSION is not defined, is capnp/generated-header-support.h missing?"
#elif CAPNP_VERSION != 1001000
#error "Version mismatch between generated code and library headers.  You must use the same version of the Cap'n Proto compiler and library."
#endif


CAPNP_BEGIN_HEADER

namespace capnp {
namespace schemas {

CAPNP_DECLARE_SCHEMA(ac7829f65c77223e);
CAPNP_DECLARE_SCHEMA(bf97262342af491e);

}  // namespace schemas
}  // namespace capnp


struct NoteBinaryData {
  NoteBinaryData() = delete;

  class Reader;
  class Builder;
  class Pipeline;

  struct _capnpPrivate {
    CAPNP_DECLARE_STRUCT_HEADER(ac7829f65c77223e, 6, 5)
    #if !CAPNP_LITE
    static constexpr ::capnp::_::RawBrandedSchema const* brand() { return &schema->defaultBrand; }
    #endif  // !CAPNP_LITE
  };
};

struct NoteBinaryCapnpData {
  NoteBinaryCapnpData() = delete;

  class Reader;
  class Builder;
  class Pipeline;

  struct _capnpPrivate {
    CAPNP_DECLARE_STRUCT_HEADER(bf97262342af491e, 0, 1)
    #if !CAPNP_LITE
    static constexpr ::capnp::_::RawBrandedSchema const* brand() { return &schema->defaultBrand; }
    #endif  // !CAPNP_LITE
  };
};

// =======================================================================================

class NoteBinaryData::Reader {
public:
  typedef NoteBinaryData Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline ::capnp::MessageSize totalSize() const {
    return _reader.totalSize().asPublic();
  }

#if !CAPNP_LITE
  inline ::kj::StringTree toString() const {
    return ::capnp::_::structString(_reader, *_capnpPrivate::brand());
  }
#endif  // !CAPNP_LITE

  inline bool hasNoteType() const;
  inline  ::capnp::Text::Reader getNoteType() const;

  inline bool hasNoteDetail() const;
  inline  ::capnp::Text::Reader getNoteDetail() const;

  inline bool hasFirst() const;
  inline  ::capnp::Text::Reader getFirst() const;

  inline bool hasSecond() const;
  inline  ::capnp::Text::Reader getSecond() const;

  inline bool hasThird() const;
  inline  ::capnp::Text::Reader getThird() const;

  inline  ::int64_t getBar() const;

  inline  ::int64_t getBeat() const;

  inline  ::int64_t getSeparate() const;

  inline  ::int64_t getEBar() const;

  inline  ::int64_t getEBeat() const;

  inline  ::int64_t getESeparate() const;

private:
  ::capnp::_::StructReader _reader;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::List;
  friend class ::capnp::MessageBuilder;
  friend class ::capnp::Orphanage;
};

class NoteBinaryData::Builder {
public:
  typedef NoteBinaryData Builds;

  Builder() = delete;  // Deleted to discourage incorrect usage.
                       // You can explicitly initialize to nullptr instead.
  inline Builder(decltype(nullptr)) {}
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline ::capnp::MessageSize totalSize() const { return asReader().totalSize(); }
#if !CAPNP_LITE
  inline ::kj::StringTree toString() const { return asReader().toString(); }
#endif  // !CAPNP_LITE

  inline bool hasNoteType();
  inline  ::capnp::Text::Builder getNoteType();
  inline void setNoteType( ::capnp::Text::Reader value);
  inline  ::capnp::Text::Builder initNoteType(unsigned int size);
  inline void adoptNoteType(::capnp::Orphan< ::capnp::Text>&& value);
  inline ::capnp::Orphan< ::capnp::Text> disownNoteType();

  inline bool hasNoteDetail();
  inline  ::capnp::Text::Builder getNoteDetail();
  inline void setNoteDetail( ::capnp::Text::Reader value);
  inline  ::capnp::Text::Builder initNoteDetail(unsigned int size);
  inline void adoptNoteDetail(::capnp::Orphan< ::capnp::Text>&& value);
  inline ::capnp::Orphan< ::capnp::Text> disownNoteDetail();

  inline bool hasFirst();
  inline  ::capnp::Text::Builder getFirst();
  inline void setFirst( ::capnp::Text::Reader value);
  inline  ::capnp::Text::Builder initFirst(unsigned int size);
  inline void adoptFirst(::capnp::Orphan< ::capnp::Text>&& value);
  inline ::capnp::Orphan< ::capnp::Text> disownFirst();

  inline bool hasSecond();
  inline  ::capnp::Text::Builder getSecond();
  inline void setSecond( ::capnp::Text::Reader value);
  inline  ::capnp::Text::Builder initSecond(unsigned int size);
  inline void adoptSecond(::capnp::Orphan< ::capnp::Text>&& value);
  inline ::capnp::Orphan< ::capnp::Text> disownSecond();

  inline bool hasThird();
  inline  ::capnp::Text::Builder getThird();
  inline void setThird( ::capnp::Text::Reader value);
  inline  ::capnp::Text::Builder initThird(unsigned int size);
  inline void adoptThird(::capnp::Orphan< ::capnp::Text>&& value);
  inline ::capnp::Orphan< ::capnp::Text> disownThird();

  inline  ::int64_t getBar();
  inline void setBar( ::int64_t value);

  inline  ::int64_t getBeat();
  inline void setBeat( ::int64_t value);

  inline  ::int64_t getSeparate();
  inline void setSeparate( ::int64_t value);

  inline  ::int64_t getEBar();
  inline void setEBar( ::int64_t value);

  inline  ::int64_t getEBeat();
  inline void setEBeat( ::int64_t value);

  inline  ::int64_t getESeparate();
  inline void setESeparate( ::int64_t value);

private:
  ::capnp::_::StructBuilder _builder;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  friend class ::capnp::Orphanage;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
};

#if !CAPNP_LITE
class NoteBinaryData::Pipeline {
public:
  typedef NoteBinaryData Pipelines;

  inline Pipeline(decltype(nullptr)): _typeless(nullptr) {}
  inline explicit Pipeline(::capnp::AnyPointer::Pipeline&& typeless)
      : _typeless(kj::mv(typeless)) {}

private:
  ::capnp::AnyPointer::Pipeline _typeless;
  friend class ::capnp::PipelineHook;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
};
#endif  // !CAPNP_LITE

class NoteBinaryCapnpData::Reader {
public:
  typedef NoteBinaryCapnpData Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline ::capnp::MessageSize totalSize() const {
    return _reader.totalSize().asPublic();
  }

#if !CAPNP_LITE
  inline ::kj::StringTree toString() const {
    return ::capnp::_::structString(_reader, *_capnpPrivate::brand());
  }
#endif  // !CAPNP_LITE

  inline bool hasDatas() const;
  inline  ::capnp::List< ::NoteBinaryData,  ::capnp::Kind::STRUCT>::Reader getDatas() const;

private:
  ::capnp::_::StructReader _reader;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::List;
  friend class ::capnp::MessageBuilder;
  friend class ::capnp::Orphanage;
};

class NoteBinaryCapnpData::Builder {
public:
  typedef NoteBinaryCapnpData Builds;

  Builder() = delete;  // Deleted to discourage incorrect usage.
                       // You can explicitly initialize to nullptr instead.
  inline Builder(decltype(nullptr)) {}
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline ::capnp::MessageSize totalSize() const { return asReader().totalSize(); }
#if !CAPNP_LITE
  inline ::kj::StringTree toString() const { return asReader().toString(); }
#endif  // !CAPNP_LITE

  inline bool hasDatas();
  inline  ::capnp::List< ::NoteBinaryData,  ::capnp::Kind::STRUCT>::Builder getDatas();
  inline void setDatas( ::capnp::List< ::NoteBinaryData,  ::capnp::Kind::STRUCT>::Reader value);
  inline  ::capnp::List< ::NoteBinaryData,  ::capnp::Kind::STRUCT>::Builder initDatas(unsigned int size);
  inline void adoptDatas(::capnp::Orphan< ::capnp::List< ::NoteBinaryData,  ::capnp::Kind::STRUCT>>&& value);
  inline ::capnp::Orphan< ::capnp::List< ::NoteBinaryData,  ::capnp::Kind::STRUCT>> disownDatas();

private:
  ::capnp::_::StructBuilder _builder;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  friend class ::capnp::Orphanage;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
};

#if !CAPNP_LITE
class NoteBinaryCapnpData::Pipeline {
public:
  typedef NoteBinaryCapnpData Pipelines;

  inline Pipeline(decltype(nullptr)): _typeless(nullptr) {}
  inline explicit Pipeline(::capnp::AnyPointer::Pipeline&& typeless)
      : _typeless(kj::mv(typeless)) {}

private:
  ::capnp::AnyPointer::Pipeline _typeless;
  friend class ::capnp::PipelineHook;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
};
#endif  // !CAPNP_LITE

// =======================================================================================

inline bool NoteBinaryData::Reader::hasNoteType() const {
  return !_reader.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS).isNull();
}
inline bool NoteBinaryData::Builder::hasNoteType() {
  return !_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::Text::Reader NoteBinaryData::Reader::getNoteType() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_reader.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
inline  ::capnp::Text::Builder NoteBinaryData::Builder::getNoteType() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
inline void NoteBinaryData::Builder::setNoteType( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), value);
}
inline  ::capnp::Text::Builder NoteBinaryData::Builder::initNoteType(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), size);
}
inline void NoteBinaryData::Builder::adoptNoteType(
    ::capnp::Orphan< ::capnp::Text>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::adopt(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::Text> NoteBinaryData::Builder::disownNoteType() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::disown(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}

inline bool NoteBinaryData::Reader::hasNoteDetail() const {
  return !_reader.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS).isNull();
}
inline bool NoteBinaryData::Builder::hasNoteDetail() {
  return !_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::Text::Reader NoteBinaryData::Reader::getNoteDetail() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_reader.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS));
}
inline  ::capnp::Text::Builder NoteBinaryData::Builder::getNoteDetail() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS));
}
inline void NoteBinaryData::Builder::setNoteDetail( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS), value);
}
inline  ::capnp::Text::Builder NoteBinaryData::Builder::initNoteDetail(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS), size);
}
inline void NoteBinaryData::Builder::adoptNoteDetail(
    ::capnp::Orphan< ::capnp::Text>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::adopt(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::Text> NoteBinaryData::Builder::disownNoteDetail() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::disown(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS));
}

inline bool NoteBinaryData::Reader::hasFirst() const {
  return !_reader.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS).isNull();
}
inline bool NoteBinaryData::Builder::hasFirst() {
  return !_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::Text::Reader NoteBinaryData::Reader::getFirst() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_reader.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS));
}
inline  ::capnp::Text::Builder NoteBinaryData::Builder::getFirst() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS));
}
inline void NoteBinaryData::Builder::setFirst( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS), value);
}
inline  ::capnp::Text::Builder NoteBinaryData::Builder::initFirst(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS), size);
}
inline void NoteBinaryData::Builder::adoptFirst(
    ::capnp::Orphan< ::capnp::Text>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::adopt(_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::Text> NoteBinaryData::Builder::disownFirst() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::disown(_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS));
}

inline bool NoteBinaryData::Reader::hasSecond() const {
  return !_reader.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS).isNull();
}
inline bool NoteBinaryData::Builder::hasSecond() {
  return !_builder.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::Text::Reader NoteBinaryData::Reader::getSecond() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_reader.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS));
}
inline  ::capnp::Text::Builder NoteBinaryData::Builder::getSecond() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_builder.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS));
}
inline void NoteBinaryData::Builder::setSecond( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(_builder.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS), value);
}
inline  ::capnp::Text::Builder NoteBinaryData::Builder::initSecond(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(_builder.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS), size);
}
inline void NoteBinaryData::Builder::adoptSecond(
    ::capnp::Orphan< ::capnp::Text>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::adopt(_builder.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::Text> NoteBinaryData::Builder::disownSecond() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::disown(_builder.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS));
}

inline bool NoteBinaryData::Reader::hasThird() const {
  return !_reader.getPointerField(
      ::capnp::bounded<4>() * ::capnp::POINTERS).isNull();
}
inline bool NoteBinaryData::Builder::hasThird() {
  return !_builder.getPointerField(
      ::capnp::bounded<4>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::Text::Reader NoteBinaryData::Reader::getThird() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_reader.getPointerField(
      ::capnp::bounded<4>() * ::capnp::POINTERS));
}
inline  ::capnp::Text::Builder NoteBinaryData::Builder::getThird() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_builder.getPointerField(
      ::capnp::bounded<4>() * ::capnp::POINTERS));
}
inline void NoteBinaryData::Builder::setThird( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(_builder.getPointerField(
      ::capnp::bounded<4>() * ::capnp::POINTERS), value);
}
inline  ::capnp::Text::Builder NoteBinaryData::Builder::initThird(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(_builder.getPointerField(
      ::capnp::bounded<4>() * ::capnp::POINTERS), size);
}
inline void NoteBinaryData::Builder::adoptThird(
    ::capnp::Orphan< ::capnp::Text>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::adopt(_builder.getPointerField(
      ::capnp::bounded<4>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::Text> NoteBinaryData::Builder::disownThird() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::disown(_builder.getPointerField(
      ::capnp::bounded<4>() * ::capnp::POINTERS));
}

inline  ::int64_t NoteBinaryData::Reader::getBar() const {
  return _reader.getDataField< ::int64_t>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS);
}

inline  ::int64_t NoteBinaryData::Builder::getBar() {
  return _builder.getDataField< ::int64_t>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS);
}
inline void NoteBinaryData::Builder::setBar( ::int64_t value) {
  _builder.setDataField< ::int64_t>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS, value);
}

inline  ::int64_t NoteBinaryData::Reader::getBeat() const {
  return _reader.getDataField< ::int64_t>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS);
}

inline  ::int64_t NoteBinaryData::Builder::getBeat() {
  return _builder.getDataField< ::int64_t>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS);
}
inline void NoteBinaryData::Builder::setBeat( ::int64_t value) {
  _builder.setDataField< ::int64_t>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS, value);
}

inline  ::int64_t NoteBinaryData::Reader::getSeparate() const {
  return _reader.getDataField< ::int64_t>(
      ::capnp::bounded<2>() * ::capnp::ELEMENTS);
}

inline  ::int64_t NoteBinaryData::Builder::getSeparate() {
  return _builder.getDataField< ::int64_t>(
      ::capnp::bounded<2>() * ::capnp::ELEMENTS);
}
inline void NoteBinaryData::Builder::setSeparate( ::int64_t value) {
  _builder.setDataField< ::int64_t>(
      ::capnp::bounded<2>() * ::capnp::ELEMENTS, value);
}

inline  ::int64_t NoteBinaryData::Reader::getEBar() const {
  return _reader.getDataField< ::int64_t>(
      ::capnp::bounded<3>() * ::capnp::ELEMENTS);
}

inline  ::int64_t NoteBinaryData::Builder::getEBar() {
  return _builder.getDataField< ::int64_t>(
      ::capnp::bounded<3>() * ::capnp::ELEMENTS);
}
inline void NoteBinaryData::Builder::setEBar( ::int64_t value) {
  _builder.setDataField< ::int64_t>(
      ::capnp::bounded<3>() * ::capnp::ELEMENTS, value);
}

inline  ::int64_t NoteBinaryData::Reader::getEBeat() const {
  return _reader.getDataField< ::int64_t>(
      ::capnp::bounded<4>() * ::capnp::ELEMENTS);
}

inline  ::int64_t NoteBinaryData::Builder::getEBeat() {
  return _builder.getDataField< ::int64_t>(
      ::capnp::bounded<4>() * ::capnp::ELEMENTS);
}
inline void NoteBinaryData::Builder::setEBeat( ::int64_t value) {
  _builder.setDataField< ::int64_t>(
      ::capnp::bounded<4>() * ::capnp::ELEMENTS, value);
}

inline  ::int64_t NoteBinaryData::Reader::getESeparate() const {
  return _reader.getDataField< ::int64_t>(
      ::capnp::bounded<5>() * ::capnp::ELEMENTS);
}

inline  ::int64_t NoteBinaryData::Builder::getESeparate() {
  return _builder.getDataField< ::int64_t>(
      ::capnp::bounded<5>() * ::capnp::ELEMENTS);
}
inline void NoteBinaryData::Builder::setESeparate( ::int64_t value) {
  _builder.setDataField< ::int64_t>(
      ::capnp::bounded<5>() * ::capnp::ELEMENTS, value);
}

inline bool NoteBinaryCapnpData::Reader::hasDatas() const {
  return !_reader.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS).isNull();
}
inline bool NoteBinaryCapnpData::Builder::hasDatas() {
  return !_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::List< ::NoteBinaryData,  ::capnp::Kind::STRUCT>::Reader NoteBinaryCapnpData::Reader::getDatas() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::NoteBinaryData,  ::capnp::Kind::STRUCT>>::get(_reader.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
inline  ::capnp::List< ::NoteBinaryData,  ::capnp::Kind::STRUCT>::Builder NoteBinaryCapnpData::Builder::getDatas() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::NoteBinaryData,  ::capnp::Kind::STRUCT>>::get(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
inline void NoteBinaryCapnpData::Builder::setDatas( ::capnp::List< ::NoteBinaryData,  ::capnp::Kind::STRUCT>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::NoteBinaryData,  ::capnp::Kind::STRUCT>>::set(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), value);
}
inline  ::capnp::List< ::NoteBinaryData,  ::capnp::Kind::STRUCT>::Builder NoteBinaryCapnpData::Builder::initDatas(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::NoteBinaryData,  ::capnp::Kind::STRUCT>>::init(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), size);
}
inline void NoteBinaryCapnpData::Builder::adoptDatas(
    ::capnp::Orphan< ::capnp::List< ::NoteBinaryData,  ::capnp::Kind::STRUCT>>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::NoteBinaryData,  ::capnp::Kind::STRUCT>>::adopt(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::List< ::NoteBinaryData,  ::capnp::Kind::STRUCT>> NoteBinaryCapnpData::Builder::disownDatas() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::NoteBinaryData,  ::capnp::Kind::STRUCT>>::disown(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}


CAPNP_END_HEADER

