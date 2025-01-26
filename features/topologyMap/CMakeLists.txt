cmake_minimum_required(VERSION 3.12)
project(topologyMap)

message("PROJECT_SOURCE_DIR\t${PROJECT_SOURCE_DIR}")
message("CMAKE_SOURCE_DIR\t${CMAKE_SOURCE_DIR}")

include_directories(${PROJECT_SOURCE_DIR}/include/)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/ topologyMapSrc)

add_executable(test test.cpp ${topologyMapSrc})
