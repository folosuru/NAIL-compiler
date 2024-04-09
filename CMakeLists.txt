cmake_minimum_required(VERSION 3.5)
project(NAIL-cl)
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES
    src/**.hpp
    src/**.cpp
)
include_directories(src)
add_executable(NAIL_cl ${SOURCES})