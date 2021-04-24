cmake_minimum_required(VERSION 3.8)

project(sdlu)

find_package(SDL2 CONFIG REQUIRED)

option(BUILD_EXAMPLES "Builds the example projects" ON)

add_subdirectory(lib/sdl2_gfx)

file(GLOB_RECURSE sdlu_includes
    "include/*.hpp"
)

file(GLOB_RECURSE sdlu_sources
    "src/*.cpp"
)

add_library(sdlu
    ${sdlu_includes} ${sdlu_sources}
)

target_include_directories(sdlu PUBLIC
    "include"
    ${SDL2_INCLUDE_DIRS}
    sdl2_gfx
)

target_link_libraries(sdlu PUBLIC
    sdl2_gfx
    SDL2 SDL2main
)

if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
