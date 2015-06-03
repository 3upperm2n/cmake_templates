set(src hello.cc)                                                        

add_library(hello SHARED ${src})                                     

set_target_properties(hello PROPERTIES OUTPUT_NAME "hello")               

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
