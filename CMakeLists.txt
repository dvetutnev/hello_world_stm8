# Blink (hello world) for STM8
# Dmitriy Vetutnev, 2019

cmake_minimum_required(VERSION 3.9)
project(blink C)

message(STATUS "CMAKE_FIND_ROOT_PATH: ${CMAKE_FIND_ROOT_PATH}")
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
include(stm8flash)

add_executable(blink main.c)
stm8flash(blink)

