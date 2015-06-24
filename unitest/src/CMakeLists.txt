# add to the include paths                                                      
#include_directories(${CMAKE_CURRENT_SOURCE_DIR})                                

# pthread
find_package(Threads)

# test directory
#add_subdirectory(unit_test)

# libs
add_library(ToDo SHARED ToDo.cpp)
add_library(compute SHARED compute.cpp)

# make libs visible to others
target_include_directories (ToDo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories (compute PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# configure gtest
#include("cmake/GTest.cmake")

add_executable(main
               main.cpp)

target_link_libraries(main
                      LINK_PUBLIC ToDo compute)
                                                                  
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})    

# add tests
#cxx_test(example_test example_test.cpp gtest_main)


# libraries
#add_library(compute OBJECT compute.cc)

#add_executable(main
#               main.cc
#               $<TARGET_OBJECTS:compute>)

# compiler flags                                                                
#set(CMAKE_CXX_FLAGS "-Wall -O2")                                                    

