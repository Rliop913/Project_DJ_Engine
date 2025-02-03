// Generated by Cap'n Proto compiler, DO NOT EDIT
// source: MixBinary.capnp

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

CAPNP_DECLARE_SCHEMA(f4ee4873bc65f8f0);
enum class TypeEnum_f4ee4873bc65f8f0: uint16_t {
  FILTER,
  EQ,
  DISTORTION,
  CONTROL,
  VOL,
  LOAD,
  UNLOAD,
  BPM_CONTROL,
  ECHO,
  OSC_FILTER,
  FLANGER,
  PHASER,
  TRANCE,
  PANNER,
  BATTLE_DJ,
  ROLL,
  COMPRESSOR,
};
CAPNP_DECLARE_ENUM(TypeEnum, f4ee4873bc65f8f0);
CAPNP_DECLARE_SCHEMA(c6c88c32e11afb23);
enum class DetailEnum_c6c88c32e11afb23: uint16_t {
  HIGH,
  MID,
  LOW,
  PAUSE,
  CUE,
  TRIM,
  FADER,
  TIME_STRETCH,
  SPIN,
  PITCH,
  REV,
  SCRATCH,
  BSCRATCH,
};
CAPNP_DECLARE_ENUM(DetailEnum, c6c88c32e11afb23);
CAPNP_DECLARE_SCHEMA(83f21337c383e938);
CAPNP_DECLARE_SCHEMA(9ba477d42ac52fd4);

}  // namespace schemas
}  // namespace capnp


typedef ::capnp::schemas::TypeEnum_f4ee4873bc65f8f0 TypeEnum;

typedef ::capnp::schemas::DetailEnum_c6c88c32e11afb23 DetailEnum;

struct MBData {
  MBData() = delete;

  class Reader;
  class Builder;
  class Pipeline;

  struct _capnpPrivate {
    CAPNP_DECLARE_STRUCT_HEADER(83f21337c383e938, 7, 3)
    #if !CAPNP_LITE
    static constexpr ::capnp::_::RawBrandedSchema const* brand() { return &schema->defaultBrand; }
    #endif  // !CAPNP_LITE
  };
};

struct MixBinaryCapnpData {
  MixBinaryCapnpData() = delete;

  class Reader;
  class Builder;
  class Pipeline;

  struct _capnpPrivate {
    CAPNP_DECLARE_STRUCT_HEADER(9ba477d42ac52fd4, 0, 1)
    #if !CAPNP_LITE
    static constexpr ::capnp::_::RawBrandedSchema const* brand() { return &schema->defaultBrand; }
    #endif  // !CAPNP_LITE
  };
};

// =======================================================================================

class MBData::Reader {
public:
  typedef MBData Reads;

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

  inline  ::TypeEnum getType() const;

  inline  ::DetailEnum getDetails() const;

  inline  ::int32_t getId() const;

  inline bool hasFirst() const;
  inline  ::capnp::Text::Reader getFirst() const;

  inline bool hasSecond() const;
  inline  ::capnp::Text::Reader getSecond() const;

  inline bool hasThird() const;
  inline  ::capnp::Text::Reader getThird() const;

  inline  ::int64_t getBar() const;

  inline  ::int64_t getBeat() const;

  inline  ::int64_t getSeparate() const;

  inline  ::int64_t getEbar() const;

  inline  ::int64_t getEbeat() const;

  inline  ::int64_t getEseparate() const;

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

class MBData::Builder {
public:
  typedef MBData Builds;

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

  inline  ::TypeEnum getType();
  inline void setType( ::TypeEnum value);

  inline  ::DetailEnum getDetails();
  inline void setDetails( ::DetailEnum value);

  inline  ::int32_t getId();
  inline void setId( ::int32_t value);

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

  inline  ::int64_t getEbar();
  inline void setEbar( ::int64_t value);

  inline  ::int64_t getEbeat();
  inline void setEbeat( ::int64_t value);

