cmake_minimum_required(VERSION 3.16)

project(MathTool VERSION 0.0.0 LANGUAGES CXX)

file(GLOB file *.cpp *.h *.qrc)

set(CMAKE_CXX_STANDARD 20)

find_package(Qt6 COMPONENTS Widgets)
find_package(GSL)

set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

add_executable(MathTool ${file})

target_link_libraries(MathTool Qt::Widgets)
target_link_libraries(MathTool GSL::gsl)
