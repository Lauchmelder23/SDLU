cmake_minimum_required(VERSION 3.8)

project(sdlu)

if(NOT ENABLE_EXAMPLE)
    set(ENABLE_EXAMPLE CACHE BOOL OFF)
endif()

add_subdirectory(3rdparty/SDL)
add_subdirectory(SDLU)
if(ENABLE_EXAMPLE)
   add_subdirectory(SDLU_Example)
endif()