  inline  ::int64_t getEseparate();
  inline void setEseparate( ::int64_t value);

private:
  ::capnp::_::StructBuilder _builder;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  friend class ::capnp::Orphanage;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
};

#if !CAPNP_LITE
class MBData::Pipeline {
public:
  typedef MBData Pipelines;

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

class MixBinaryCapnpData::Reader {
public:
  typedef MixBinaryCapnpData Reads;

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
  inline  ::capnp::List< ::MBData,  ::capnp::Kind::STRUCT>::Reader getDatas() const;

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

class MixBinaryCapnpData::Builder {
public:
  typedef MixBinaryCapnpData Builds;

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
  inline  ::capnp::List< ::MBData,  ::capnp::Kind::STRUCT>::Builder getDatas();
  inline void setDatas( ::capnp::List< ::MBData,  ::capnp::Kind::STRUCT>::Reader value);
  inline  ::capnp::List< ::MBData,  ::capnp::Kind::STRUCT>::Builder initDatas(unsigned int size);
  inline void adoptDatas(::capnp::Orphan< ::capnp::List< ::MBData,  ::capnp::Kind::STRUCT>>&& value);
  inline ::capnp::Orphan< ::capnp::List< ::MBData,  ::capnp::Kind::STRUCT>> disownDatas();

private:
  ::capnp::_::StructBuilder _builder;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  friend class ::capnp::Orphanage;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
};

#if !CAPNP_LITE
class MixBinaryCapnpData::Pipeline {
public:
  typedef MixBinaryCapnpData Pipelines;

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

inline  ::TypeEnum MBData::Reader::getType() const {
  return _reader.getDataField< ::TypeEnum>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS);
}

inline  ::TypeEnum MBData::Builder::getType() {
  return _builder.getDataField< ::TypeEnum>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS);
}
inline void MBData::Builder::setType( ::TypeEnum value) {
  _builder.setDataField< ::TypeEnum>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS, value);
}

inline  ::DetailEnum MBData::Reader::getDetails() const {
  return _reader.getDataField< ::DetailEnum>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS);
}

inline  ::DetailEnum MBData::Builder::getDetails() {
  return _builder.getDataField< ::DetailEnum>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS);
}
inline void MBData::Builder::setDetails( ::DetailEnum value) {
  _builder.setDataField< ::DetailEnum>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS, value);
}

inline  ::int32_t MBData::Reader::getId() const {
  return _reader.getDataField< ::int32_t>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS);
}

inline  ::int32_t MBData::Builder::getId() {
  return _builder.getDataField< ::int32_t>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS);
}
inline void MBData::Builder::setId( ::int32_t value) {
  _builder.setDataField< ::int32_t>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS, value);
}

inline bool MBData::Reader::hasFirst() const {
  return !_reader.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS).isNull();
}
inline bool MBData::Builder::hasFirst() {
  return !_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::Text::Reader MBData::Reader::getFirst() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_reader.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
inline  ::capnp::Text::Builder MBData::Builder::getFirst() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
inline void MBData::Builder::setFirst( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), value);
}
inline  ::capnp::Text::Builder MBData::Builder::initFirst(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), size);
}
inline void MBData::Builder::adoptFirst(
    ::capnp::Orphan< ::capnp::Text>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::adopt(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::Text> MBData::Builder::disownFirst() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::disown(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}

inline bool MBData::Reader::hasSecond() const {
  return !_reader.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS).isNull();
}
inline bool MBData::Builder::hasSecond() {
  return !_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::Text::Reader MBData::Reader::getSecond() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_reader.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS));
}
inline  ::capnp::Text::Builder MBData::Builder::getSecond() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS));
}
inline void MBData::Builder::setSecond( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS), value);
}
inline  ::capnp::Text::Builder MBData::Builder::initSecond(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS), size);
}
inline void MBData::Builder::adoptSecond(
    ::capnp::Orphan< ::capnp::Text>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::adopt(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::Text> MBData::Builder::disownSecond() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::disown(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS));
}

inline bool MBData::Reader::hasThird() const {
  return !_reader.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS).isNull();
}
inline bool MBData::Builder::hasThird() {
  return !_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::Text::Reader MBData::Reader::getThird() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_reader.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS));
}
inline  ::capnp::Text::Builder MBData::Builder::getThird() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS));
}
inline void MBData::Builder::setThird( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS), value);
}
inline  ::capnp::Text::Builder MBData::Builder::initThird(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS), size);
}
inline void MBData::Builder::adoptThird(
    ::capnp::Orphan< ::capnp::Text>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::adopt(_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::Text> MBData::Builder::disownThird() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::disown(_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS));
}

inline  ::int64_t MBData::Reader::getBar() const {
  return _reader.getDataField< ::int64_t>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS);
}

inline  ::int64_t MBData::Builder::getBar() {
  return _builder.getDataField< ::int64_t>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS);
}
inline void MBData::Builder::setBar( ::int64_t value) {
  _builder.setDataField< ::int64_t>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS, value);
}

