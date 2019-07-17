# Blink (hello world) for STM8
# Dmitriy Vetutnev, 2019

find_program(STM8FLASH_PROGRAM stm8flash)
message(STATUS "stm8flash: ${STM8FLASH_PROGRAM}")
if(NOT STM8FLASH_PROGRAM)
    message(WARNING "stm8flash not found!")
endif()

add_custom_target(flash)
macro(stm8flash target)
    add_custom_target("${target}_flash" COMMAND ${STM8FLASH_PROGRAM} -c stlinkv2 -p stm8s103?3 -w $<TARGET_FILE:${target}>)
    add_dependencies("${target}_flash" ${target})
    add_dependencies(flash "${target}_flash")
endmacro()

