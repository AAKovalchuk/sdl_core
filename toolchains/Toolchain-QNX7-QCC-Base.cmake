set(CMAKE_SYSTEM_NAME QNX)

set(CMAKE_SHARED_LIBRARY_PREFIX "lib")
set(CMAKE_SHARED_LIBRARY_SUFFIX ".so")
set(CMAKE_STATIC_LIBRARY_PREFIX "lib")
set(CMAKE_STATIC_LIBRARY_SUFFIX ".a")

if(CMAKE_HOST_WIN32)
    set(HOST_EXECUTABLE_SUFFIX ".exe")
endif()

if(QNX_HOST)
    set(ENV{QNX_HOST} "${QNX_HOST}")
else()
    set(QNX_HOST "$ENV{QNX_HOST}")
    if("${QNX_HOST}" STREQUAL "")
        message(FATAL_ERROR "QNX_HOST environment variable is not defined")
    endif()
    set(QNX_HOST "${QNX_HOST}" CACHE INTERNAL "")
endif()
message(STATUS "Using QNX_HOST ${QNX_HOST}")

if(QNX_TARGET)
    set(ENV{QNX_TARGET} "${QNX_TARGET}")
else()
    set(QNX_TARGET "$ENV{QNX_TARGET}")
    if("${QNX_TARGET}" STREQUAL "")
        message(FATAL_ERROR "QNX_TARGET environment variable is not defined")
    endif()
    set(QNX_TARGET "${QNX_TARGET}" CACHE INTERNAL "")
endif()
message(STATUS "Using QNX_TARGET ${QNX_TARGET}")

if(NOT EXISTS "${QNX_TARGET}/etc/qversion")
    message(FATAL_ERROR "The folder ${QNX_TARGET} is missing /etc/qversion and may not provide a QNX SDK")
endif()

file(READ "${QNX_TARGET}/etc/qversion" CMAKE_SYSTEM_VERSION)
string(REGEX REPLACE "[^0-9.]" "" CMAKE_SYSTEM_VERSION "${CMAKE_SYSTEM_VERSION}")
if("${CMAKE_SYSTEM_VERSION}" VERSION_LESS "7.0.0")
    message(FATAL_ERROR "This toolchain file is not supported for QNX ${CMAKE_SYSTEM_VERSION}")
else()
    message(STATUS "QNX Version is ${CMAKE_SYSTEM_VERSION}")
endif()

# List of root paths to search on the filesystem
# ${QNX_TARGET}/usr contains architecture independent headers
# ${QNX_TARGET}/${QNX_TARGET_ARCH_DIR} contains architecture-dependent headers
set(CMAKE_FIND_ROOT_PATH "${CMAKE_FIND_ROOT_PATH}" "${QNX_TARGET}/${QNX_TARGET_ARCH_DIR}" "${QNX_TARGET}/usr")

# Will remove duplicate items in the CMAKE_FIND_ROOT_PATH list.
list(REMOVE_DUPLICATES CMAKE_FIND_ROOT_PATH)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(CMAKE_C_COMPILER   "${QNX_HOST}/usr/bin/qcc${HOST_EXECUTABLE_SUFFIX}"                                  CACHE PATH "QNX gcc Program")
set(CMAKE_CXX_COMPILER "${QNX_HOST}/usr/bin/qcc${HOST_EXECUTABLE_SUFFIX}"                                  CACHE PATH "QNX g++ Program")
set(CMAKE_AR           "${QNX_HOST}/usr/bin/nto${CMAKE_SYSTEM_PROCESSOR}-ar${HOST_EXECUTABLE_SUFFIX}"      CACHE PATH "QNX ar Program")
set(CMAKE_RANLIB       "${QNX_HOST}/usr/bin/nto${CMAKE_SYSTEM_PROCESSOR}-ranlib${HOST_EXECUTABLE_SUFFIX}"  CACHE PATH "QNX ranlib Program")
set(CMAKE_NM           "${QNX_HOST}/usr/bin/nto${CMAKE_SYSTEM_PROCESSOR}-nm${HOST_EXECUTABLE_SUFFIX}"      CACHE PATH "QNX nm Program")
set(CMAKE_OBJCOPY      "${QNX_HOST}/usr/bin/nto${CMAKE_SYSTEM_PROCESSOR}-objcopy${HOST_EXECUTABLE_SUFFIX}" CACHE PATH "QNX objcopy Program")
set(CMAKE_OBJDUMP      "${QNX_HOST}/usr/bin/nto${CMAKE_SYSTEM_PROCESSOR}-objdump${HOST_EXECUTABLE_SUFFIX}" CACHE PATH "QNX objdump Program")
set(CMAKE_LINKER       "${QNX_HOST}/usr/bin/nto${CMAKE_SYSTEM_PROCESSOR}-ld${HOST_EXECUTABLE_SUFFIX}"      CACHE PATH "QNX Linker Program")
set(CMAKE_STRIP        "${QNX_HOST}/usr/bin/nto${CMAKE_SYSTEM_PROCESSOR}-strip${HOST_EXECUTABLE_SUFFIX}"   CACHE PATH "QNX Strip Program")

# Add -V<target> to specify target machine architecture
set(CMAKE_C_COMPILER_TARGET   ${QNX_QCC_ARCH} CACHE INTERNAL "")
set(CMAKE_CXX_COMPILER_TARGET ${QNX_QCC_ARCH} CACHE INTERNAL "")

set(CMAKE_C_FLAGS_INIT   "-lang-c")
set(CMAKE_CXX_FLAGS_INIT "-lang-c++")
