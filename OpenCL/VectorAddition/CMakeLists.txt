cmake_minimum_required(VERSION 3.16)
project(VectorAddition LANGUAGES C)
file(GLOB src *.c *.h)
find_package(OpenCL 3.0 REQUIRED)
add_executable(VectorAddition ${src})
target_link_libraries(VectorAddition OpenCL::OpenCL)

