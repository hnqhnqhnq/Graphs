cmake_minimum_required(VERSION 3.25)
project(Graphs C)

set(CMAKE_C_STANDARD 23)

add_executable(Graphs main.c stack.c stack.h queue.h queue.c graph.h graph.c list.h list.c)
