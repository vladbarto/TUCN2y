cmake_minimum_required(VERSION 3.23)
project(primul_program C)

set(CMAKE_C_STANDARD 99)

add_executable(primul_program main.c)
include_directories("Profiler.h")