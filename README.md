# Project_DJ_Engine

This project is a DJ/rhythm game engine written in C++. All sources live under `include/`.

## Document

See **[document Website](https://rliop913.github.io/Project_DJ_Engine/)**

## Building

Prerequisites:

- C++20 compatible compiler
- CMake 3.12 or later
- SWIG
- OpenSSL

To build the engine:

```bash
mkdir build
cd build
cmake ..
cmake --build . --parallel
```


## Dependencies

This project uses the following dependencies, which are automatically fetched using `FetchContent` or `ExternalProject_Add`:

- **[miniaudio](https://github.com/mackron/miniaudio)**: Audio playback and capture library.
- **[highway](https://github.com/google/highway)**: High-performance SIMD library.
- **[CapnProto](https://github.com/capnproto/capnproto)**: Serialization library.
- **[nlohmann/json](https://github.com/nlohmann/json)**: JSON for Modern C++.
- **[sqlite3](https://www.sqlite.org/index.html)**: SQL database engine.
- **[cppcodec](https://github.com/tplgy/cppcodec)**: Header-only C++11 library for encoding/decoding schemes.
- **[annoy](https://github.com/spotify/annoy)**: Approximate Nearest Neighbors Oh Yeah.
- **[spdlog](https://github.com/gabime/spdlog)**: Fast C++ logging library.
- **[libgit2](https://github.com/libgit2/libgit2)**: Git core library.
- **[rocksdb](https://github.com/facebook/rocksdb)**: A library that provides an embeddable, persistent key-value store for fast storage.
- **[SoundTouch](https://www.surina.net/soundtouch/)**: Audio processing library.

## Generating Documentation

Documentation is produced using Doxygen and Sphinx. Ensure both tools are available in your PATH, then run:

```bash
bash DOCUMENT_GENERATOR.sh
```

The resulting HTML documentation will appear in the `docs/` directory.
