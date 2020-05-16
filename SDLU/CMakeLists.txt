set(PNAME SDLU)

add_library(${PNAME}
	alibi.cpp SDLU.hpp
)

target_include_directories(${PNAME} PRIVATE
	${PROJECT_SOURCE_DIR}/3rdparty/SDL/include
)

target_link_libraries(${PNAME} PRIVATE
	${CMAKE_BINARY_DIR}/3rdparty/SDL/SDL2d.lib
)