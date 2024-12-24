cmake_minimum_required(VERSION 3.16)
project(SinglyLinkedList LANGUAGES C)
file(GLOB src *  .c .h)
add_executable(SinglyLinkedList ${src})
