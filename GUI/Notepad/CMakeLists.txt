cmake_minimum_required(VERSION 3.16)

project(Notepad)

find_package(Qt6 COMPONENTS Widgets)
find_package(Qt6 COMPONENTS PrintSupport)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

file(GLOB resource *.cpp *.h *.qrc)

add_executable(Notepad ${resource})

target_link_libraries(Notepad Qt::Widgets)
target_link_libraries(Notepad Qt::PrintSupport)
