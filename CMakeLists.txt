cmake_minimum_required(VERSION 3.13)
project(RotevEngine)
set(CMAKE_CXX_STANDARD 20)
set(WARNING_FLAGS "-Wall -Werror -Wextra")
set(OPTIMIZATION_FLAGS "-march=native -O3 -ffast-math")
set(DEBUG_FLAGS "-g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WARNING_FLAGS} ${OPTIMIZATION_FLAGS} ${DEBUG_FLAGS}")

include_directories(src)
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(example)

