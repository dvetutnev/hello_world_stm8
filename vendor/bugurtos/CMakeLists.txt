# BuguRTOS
# Dmitriy Vetutnev, 2021

cmake_minimum_required(VERSION 3.0)
project(bugurtos C)

set(BUGURTOS_SOURCES

    kernel/crit_sec.c
    kernel/index.c
    kernel/item.c
    kernel/kernel.c
    kernel/pcounter.c
    kernel/pitem.c
    kernel/proc.c
    kernel/sched.c
    kernel/sync.c
    kernel/sched.c
    kernel/sync.c
    kernel/syscall.c
    kernel/timer.c
    kernel/vint.c
    kernel/xlist.c

    libs/native/cond.c
    libs/native/ipc.c
    libs/native/sem.c

    arch/stm8/sdcc/bugurt_port.c
    arch/stm8/sdcc/bugurt_proc_stack_init.c
)

add_library(${PROJECT_NAME} STATIC ${BUGURTOS_SOURCES})
target_include_directories(${PROJECT_NAME}
    PUBLIC kernel
    PUBLIC kernel/default
    PUBLIC libs/native
    PUBLIC arch/stm8/sdcc
)
target_link_libraries(${PROJECT_NAME} spl)
