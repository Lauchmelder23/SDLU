target_sources(${PNAME} PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/Graphics.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/RenderWindow.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/RenderWindow.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/RenderTarget.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/RenderTarget.cpp
)

add_subdirectory(drawable)