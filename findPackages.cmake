# set(GIT_USE_STAT_MTIMESPEC ON CACHE BOOL "Don't use nanosecond timestamps" FORCE)


FetchContent_Declare(
  miniaudio
  GIT_REPOSITORY https://github.com/mackron/miniaudio.git
  GIT_TAG 0.11.21
)

FetchContent_Declare(
  highway
  GIT_REPOSITORY https://github.com/google/highway.git
  GIT_TAG 1.2.0
)

FetchContent_Declare(
  CapnProto
  GIT_REPOSITORY https://github.com/capnproto/capnproto.git
  GIT_TAG v1.1.0
)

FetchContent_Declare(
  NHJson
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.12.0
)

FetchContent_Declare(
  sql_amalgam
  URL https://www.sqlite.org/2024/sqlite-amalgamation-3450000.zip
)


include(ExternalProject)

if(WIN32)
FetchContent_Declare(
    zlib
    GIT_REPOSITORY https://github.com/madler/zlib.git
    GIT_TAG v1.3.1
  )
  FetchContent_MakeAvailable(zlib)
  set(ZLIB_DEBUG_LIB_PATH   "${zlib_BINARY_DIR}/Debug/zlibd.lib")
  set(ZLIB_RELEASE_LIB_PATH "${zlib_BINARY_DIR}/Release/zlib.lib")
  # if()
  # include_directories(${zlib_SOURCE_DIR})
# if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
ExternalProject_Add(
  libgit2
  GIT_REPOSITORY https://github.com/libgit2/libgit2.git
  GIT_TAG v1.9.0
  
  PREFIX "${CMAKE_BINARY_DIR}/_deps"
  BUILD_IN_SOURCE 0
  DEPENDS        zlib
  CONFIGURE_COMMAND
    ${CMAKE_COMMAND}
      -G "${CMAKE_GENERATOR}"
      -A "${CMAKE_GENERATOR_PLATFORM}"
      -S <SOURCE_DIR>
      -B <BINARY_DIR>
      -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
      -DBUILD_SHARED_LIBS=OFF
      -DREGEX_BACKEND=builtin
      -DCMAKE_POSITION_INDEPENDENT_CODE=ON
      -DZLIB_LIBRARY:FILEPATH=$<IF:$<CONFIG:Debug>,${ZLIB_DEBUG_LIB_PATH},${ZLIB_RELEASE_LIB_PATH}>

  BUILD_COMMAND  ${CMAKE_COMMAND} --build . --config $<CONFIG>
  INSTALL_COMMAND ${CMAKE_COMMAND} --install . --config $<CONFIG>
)
link_libraries(
  debug "${ZLIB_DEBUG_LIB_PATH}"
  optimized "${ZLIB_RELEASE_LIB_PATH}"
)

set(OPENSSL_USE_STATIC_LIBS TRUE)
# ExternalProject_Add(
#   libgit2
#   GIT_REPOSITORY https://github.com/libgit2/libgit2.git
#   GIT_TAG v1.9.0

#   PREFIX "${CMAKE_BINARY_DIR}/_deps"
#   BUILD_IN_SOURCE 0
#   CMAKE_ARGS     
#     -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR> 
#     -DBUILD_SHARED_LIBS=OFF 
#     -DREGEX_BACKEND=builtin 
#     -DZLIB_LIBRARY:FILEPATH=${zlib_BINARY_DIR}/Debug/zlibd.lib
#   CMAKE_CACHE_ARGS_RELEASE
#     -DZLIB_LIBRARY:FILEPATH=${zlib_BINARY_DIR}/Release/zlib.lib
#   BUILD_COMMAND  ${CMAKE_COMMAND} --build . --config $<CONFIG>
#   INSTALL_COMMAND ${CMAKE_COMMAND} --install . --config $<CONFIG>
# )

