enable_testing()
find_package(GTest REQUIRED)                                                    
include_directories(${GTEST_INCLUDE_DIRS})                                      

include_directories(data_structures rasterization)

file(GLOB_RECURSE TEST_FILES *.cc)
add_executable(tests ${TEST_FILES})                                             
target_link_libraries(tests ${GTEST_BOTH_LIBRARIES} pthread rotev-engine)  
add_custom_target(
    COMMAND ./tests                                                             
    DEPENDS tests
    )
