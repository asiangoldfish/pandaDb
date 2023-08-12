cmake_minimum_required(VERSION 3.25)
project(pandaDb VERSION 1.0.0 LANGUAGES CXX)

configure_file(pandaDbConfig.h.in pandaDbConfig.h)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose Release or Debug" FORCE)
endif()

set(CMAKE_CXX_EXTENSIONS OFF)

set(BITSIZE 64)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${CMAKE_SYSTEM_NAME}${BITSIZE}/${CMAKE_BUILD_TYPE}")


add_subdirectory(src)