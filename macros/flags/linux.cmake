# This option has no effect in glibc version less than 2.20.
# Since glibc 2.20 _BSD_SOURCE is deprecated, this macro is recomended instead
add_definitions("-D_DEFAULT_SOURCE -D_GNU_SOURCE")
set(MINGW_FLAG "")
set(ARCH native CACHE STRING "CPU to build for: -march value or default")
if ("${ARCH}" STREQUAL "default")
    set(ARCH_FLAG "")
else ()
    set(ARCH_FLAG "-march=${ARCH}")
endif ()

set(WARNINGS "-Wall -Wextra -Wpointer-arith -Wundef -Wvla -Wwrite-strings -Werror -Wno-error=extra -Wno-error=unused-function -Wno-error=deprecated-declarations -Wno-error=sign-compare -Wno-error=strict-aliasing -Wno-error=type-limits -Wno-unused-parameter -Wno-error=unused-variable -Wno-error=undef -Wno-error=uninitialized -Wno-error=unused-result -Wno-unknown-pragmas -Wno-clobbered -Wno-error=class-memaccess")

if (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 9)
    set(WARNINGS ${WARNINGS} -Wno-error=deprecated-copy -Wno-error=redundant-move)
endif()

if (CMAKE_C_COMPILER_ID STREQUAL "Clang")
    set(WARNINGS "${WARNINGS} -Wno-error=mismatched-tags -Wno-error=null-conversion -Wno-overloaded-shift-op-parentheses -Wno-error=shift-count-overflow -Wno-error=tautological-constant-out-of-range-compare -Wno-error=unused-private-field -Wno-error=unneeded-internal-declaration -Wno-error=missing-braces")
else ()
    set(WARNINGS "${WARNINGS} -Wlogical-op -Wno-error=maybe-uninitialized -Wno-error=unused-but-set-variable")
endif ()

if (MINGW)
    set(WARNINGS "${WARNINGS} -Wno-error=unused-value")
    #set(MINGW_FLAG "-DWIN32_LEAN_AND_MEAN")
    include_directories(SYSTEM src/platform/mingw)
endif ()

if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
    set(WARNINGS "${WARNINGS} -Wno-error=odr -Wno-format-truncation")
endif ()

set(C_WARNINGS "-Waggregate-return -Wnested-externs -Wold-style-definition -Wstrict-prototypes")
set(CXX_WARNINGS "-Wno-reorder -Wno-missing-field-initializers")

try_compile(STATIC_ASSERT_RES "${CMAKE_CURRENT_BINARY_DIR}/static-assert" "${CMAKE_CURRENT_SOURCE_DIR}/cmake/test-static-assert.c" COMPILE_DEFINITIONS "-std=c11")
if (STATIC_ASSERT_RES)
    set(STATIC_ASSERT_FLAG "")
else ()
    set(STATIC_ASSERT_FLAG "-Dstatic_assert=_Static_assert")
endif ()

try_compile(STATIC_ASSERT_CPP_RES "${CMAKE_CURRENT_BINARY_DIR}/static-assert" "${CMAKE_CURRENT_SOURCE_DIR}/cmake/test-static-assert.cpp" COMPILE_DEFINITIONS "-std=c++11")
if (STATIC_ASSERT_CPP_RES)
    set(STATIC_ASSERT_CPP_FLAG "")
else ()
    set(STATIC_ASSERT_CPP_FLAG "-Dstatic_assert=_Static_assert")
endif ()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 ${MINGW_FLAG} ${WARNINGS} ${C_WARNINGS} ${ARCH_FLAG} -maes")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ${MINGW_FLAG} ${STATIC_ASSERT_CPP_FLAG} ${WARNINGS} ${CXX_WARNINGS} ${ARCH_FLAG} -maes")

if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
    set(DEBUG_FLAGS "-g3 -Og")
endif()

set(RELEASE_FLAGS "-Ofast -DNDEBUG -Wno-unused-variable")

# There is a clang bug that does not allow to compile code that uses AES-NI intrinsics if -flto is enabled
if (CMAKE_C_COMPILER_ID STREQUAL "GNU" AND CMAKE_SYSTEM_NAME STREQUAL "Linux" AND CMAKE_BUILD_TYPE STREQUAL "Release")
    # On linux, to build in lto mode, check that ld.gold linker is used: 'update-alternatives --install /usr/bin/ld ld /usr/bin/ld.gold HIGHEST_PRIORITY'
    set(CMAKE_AR gcc-ar)
    set(CMAKE_RANLIB gcc-ranlib)
endif ()
set(RELEASE_FLAGS "${RELEASE_FLAGS} -flto")

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} ${DEBUG_FLAGS}")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${DEBUG_FLAGS}")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} ${RELEASE_FLAGS}")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${RELEASE_FLAGS}")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++")