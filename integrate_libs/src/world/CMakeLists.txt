set(src world.cc)                                                               

add_library(world SHARED ${src})                                                

set_target_properties(world PROPERTIES OUTPUT_NAME "world")                     

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
