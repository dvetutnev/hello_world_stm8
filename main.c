#include "delay.h"
#include <stdint.h>


typedef struct SGPIO
{
    volatile uint8_t ODR;
    volatile uint8_t IDR;
    volatile uint8_t DDR;
    volatile uint8_t CR1;
    volatile uint8_t CR2;
} GPIO;

#define GPIOB_BaseAddress 0x5005
#define GPIOB ((GPIO*) GPIOB_BaseAddress)


static uint8_t i;
static uint32_t i2;

void main(void) {
    GPIOB->DDR = 0xFF;
    GPIOB->CR1 = 0xFF;
    GPIOB->CR2 = 0xFF;

    for (;;) {
        GPIOB->ODR = 0xFF;
        delay(10000UL);
        GPIOB->ODR = 0;
        delay(10000UL);
    }
}