inline  ::int64_t MBData::Reader::getBeat() const {
  return _reader.getDataField< ::int64_t>(
      ::capnp::bounded<2>() * ::capnp::ELEMENTS);
}

inline  ::int64_t MBData::Builder::getBeat() {
  return _builder.getDataField< ::int64_t>(
      ::capnp::bounded<2>() * ::capnp::ELEMENTS);
}
inline void MBData::Builder::setBeat( ::int64_t value) {
  _builder.setDataField< ::int64_t>(
      ::capnp::bounded<2>() * ::capnp::ELEMENTS, value);
}

inline  ::int64_t MBData::Reader::getSeparate() const {
  return _reader.getDataField< ::int64_t>(
      ::capnp::bounded<3>() * ::capnp::ELEMENTS);
}

inline  ::int64_t MBData::Builder::getSeparate() {
  return _builder.getDataField< ::int64_t>(
      ::capnp::bounded<3>() * ::capnp::ELEMENTS);
}
inline void MBData::Builder::setSeparate( ::int64_t value) {
  _builder.setDataField< ::int64_t>(
      ::capnp::bounded<3>() * ::capnp::ELEMENTS, value);
}

inline  ::int64_t MBData::Reader::getEbar() const {
  return _reader.getDataField< ::int64_t>(
      ::capnp::bounded<4>() * ::capnp::ELEMENTS);
}

inline  ::int64_t MBData::Builder::getEbar() {
  return _builder.getDataField< ::int64_t>(
      ::capnp::bounded<4>() * ::capnp::ELEMENTS);
}
inline void MBData::Builder::setEbar( ::int64_t value) {
  _builder.setDataField< ::int64_t>(
      ::capnp::bounded<4>() * ::capnp::ELEMENTS, value);
}

inline  ::int64_t MBData::Reader::getEbeat() const {
  return _reader.getDataField< ::int64_t>(
      ::capnp::bounded<5>() * ::capnp::ELEMENTS);
}

inline  ::int64_t MBData::Builder::getEbeat() {
  return _builder.getDataField< ::int64_t>(
      ::capnp::bounded<5>() * ::capnp::ELEMENTS);
}
inline void MBData::Builder::setEbeat( ::int64_t value) {
  _builder.setDataField< ::int64_t>(
      ::capnp::bounded<5>() * ::capnp::ELEMENTS, value);
}

inline  ::int64_t MBData::Reader::getEseparate() const {
  return _reader.getDataField< ::int64_t>(
      ::capnp::bounded<6>() * ::capnp::ELEMENTS);
}

inline  ::int64_t MBData::Builder::getEseparate() {
  return _builder.getDataField< ::int64_t>(
      ::capnp::bounded<6>() * ::capnp::ELEMENTS);
}
inline void MBData::Builder::setEseparate( ::int64_t value) {
  _builder.setDataField< ::int64_t>(
      ::capnp::bounded<6>() * ::capnp::ELEMENTS, value);
}

inline bool MixBinaryCapnpData::Reader::hasDatas() const {
  return !_reader.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS).isNull();
}
inline bool MixBinaryCapnpData::Builder::hasDatas() {
  return !_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::List< ::MBData,  ::capnp::Kind::STRUCT>::Reader MixBinaryCapnpData::Reader::getDatas() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::MBData,  ::capnp::Kind::STRUCT>>::get(_reader.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
inline  ::capnp::List< ::MBData,  ::capnp::Kind::STRUCT>::Builder MixBinaryCapnpData::Builder::getDatas() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::MBData,  ::capnp::Kind::STRUCT>>::get(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
inline void MixBinaryCapnpData::Builder::setDatas( ::capnp::List< ::MBData,  ::capnp::Kind::STRUCT>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::MBData,  ::capnp::Kind::STRUCT>>::set(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), value);
}
inline  ::capnp::List< ::MBData,  ::capnp::Kind::STRUCT>::Builder MixBinaryCapnpData::Builder::initDatas(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::MBData,  ::capnp::Kind::STRUCT>>::init(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), size);
}
inline void MixBinaryCapnpData::Builder::adoptDatas(
    ::capnp::Orphan< ::capnp::List< ::MBData,  ::capnp::Kind::STRUCT>>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::MBData,  ::capnp::Kind::STRUCT>>::adopt(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::List< ::MBData,  ::capnp::Kind::STRUCT>> MixBinaryCapnpData::Builder::disownDatas() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::MBData,  ::capnp::Kind::STRUCT>>::disown(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}


CAPNP_END_HEADER

