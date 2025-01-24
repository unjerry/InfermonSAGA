cmake_minimum_required(VERSION 3.12)
project(deps)

message("PROJECT_SOURCE_DIR\t${PROJECT_SOURCE_DIR}")
message("CMAKE_SOURCE_DIR\t${CMAKE_SOURCE_DIR}")

set(GLAD_SOURCES_DIR "${PROJECT_SOURCE_DIR}/glad")
add_subdirectory("${GLAD_SOURCES_DIR}/cmake" glad_cmake)
glad_add_library(glad REPRODUCIBLE MX API gl:core=4.3)

add_subdirectory(glfw)
include_directories(glfw/include)

add_executable(depTes depsTest.cpp)
target_link_libraries(depTes glad glfw)

