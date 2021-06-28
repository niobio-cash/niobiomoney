cmake_minimum_required(VERSION 3.16)

include(macros/settings.cmake)

enable_testing()
# copy CTestCustom.cmake to build dir to disable long running tests in 'make test'
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/CTestCustom.cmake ${CMAKE_CURRENT_BINARY_DIR})


project(${CN_PROJECT_NAME})

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

