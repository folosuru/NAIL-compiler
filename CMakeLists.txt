cmake_minimum_required(VERSION 3.5)
project(NTSL-cl)
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES
    src/**.hpp
    src/**.cpp
)
include_directories(src)
add_executable(NTSL_cl ${SOURCES})