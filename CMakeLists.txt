cmake_minimum_required(VERSION 3.13)
project(RotevEngine)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -fconcepts -march=native -g")

include_directories(src)
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(example)