else()
ExternalProject_Add(
  libgit2
  GIT_REPOSITORY https://github.com/libgit2/libgit2.git
  GIT_TAG v1.9.0

  PREFIX "${CMAKE_BINARY_DIR}/_deps"
  BUILD_IN_SOURCE 0
  CMAKE_ARGS 
    -DBUILD_SHARED_LIBS=OFF 
    -DREGEX_BACKEND=builtin
    -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
    -DCMAKE_POSITION_INDEPENDENT_CODE=ON

  BUILD_COMMAND cmake --build . --parallel 6
  INSTALL_DIR "${CMAKE_BINARY_DIR}/libgitbin"
  INSTALL_COMMAND cmake --install . --prefix "${CMAKE_BINARY_DIR}/libgitbin"
  BUILD_BYPRODUCTS "${CMAKE_BINARY_DIR}/libgitbin/lib/libgit2.a"
)
endif()

ExternalProject_Get_Property(libgit2 source_dir binary_dir install_dir)
# message("환경변수-install: ${install_dir} $<CONFIG>")




find_package(OpenSSL REQUIRED)
link_libraries(${OPENSSL_LIBRARIES})
# link_directories(${install_dir}/lib)
if(UNIX)
add_library(libgit2_static STATIC IMPORTED GLOBAL)

set_target_properties(libgit2_static PROPERTIES
  IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/libgitbin/lib/libgit2.a"
  # INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_BINARY_DIR}/libgitbin/include"
)
add_dependencies(libgit2_static libgit2)


link_libraries(libgit2_static)
else()
add_library(libgit2_static STATIC IMPORTED GLOBAL)

add_dependencies(libgit2_static libgit2)

# set_target_properties(libgit2_static PROPERTIES
#     IMPORTED_LOCATION  "$<$<CONFIG:Debug>:${install_dir}/src/libgit2-build/Debug/git2.lib>$<$<CONFIG:Release>:${install_dir}/libgit2-build/Release/git2.lib>"
    
#     INTERFACE_INCLUDE_DIRECTORIES "${install_dir}/include"
# )
# file(GLOB LIBGIT2_LIBRARIES "${CMAKE_BINARY_DIR}/src/libgit2-build/${CMAKE_BUILD_TYPE}/git2.lib")
# link_libraries(${CMAKE_BINARY_DIR}/src/libgit2-build/${CMAKE_BUILD_TYPE}/git2.lib)
# link_libraries(
#   $<$<CONFIG:Debug>:${install_dir}/src/libgit2-build/Debug/libgit2_debug.lib>
#   $<$<CONFIG:Release>:${install_dir}/src/libgit2-build/Release/libgit2.lib>
# )
link_libraries("$<$<CONFIG:Debug>:${install_dir}/src/libgit2-build/Debug/git2.lib>$<$<CONFIG:Release>:${install_dir}/src/libgit2-build/Release/git2.lib>")
endif()
# add_library(libgit2_static INTERFACE IMPORTED GLOBAL)

# add_dependencies(libgit2_static libgit2)

# set_target_properties(libgit2_static PROPERTIES
#   INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_BINARY_DIR}/libgitbin/include"
#   INTERFACE_LINK_LIBRARIES "${CMAKE_BINARY_DIR}/libgitbin/lib/libgit2.a"
# )


# message(${LIBGIT2_INCLUDE_DIR})
# link_libraries(libgit2)
# message("LOCATION위치: ${install_dir}/include")
include_directories(${install_dir}/include)
# find_package(SQLite3 REQUIRED)

FetchContent_MakeAvailable(CapnProto)
FetchContent_MakeAvailable(miniaudio)
FetchContent_MakeAvailable(highway)
FetchContent_MakeAvailable(NHJson)
FetchContent_MakeAvailable(sql_amalgam)
# get_cmake_property(_vars VARIABLES)

# foreach(var ${_vars})
#     if(var MATCHES "^zlib")
#         message(STATUS "환경변수: ${var} = [${${var}}]")
#     endif()
# endforeach()
include_directories(${nlohmann_json_SOURCE_DIR}/include)
include_directories(${hwy_SOURCE_DIR})
include_directories(${sql_amalgam_SOURCE_DIR})
# link_libraries(${hwy_BINARY_DIR}/libhwy.a)
# include_directories(${libgit2_INCLUDE_DIRS})
set_target_properties(
  capnp
  capnpc
  kj
  capnp-json
  PROPERTIES POSITION_INDEPENDENT_CODE ON
)
find_package(SWIG REQUIRED)
include(UseSWIG)
