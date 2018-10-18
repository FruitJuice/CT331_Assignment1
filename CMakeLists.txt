cmake_minimum_required(VERSION 3.12)
project(Assignment1 C)

set(CMAKE_C_STANDARD 11)

include_directories(src/q1)
include_directories(src/q2)
include_directories(src/q3)

add_executable(Assignment1
    src/q1/assignment.c
    src/q2/assignment.c
    src/q2/linkedList.c
    src/q2/linkedList.h
    src/q2/tests.c
    src/q2/tests.h
    src/q3/assignment.c
    src/q3/genericLinkedList.c
    src/q3/genericLinkedList.h
    src/q3/tests.c
    src/q3/tests.h)
