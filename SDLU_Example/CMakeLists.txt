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

if(WIN32)
	add_custom_command(TARGET ${PNAME}
		POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE_DIR:SDL2>/SDL2d.dll $<TARGET_FILE_DIR:sdlu_example>
	)
else()
	add_custom_command(TARGET ${PNAME}
		POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE_DIR:SDL2>/libSDL2-2.0.so $<TARGET_FILE_DIR:sdlu_example>
	)
endif()