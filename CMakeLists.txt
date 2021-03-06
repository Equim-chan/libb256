cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(libb256)

if(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_BINARY_DIR} AND NOT WIN32)
  message(FATAL_ERROR "You can not use CMake to build the project from the root of it's source tree! Remove the CMakeCache.txt file from this directory, then create a separate directory (either below this directory or elsewhere), and then re-run CMake from there.")
endif()

option(ENABLE_SHARED "Build shared library instead of static" OFF)

set(sources
    src/base256.c
    src/uthash.h)

set(cflags
    -std=c11 -O3
    -pedantic
    -Wall -Wextra -Wshadow -Wpointer-arith -Wstrict-prototypes -Wmissing-prototypes)

if(ENABLE_SHARED)
  add_library(b256 SHARED ${sources})
  target_compile_options(b256 PUBLIC ${cflags})
  target_include_directories(b256 PUBLIC include)
else()
  add_library(b256 STATIC ${sources})
  target_compile_options(b256 PUBLIC ${cflags})
  target_include_directories(b256 PUBLIC include)
endif()

install(TARGETS b256 DESTINATION lib)
install(FILES include/base256.h DESTINATION include)
install(FILES man/libb256.3 DESTINATION share/man/man3)
