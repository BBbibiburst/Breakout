cmake_minimum_required(VERSION 3.25)
project(Breakout)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include)

link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(Breakout src/main.cpp src/Game.cpp src/Game.h src/tools/Shader.cpp src/tools/Shader.h src/tools/Texture2D.cpp src/tools/Texture2D.h src/resource_manager.cpp src/resource_manager.h src/stb_image.cpp src/glad.c src/tools/SpriteRenderer.cpp src/tools/SpriteRenderer.h)

target_link_libraries(Breakout ${CMAKE_SOURCE_DIR}/lib/glfw3.dll)

target_link_libraries(Breakout ${CMAKE_SOURCE_DIR}/lib/libassimp-5d.dll)

target_link_libraries(Breakout ${CMAKE_SOURCE_DIR}/lib/libfreetyped.a)
