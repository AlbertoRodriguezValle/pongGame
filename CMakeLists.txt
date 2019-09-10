cmake_minimum_required(VERSION 3.7)
add_definitions(-std=c++17)

#set(CXX_FLAGS "-Wall")
#set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(PongGame)

include_directories(${SDL2_INCLUDE_DIRS} src)
add_executable(pongGame src/main.cpp src/PongGame.cpp)
target_link_libraries(pongGame)
