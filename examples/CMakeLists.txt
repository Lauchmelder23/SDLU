add_executable(sdlu_example
	main.cpp header.hpp
)

target_include_directories(sdlu_example PUBLIC
	sdlu
)

target_link_libraries(sdlu_example
	sdlu
)

# add_custom_command(TARGET sdlu_example POST_BUILD
	# COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:SDL2> $<TARGET_FILE_DIR:sdlu_example>
# )