set(GMOCK_DIR "gmock/gmock-1.7.0"
    CACHE PATH "The path to the GoogleMock test framework.")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    # force this option to ON so that Google Test will use /MD instead of /MT
    # /MD is now the default for Visual Studio, so it should be our default, too
    option(gtest_force_shared_crt
           "Use shared (DLL) run-time lib even when Google Test is built as static lib."
           ON)
elseif (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE=1)
endif()

add_subdirectory(${GMOCK_DIR}) 
set_property(TARGET gtest APPEND_STRING PROPERTY COMPILE_FLAGS " -w")

include_directories(SYSTEM ${GMOCK_DIR}/gtest/include
                           ${GMOCK_DIR}/include)

### configure cuda building
find_package(CUDA QUIET REQUIRED)
include(FindCUDA)

include_directories(
/usr/local/cuda/include
/usr/local/cuda/samples/common/inc
${CMAKE_SOURCE_DIR}
)

link_directories(
/usr/local/cuda/lib64	
)

include(FindCUDA)

### allow custom build rules 
set(CUDA_ATTACH_VS_BUILD_RULE_TO_CUDA_FILE on)
set(CUDA_SEPARABLE_COMPILATION on)
set(BUILD_SHARED_LIBS off)
set(CUDA_VERBOSE_BUILD off)
set(CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS};
-O2
-gencode arch=compute_30,code=sm_30 
-gencode arch=compute_35,code=sm_35 
-gencode arch=compute_37,code=sm_37 
-gencode arch=compute_50,code=sm_50
)



#
# add_gmock_test(<target> <sources>...)
#
#  Adds a Google Mock based test executable, <target>, built from <sources> and
#  adds the test so that CTest will run it. Both the executable and the test
#  will be named <target>.
#
function(add_gmock_test target)
    # add_executable(${target} ${ARGN})
    cuda_add_executable(${target} ${ARGN})

    target_link_libraries(${target} 
	                      gmock_main
	                      kernel
						  -lcudart)

    add_test(${target} ${PROJECT_BINARY_DIR}/${target})
endfunction()

### add test
add_gmock_test(example_test example_test.cu)

### output path
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}) 
