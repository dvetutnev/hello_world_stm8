# Blink (hello world) for STM8
# Dmitriy Vetutnev, 2019 - 2020

cmake_minimum_required(VERSION 3.9)
project(blink C)

message(STATUS "CMAKE_FIND_ROOT_PATH: ${CMAKE_FIND_ROOT_PATH}")

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
include(stm8flash)
include(stm8size)
include(AdjustAR)
adjustAR(CMAKE_AR)

set(DEVICE "STM8S105")
include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(vendor/STM8S_StdPeriph_Lib)

add_executable(blink
    main.c
    stm8s_it.c
)
target_link_libraries(blink spl)
target_compile_definitions(blink
    PRIVATE
        -DLED_GPIO_PORT=GPIOD
        -DLED_GPIO_PIN=GPIO_PIN_0
)

stm8flash(blink)
stm8size(blink)
