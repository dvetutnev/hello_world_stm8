# Blink (hello world) for STM8
# Dmitriy Vetutnev, 2019

cmake_minimum_required(VERSION 3.9)
project(blink C)

set(CMAKE_EXECUTABLE_SUFFIX ".elf")
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "--out-fmt-elf")
add_executable(${CMAKE_PROJECT_NAME} main.c)

