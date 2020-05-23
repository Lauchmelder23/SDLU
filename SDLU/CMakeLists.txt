set(PNAME SDLU)

add_library(${PNAME}
	alibi.cpp SDLU.hpp Util.hpp
 "structures/Color.cpp" "structures/Mouse.cpp" "structures/Window.cpp" "graphics/RenderTarget.cpp" "graphics/drawable/Transformable.cpp" "graphics/drawable/shapes/Rectangle.cpp")

set_property(TARGET ${PNAME} PROPERTY CXX_STANDARD 17)

target_include_directories(${PNAME} PRIVATE
	${PROJECT_SOURCE_DIR}/3rdparty/SDL/include
	${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(${PNAME}
	SDL2
)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	target_link_libraries(${PNAME} m)
endif()

add_subdirectory(structures)
add_subdirectory(graphics)