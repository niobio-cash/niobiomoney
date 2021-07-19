cmake_minimum_required(VERSION 3.16)

# Required for finding Threads 
SET (CMAKE_C_COMPILER_WORKS 1)
SET (CMAKE_CXX_COMPILER_WORKS 1)
# Enable the compiler cache
if (WIN32)
    find_program(CLCACHE_PROGRAM clcache)
else()
    find_program(CCACHE_PROGRAM ccache)
    if(CCACHE_PROGRAM)
        # Support Unix Makefiles and Ninja
        set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
        set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK "${CCACHE_PROGRAM}")
    endif()
endif()

include(macros/settings.cmake)

project(${CN_PROJECT_NAME})

if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 8)
        message(FATAL_ERROR "GCC version must be at least 8!  " ${CMAKE_CXX_COMPILER_VERSION})
    endif()
endif()

if (CMAKE_SYSTEM_PROCESSOR MATCHES "(64)")
    MESSAGE(STATUS "host system: ${CMAKE_SYSTEM_PROCESSOR}")
else ()
    message(FATAL_ERROR "Unrecognized architecture on host system: ${CMAKE_SYSTEM_PROCESSOR}")
endif ()

# Threads
find_package(Threads REQUIRED)

include_directories(include src external "${CMAKE_CURRENT_BINARY_DIR}/version")
if(APPLE)
  include_directories(SYSTEM /usr/include/malloc)
  enable_language(ASM)
endif()

if(MSVC)
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/Platform/Windows)
elseif(APPLE)
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/Platform/OSX)
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/Platform/Posix)
else()
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/Platform/Linux)
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/Platform/Posix)
endif()

include(macros/flags.cmake)
include(macros/boost.cmake)

set(VERSION "")

include(macros/version.cmake)

add_definitions(-DVERSION=\"${CN_VERSION}\")
add_definitions(-DGIT_REVISION=\"${GIT_REVISION}\")

add_subdirectory(external)
add_subdirectory(src)

