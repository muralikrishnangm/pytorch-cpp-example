cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(example)

if ("${ARCH}" STREQUAL "CUDA")
  enable_language(CUDA)
endif()

find_package(Torch REQUIRED)

set(CXX_SRC torch_interface.cpp)
if ("${ARCH}" STREQUAL "CUDA")
  set(MAIN_SRC example_pytorchNN_gpu.cpp)
else()
  set(MAIN_SRC example_pytorchNN_cpu.cpp)
endif()

add_executable(example ${CXX_SRC} ${MAIN_SRC})
target_link_libraries(example ${TORCH_LIBRARIES})
set_property(TARGET example PROPERTY CXX_STANDARD 14)

if ("${ARCH}" STREQUAL "CUDA")
  enable_language(CUDA)
  set_source_files_properties(${MAIN_SRC} PROPERTIES LANGUAGE CUDA)
endif()
