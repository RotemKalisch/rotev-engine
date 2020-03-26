include_directories(renderer data_structures rasterization utils)
add_subdirectory(renderer)
add_subdirectory(data_structures)
add_subdirectory(rasterization)

add_library(rotev-engine INTERFACE)
target_link_libraries(rotev-engine INTERFACE renderer data_structures rasterization)
