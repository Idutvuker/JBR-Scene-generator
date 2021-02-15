cmake_minimum_required(VERSION 3.10)
project(SceneGen)

set(CMAKE_CXX_STANDARD 14)

include_directories(external/raylib/include)
link_directories(external/raylib/lib)

add_executable(SceneGen src/main.cpp src/SceneConfig.cpp src/common.cpp)
target_link_libraries(SceneGen raylib)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR})