add_subdirectory(renderer)
add_subdirectory(data_structures)
include_directories(renderer data_structures)

add_library(rotev-engine INTERFACE)
target_link_libraries(rotev-engine INTERFACE renderer data_structures)
