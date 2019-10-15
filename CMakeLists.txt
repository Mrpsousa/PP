set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
cmake_minimum_required(VERSION 3.0)

project(prj1_BLAS)

file(GLOB HEADERS src/*.h)
file(GLOB SOURCES src/*.c)

set(SRC_FILES ${HEADERS} ${SOURCES})

add_compile_options(-Wall)

add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} cblas omp)

add_executable(prj1_OPENBLAS ${SRC_FILES})
target_link_libraries(prj1_OPENBLAS openblas omp)