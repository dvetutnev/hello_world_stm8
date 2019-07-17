# Blink (hello world) for STM8
# Dmitriy Vetutnev, 2019

cmake_minimum_required(VERSION 3.9)
project(blink C)

message(STATUS "CMAKE_FIND_ROOT_PATH: ${CMAKE_FIND_ROOT_PATH}")

add_executable(${CMAKE_PROJECT_NAME} main.c)

