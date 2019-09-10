cmake_minimum_required(VERSION 3.7)
add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(PongGame)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} src)
add_executable(pongGame src/main.cpp src/Display.cpp src/Input.cpp src/PongGame.cpp src/Ball.cpp src/Player.cpp src/GameElement.cpp)
target_link_libraries(pongGame ${SDL2_LIBRARIES} -pthread)