set(CMAKE_SYSTEM_NAME Generic)

get_filename_component(SDCC_LOCATION "${CMAKE_C_COMPILER}" DIRECTORY)
get_filename_component(SDCC_PREFIX "${SDCC_LOCATION}" DIRECTORY)
set(CMAKE_FIND_ROOT_PATH ${SDCC_PREFIX}/share/sdcc)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(CMAKE_C_FLAGS_INIT " -mstm8 --opt-code-size")
set(CMAKE_EXE_LINKER_FLAGS_INIT "")
