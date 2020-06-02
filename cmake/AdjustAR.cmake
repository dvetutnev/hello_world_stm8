# Blink (hello world) for STM8
# Find sdar for new version SDCC
# Dmitriy Vetutnev, 2020

function(adjustAR var)
    if(NOT DEFINED ${var} OR ${var} MATCHES ".*-NOTFOUND$")
        find_program(SDAR_EXECUTABLE sdar PATHS "${SDCC_LOCATION}" NO_DEFAULT_PATH)

        message(STATUS "sdar: ${SDAR_EXECUTABLE}")
        set(${var} ${SDAR_EXECUTABLE} PARENT_SCOPE)
        message(STATUS "Set ${var} to ${SDAR_EXECUTABLE}")

        set(value
            "\"${CMAKE_COMMAND}\" -E remove <TARGET>"
            "<CMAKE_AR> -rc <TARGET> <LINK_FLAGS> <OBJECTS> "
        )
        set(CMAKE_C_CREATE_STATIC_LIBRARY ${value} PARENT_SCOPE)
        message(STATUS "Set CMAKE_C_CREATE_STATIC_LIBRARY to ${value}")
    endif()
endfunction()
