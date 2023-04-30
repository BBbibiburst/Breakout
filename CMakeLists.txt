cmake_minimum_required(VERSION 3.25)
project(Breakout)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include)

link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(Breakout src/main.cpp src/Game/Game.cpp src/Game/Game.h src/Render/Shader.cpp src/Render/Shader.h src/Render/Texture2D.cpp src/Render/Texture2D.h src/Game/GameResource/resource_manager.cpp src/Game/GameResource/resource_manager.h src/Library/stb_image.cpp src/Library/glad.c src/Render/SpriteRenderer.cpp src/Render/SpriteRenderer.h src/Game/GameObject/GameObject.cpp src/Game/GameObject/GameObject.h src/Game/GameLevel/GameLevel.cpp src/Game/GameLevel/GameLevel.h src/Game/GameObject/BallObject.cpp src/Game/GameObject/BallObject.h)

target_link_libraries(Breakout ${CMAKE_SOURCE_DIR}/lib/glfw3.dll)

target_link_libraries(Breakout ${CMAKE_SOURCE_DIR}/lib/libassimp-5d.dll)

target_link_libraries(Breakout ${CMAKE_SOURCE_DIR}/lib/libfreetyped.a)
