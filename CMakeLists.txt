cmake_minimum_required (VERSION 3.24 FATAL_ERROR)
project (mp VERSION 0.1 LANGUAGES C CXX)

# Make including this file idempotent
#
if(TARGET mp OR TARGET mp::mp)
  return()
endif()

# If this is the current project.
#
if(PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME)
  # Laod the cmake recipes and utilities.
  #
  include(${CMAKE_CURRENT_LIST_DIR}/cmake/load_cmake_helpers.cmake)
  
  # Options for generating tests and documentation.
  #
  option(MP_TEST "Generate the tests." ON)
  option(MP_DOCS "Generate the docs." OFF)

  # compile_commands.json
  #
  symlink_compile_commands()

  # Convenience targets for git operations
  #
  make_submodule_pull_target()
  
else()
  option(MP_TEST "Generate the tests." OFF)
  option(MP_DOCS "Generate the docs." OFF)
endif()

# Put executables in the top-level binary directory
#
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Output configuration
#
message("-- mp: Configuration: ${CMAKE_CURRENT_SOURCE_DIR}")
message("-- mp: Included from: ${CMAKE_SOURCE_DIR}")
message("-- mp: Install prefix ${CMAKE_INSTALL_PREFIX}")
message("-- mp: test ${MP_TEST}")
message("-- mp: docs ${MP_DOCS}")

# Setup compilation
#
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall)
add_compile_options(-O)

# Add our dependencies
#
add_fmt()
add_pp()

# Build the library
#
add_library(mp INTERFACE)
add_library(mp::mp ALIAS mp) # Allow interop between FetchContent and FindPackage.

# Define the header files for this library.
#
file(GLOB_RECURSE PUBLIC_INCLUDE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} include/*.h)
target_sources(mp INTERFACE FILE_SET HEADERS BASE_DIRS include FILES ${PUBLIC_INCLUDE_FILES})

target_link_libraries(mp INTERFACE fmt::fmt pp::pp)

# Optionally configure the tests
#
if(MP_TEST)
  add_gtest()
  add_subdirectory(test)
endif()

# Optionally configure the documentation
#
if(MP_DOCS)
  add_subdirectory(docs)
endif()

# Install config
#
install_config(mp)
