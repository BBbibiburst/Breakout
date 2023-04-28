cmake_minimum_required(VERSION 3.25)
project(Breakout)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include)

link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(Breakout src/main.cpp src/Game/Game.cpp src/Game/Game.h src/Render/Shader.cpp src/Render/Shader.h src/Render/Texture2D.cpp src/Render/Texture2D.h src/resource_manager.cpp src/resource_manager.h src/stb_image.cpp src/glad.c src/Render/SpriteRenderer.cpp src/Render/SpriteRenderer.h src/Game/GameObject.cpp src/Game/GameObject.h src/Game/GameLevel.cpp src/Game/GameLevel.h)

target_link_libraries(Breakout ${CMAKE_SOURCE_DIR}/lib/glfw3.dll)

target_link_libraries(Breakout ${CMAKE_SOURCE_DIR}/lib/libassimp-5d.dll)

target_link_libraries(Breakout ${CMAKE_SOURCE_DIR}/lib/libfreetyped.a)
