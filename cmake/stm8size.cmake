# Blink (hello world) for STM8
# Get usage RAM/ROM for STM8
# Dmitriy Vetutnev, 2020

macro(stm8size target)
    add_custom_command(
        TARGET ${target} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -D PATH="$<TARGET_FILE_DIR:${target}>/${target}.map" -P ${CMAKE_SOURCE_DIR}/cmake/LinkerMapParser.cmake
    )
endmacro()
