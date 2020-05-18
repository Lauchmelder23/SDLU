set(PNAME SDLU)

add_library(${PNAME}
	alibi.cpp SDLU.hpp Util.hpp
 "structures/Color.cpp")

set_property(TARGET ${PNAME} PROPERTY CXX_STANDARD 17)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	add_link_options(-lm)
endif()

target_include_directories(${PNAME} PRIVATE
	${PROJECT_SOURCE_DIR}/3rdparty/SDL/include
	${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(${PNAME} PRIVATE
	SDL2
)

add_subdirectory(structures)
add_subdirectory(graphics)