# STM8S/A Standard Peripherals Library
# Dmitriy Vetutnev, 2020

cmake_minimum_required(VERSION 3.9)
project(spl C)

set(SUPPORT_DEVICES
    "STM8S208"
    "STM8S207"
    "STM8S007"
    "STM8AF52Ax"
    "STM8AF62Ax"
    "STM8S105"
    "STM8S005"
    "STM8AF626x"
    "STM8AF622x"
    "STM8S103"
    "TM8S003"
    "STM8S903"
    "STM8S001"
)
if(NOT ${DEVICE} IN_LIST SUPPORT_DEVICES)
    message(FATAL_ERROR "Target device ${DEVICE} not support")
endif()
mark_as_advanced(SUPPORT_DEVICES)

set(SPL_INCLUDE_DIR Libraries/STM8S_StdPeriph_Driver/inc)
set(SPL_SOURCE_DIR Libraries/STM8S_StdPeriph_Driver/src)

set(SPL_SOURCES
    ${SPL_SOURCE_DIR}/stm8s_awu.c
    ${SPL_SOURCE_DIR}/stm8s_beep.c
    ${SPL_SOURCE_DIR}/stm8s_clk.c
    ${SPL_SOURCE_DIR}/stm8s_exti.c
    ${SPL_SOURCE_DIR}/stm8s_flash.c
    ${SPL_SOURCE_DIR}/stm8s_gpio.c
    ${SPL_SOURCE_DIR}/stm8s_i2c.c
    ${SPL_SOURCE_DIR}/stm8s_itc.c
    ${SPL_SOURCE_DIR}/stm8s_iwdg.c
    ${SPL_SOURCE_DIR}/stm8s_rst.c
    ${SPL_SOURCE_DIR}/stm8s_spi.c
    ${SPL_SOURCE_DIR}/stm8s_tim1.c
    ${SPL_SOURCE_DIR}/stm8s_wwdg.c
)

set(ADC1_PRESENT
    "STM8S105"
    "STM8S005"
    "STM8S103"
    "STM8S003"
    "STM8S001"
    "STM8S903"
    "STM8AF626x"
    "STM8AF622x"
)
if(${DEVICE} IN_LIST ADC1_PRESENT)
    set(SPL_SOURCES ${SPL_SOURCES} ${SPL_SOURCE_DIR}/stm8s_adc1.c)
endif()
mark_as_advanced(ADC1_PRESENT)

set(ADC2_PRESENT
    "STM8S208"
    "STM8S207"
    "STM8S007"
    "STM8AF52Ax"
    "STM8AF62Ax"
)
if(${DEVICE} IN_LIST ADC2_PRESENT)
    set(SPL_SOURCES ${SPL_SOURCES} ${SPL_SOURCE_DIR}/stm8s_adc2.c)
endif()
mark_as_advanced(ADC2_PRESENT)

set(CAN_PRESENT
    "STM8S208"
    "STM8AF52Ax"
)
if(${DEVICE} IN_LIST CAN_PRESENT)
    set(SPL_SOURCES ${SPL_SOURCES} ${SPL_SOURCE_DIR}/stm8s_can.c)
endif()
mark_as_advanced(CAN_PRESENT)

set(TIM2_PRESENT
    "STM8S208"
    "STM8S207"
    "STM8S007"
    "STM8S103"
    "STM8S003"
    "STM8S001"
    "STM8S105"
    "STM8S005"
    "STM8AF52Ax"
    "STM8AF62Ax"
    "STM8AF626x"
)
if(${DEVICE} IN_LIST TIM2_PRESENT)
    set(SPL_SOURCES ${SPL_SOURCES} ${SPL_SOURCE_DIR}/stm8s_tim2.c)
endif()
mark_as_advanced(TIM2_PRESENT)

set(TIM3_PRESENT
    "STM8S208"
    "STM8S207"
    "STM8S007"
    "STM8S105"
    "STM8S005"
    "STM8AF52Ax"
    "STM8AF62Ax"
    "STM8AF626x"
)
if(${DEVICE} IN_LIST TIM3_PRESENT)
    set(SPL_SOURCES ${SPL_SOURCES} ${SPL_SOURCE_DIR}/stm8s_tim3.c)
endif()
mark_as_advanced(TIM3_PRESENT)

set(TIM4_PRESENT
    "STM8S208"
    "STM8S207"
    "STM8S007"
    "STM8S103"
    "STM8S003"
    "STM8S001"
    "STM8S105"
    "STM8S005"
    "STM8AF52Ax"
    "STM8AF62Ax"
    "STM8AF626x"
)
if(${DEVICE} IN_LIST TIM4_PRESENT)
    set(SPL_SOURCES ${SPL_SOURCES} ${SPL_SOURCE_DIR}/stm8s_tim4.c)
endif()
mark_as_advanced(TIM4_PRESENT)

set(TIM5_6_PRESENT
    "STM8S903"
    "STM8AF622x"
)
if(${DEVICE} IN_LIST TIM5_6_PRESENT)
    set(SPL_SOURCES ${SPL_SOURCES}
        ${SPL_SOURCE_DIR}/stm8s_tim5.c
        ${SPL_SOURCE_DIR}/stm8s_tim6.c
    )
endif()
mark_as_advanced(TIM5_6_PRESENT)

set(UART1_PRESENT
    "STM8S208"
    "STM8S207"
    "STM8S007"
    "STM8S103"
    "STM8S003"
    "STM8S001"
    "STM8S903"
    "STM8AF52Ax"
    "STM8AF62Ax"
)
if(${DEVICE} IN_LIST UART1_PRESENT)
    set(SPL_SOURCES ${SPL_SOURCES} ${SPL_SOURCE_DIR}/stm8s_uart1.c)
endif()
mark_as_advanced(UART1_PRESENT)

set(UART2_PRESENT
    "STM8S105"
    "STM8S005"
    "STM8AF626x"
)
if(${DEVICE} IN_LIST UART2_PRESENT)
    set(SPL_SOURCES ${SPL_SOURCES} ${SPL_SOURCE_DIR}/stm8s_uart2.c)
endif()
mark_as_advanced(UART2_PRESENT)

set(UART3_PRESENT
    "STM8S208"
    "STM8S207"
    "STM8S007"
    "STM8AF52Ax"
)
if(${DEVICE} IN_LIST UART3_PRESENT)
    set(SPL_SOURCES ${SPL_SOURCES} ${SPL_SOURCE_DIR}/stm8s_uart3.c)
endif()
mark_as_advanced(UART3_PRESENT)

set(UART4_PRESENT
    "STM8AF622x"
)
if(${DEVICE} IN_LIST UART4_PRESENT)
    set(SPL_SOURCES ${SPL_SOURCES} ${SPL_SOURCE_DIR}/stm8s_uart4.c)
endif()
mark_as_advanced(UART4_PRESENT)

if(${CMAKE_C_COMPILER_ID} STREQUAL "SDCC")
    set_source_files_properties(${SPL_SOURCE_DIR}/stm8s_itc.c PROPERTIES COMPILE_FLAGS "--disable-warning 59")
    set_source_files_properties(${SPL_SOURCE_DIR}/stm8s_tim2.c PROPERTIES COMPILE_FLAGS "--disable-warning 116")
endif()

add_library(${PROJECT_NAME} STATIC ${SPL_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${SPL_INCLUDE_DIR})
target_compile_definitions(${PROJECT_NAME} PUBLIC ${DEVICE})
