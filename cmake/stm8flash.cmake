# Blink (hello world) for STM8
# stm8flash wrapper
# Dmitriy Vetutnev, 2019

find_program(STM8FLASH_PROGRAM stm8flash)
message(STATUS "stm8flash: ${STM8FLASH_PROGRAM}")
if(NOT STM8FLASH_PROGRAM)
    message(WARNING "stm8flash not found!")
endif()

add_custom_target(flash)
macro(stm8flash target)
    add_custom_target(
        "${target}_flash"
        COMMAND ${STM8FLASH_PROGRAM} -c stlink -p stm8s105?6 -w $<TARGET_FILE:${target}>
    )
    add_dependencies("${target}_flash" ${target})
    add_dependencies(flash "${target}_flash")
endmacro()

