# Blink (hello world) for STM8
# Parser SDCC linker memory map
# Dmitriy Vetutnev, 2020

set(RAM_ADDR "0x00000000")
set(ROM_ADDR "0x00008000")

math(EXPR ram_addr ${RAM_ADDR} OUTPUT_FORMAT DECIMAL)
math(EXPR rom_addr ${ROM_ADDR} OUTPUT_FORMAT DECIMAL)

file(STRINGS ${PATH} content)

set(ram_usage 0)
set(rom_usage 0)

set(hex8digit_re "[0-9A-B][0-9A-B][0-9A-B][0-9A-B][0-9A-B][0-9A-B][0-9A-B][0-9A-B]")
foreach(line ${content})
    if(${line} MATCHES "^[A-Z]+[ \t]+(${hex8digit_re})[ \t]+${hex8digit_re} =[ \t]+([0-9]+)\\.")
        set(addr ${CMAKE_MATCH_1})
        set(size ${CMAKE_MATCH_2})
        math(EXPR addr "0x${addr}" OUTPUT_FORMAT DECIMAL)
        if(addr GREATER_EQUAL ram_addr AND addr LESS rom_addr)
            math(EXPR ram_usage "${ram_usage} + ${size}" OUTPUT_FORMAT DECIMAL)
        else()
            math(EXPR rom_usage "${rom_usage} + ${size}" OUTPUT_FORMAT DECIMAL)
        endif()
    endif()
endforeach()

message(STATUS "RAM usage: ${ram_usage} bytes, ROM usage: ${rom_usage} bytes")
