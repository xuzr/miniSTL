cmake_minimum_required(VERSION 3.0)
SET(CMAKE_BUILD_TYPE "Debug")  
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")  
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
add_compile_options(-std=c++11)

project(miniSTL)
aux_source_directory(./sources SERVER_SOUR)
include_directories(./headers)
add_executable(miniSTL ${SERVER_SOUR})