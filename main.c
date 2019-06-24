#include <stdint.h>


#define     __IO    volatile


typedef struct GPIO_struct
{
  __IO uint8_t ODR;
  __IO uint8_t IDR;
  __IO uint8_t DDR;
  __IO uint8_t CR1;
  __IO uint8_t CR2;
} GPIO_TypeDef;

#define GPIOB_BaseAddress       0x5005
#define GPIOB ((GPIO_TypeDef *) GPIOB_BaseAddress)


static void delay(uint32_t t) {
    while (t--) {
    }
}

static volatile uint32_t dummy = 0;

void main(void) {


    GPIOB->DDR = 0xFF;
    GPIOB->CR1 = 0xFF;
    GPIOB->CR2 = 0xFF;
    while(1) {
        GPIOB->ODR = 0xFF;
        delay(10000UL);
        GPIOB->ODR = 0;
        if (dummy % 2) {
            delay(10000UL);
        }
        else {
            delay(10001UL);
        }
        dummy++;
    }
}

