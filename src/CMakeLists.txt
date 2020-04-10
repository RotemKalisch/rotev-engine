include_directories(utils data_structures renderer rasterization geometry engine)
add_subdirectory(renderer)
add_subdirectory(data_structures)
add_subdirectory(rasterization)
add_subdirectory(geometry)
add_subdirectory(engine)

add_library(rotev-engine INTERFACE)
target_link_libraries(rotev-engine INTERFACE renderer data_structures rasterization geometry engine)

