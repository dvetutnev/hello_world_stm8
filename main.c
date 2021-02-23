#include <stm8s.h>
#include <native.h>


bgrt_proc_t process;
bgrt_stack_t stack[BGRT_PROC_STACK_SIZE];

void initHW();
void pmain(void*);

int main() {
    initHW();
    bgrt_init();

    bgrt_priv_proc_init(
                &process,
                pmain,
                (bgrt_code_t) 0, /* sv_hook */
                (bgrt_code_t) 0, /* rs_hook */
                0, /* arg */
                &stack[BGRT_PROC_STACK_SIZE-1],
                (bgrt_prio_t) 1, /* priority */
                (bgrt_tmr_t) 1, /* time slice */
                (bgrt_bool_t) 0 /* is realtime */
            );
    bgrt_priv_proc_run(&process);

    bgrt_start();

    return 0;
}

void pmain(void* arg) {
    (void) arg;

    for(;;) {
        GPIO_WriteReverse(LED_GPIO_PORT,
                         (GPIO_Pin_TypeDef)LED_GPIO_PINS);
        bgrt_wait_time(300);
    }
}

void initHW() {
    GPIO_Init(LED_GPIO_PORT,
              (GPIO_Pin_TypeDef)LED_GPIO_PINS,
              GPIO_MODE_OUT_PP_LOW_FAST);

    /*
     * Current frenq master clock: 16MHz HSI / 8 (default prescaler) = 2MHz
     * Irq overflow frenq: 2MHz / 8 / 256 (8 bits counter) = ~1kHz
    */

    TIM4_TimeBaseInit(TIM4_PRESCALER_8, TIM4_ARR_RESET_VALUE);
    TIM4_ClearFlag(TIM4_FLAG_UPDATE);
    TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);

    enableInterrupts();

    TIM4_Cmd(ENABLE);
}

void kernel_preemt_hook() {
    NOP();
}
