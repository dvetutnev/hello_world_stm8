#include <stm8s.h>


int main(void) {
    GPIO_Init(LED_GPIO_PORT,
              (GPIO_Pin_TypeDef)LED_GPIO_PINS,
              GPIO_MODE_OUT_PP_LOW_FAST);

    TIM4_TimeBaseInit(TIM4_PRESCALER_128, TIM4_ARR_RESET_VALUE);
    TIM4_ClearFlag(TIM4_FLAG_UPDATE);
    TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);

    enableInterrupts();

    TIM4_Cmd(ENABLE);

    for (;;)
        ;
}
