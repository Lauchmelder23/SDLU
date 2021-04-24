file(GLOB_RECURSE sdl2gfx_includes
	"include/*.h"
)

file(GLOB_RECURSE sdl2gfx_sources
	"src/*.c"
)

add_library(sdl2_gfx 
	${sdl2gfx_includes} ${sdl2gfx_sources}
)

target_include_directories(sdl2_gfx PUBLIC 
	"include"
	${SDL2_INCLUDE_DIRS}
)

target_link_libraries(sdl2_gfx PUBLIC 
	${SDL2_PREFIX}SDL2 ${SDL2_PREFIX}SDL2main
)
