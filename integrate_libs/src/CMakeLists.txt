# add to the include paths                                                      
include_directories(${CMAKE_CURRENT_SOURCE_DIR})                                

# compiler flags                                                                
set(CMAKE_CXX_FLAGS "-Wall -O2")                                                    

# directories in the project                                                    
add_subdirectory(hello)
add_subdirectory(world)

add_executable(main main.cc)                                                    

# libs to be linked against                                                     
#set(lib_lists hello world)                                                          
target_link_libraries(main 
                      hello 
					  world)                                         

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)    
