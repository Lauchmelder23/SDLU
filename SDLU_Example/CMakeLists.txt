set(PNAME sdlu_example)

add_executable(${PNAME}
	main.cpp header.hpp
)

target_include_directories(${PNAME} PRIVATE
	${PROJECT_SOURCE_DIR}/SDLU
	${PROJECT_SOURCE_DIR}/3rdparty/SDL/include
)

target_link_libraries(${PNAME}
	SDLU
	SDL2
	SDL2main
)

add_custom_command(TARGET ${PNAME}
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/3rdparty/SDL/SDL2d.dll ${CMAKE_BINARY_DIR}/SDLU_Example/
)