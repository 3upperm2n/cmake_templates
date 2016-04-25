cmake_minimum_required(VERSION 2.8)

project("build kernel libs") 

### find cuda installed
find_package(CUDA QUIET REQUIRED)
if (CUDA_FOUND)
	message("CUDA found, using device squaring!")
else()
	message("CUDA not found, doing something alternatively")
endif()

### include header files 
include_directories(
/usr/local/cuda/include
/usr/local/cuda/samples/common/inc
${CMAKE_CURRENT_SOURCE_DIR}
)

### libs 
link_directories(
/usr/local/cuda/lib64	
)


### tools for building cuda files
include(FindCUDA)

### allow custom build rules 
set(CUDA_ATTACH_VS_BUILD_RULE_TO_CUDA_FILE on)

### allow separable compilation for all cuda runtime objects
set(CUDA_SEPARABLE_COMPILATION on)

set(BUILD_SHARED_LIBS off)

### versose during building
set(CUDA_VERBOSE_BUILD off)

### nvcc options 
set(CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS};
-O2
-gencode arch=compute_30,code=sm_30 
-gencode arch=compute_35,code=sm_35 
-gencode arch=compute_50,code=sm_50
-gencode arch=compute_52,code=sm_52
)

file( GLOB CUDA_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}  *.cu )
MESSAGE( STATUS "Process file: ${CUDA_FILES}" )

foreach( cudasrc ${CUDA_FILES} )
  string( REPLACE ".cu" "" cudaobj ${cudasrc} )
  ### compile target from source files 
  cuda_add_executable( ${cudaobj} ${cudasrc} )

  ### runtime libs
  target_link_libraries( ${cudaobj}	-lcudart )
#
endforeach( cudasrc ${CUDA_FILES} )
