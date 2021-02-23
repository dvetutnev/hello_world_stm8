#ifndef BGRT_CONFIG_H
/*This is example config file*/
#define BGRT_CONFIG_H
/**================================================================*/
/**               Don't edit this part of the file!!!              */
/**================================================================*/
#define BGRT_SC_TBL(a) const bgrt_scsr_t a
#define BGRT_SC_TBL_READ(a) a

#define WEAK
#define NOP()                     __asm__("nop")

typedef unsigned char bgrt_stack_t;

/**================================================================*/
/**               Edit this part carefully!!!                                     */
/**================================================================*/

/* Max priority levels are defined by bgrt_map_t,*/
/* you must specify BGRT_BITS_IN_INDEX_T to show*/
/* how many levels you actually are going to use.*/
typedef unsigned char bgrt_map_t;
#define BGRT_BITS_IN_INDEX_T (8)

/* Even if bgrt_map_t is unsigned long long,*/
/* there will be only 64 priority levels available,*/
/* so unsigned char is always enough.*/
typedef unsigned char bgrt_prio_t;

/* Unsigned char is enough.*/
typedef unsigned char bgrt_flag_t;
/* unsigned char is enough.*/
typedef unsigned char bgrt_st_t;
/*For STM8 only 64Kib of stack space*/
/* may be available, so bgrt_cnt_t can be*/
/* unsigned char or unsigned short.*/
/* Unsigned short is enough.*/
#define BGRT_CONFIG_CNT_MAX (0xffff)
typedef unsigned short bgrt_cnt_t;

/* You can specify any unsigned type here. */
typedef unsigned short bgrt_tmr_t;

/* Unsigned char is enough.*/
/* There is no reason to make it bigger.*/
typedef unsigned char bgrt_bool_t;

/* Unsigned char is enough.*/
/* There is no reason to make it bigger.*/
typedef volatile unsigned char bgrt_syscall_t;
/*=================================================================*/
/**     BuguRTOS behavior compilation flags, edit carefully!!!    */
/*=================================================================*/
#define BGRT_CONFIG_HARD_RT
/*=================================================================*/
/*     Project specific stuff, you are welcome to edit it!!!   */
/*=================================================================*/

#define INT_TIM4_CHANGE 23
#define BGRT_SYSTEM_TIMER_VECTOR INT_TIM4_CHANGE

#include <stm8s.h>

#define BGRT_SYSTEM_TIMER_INTERRUPT_CLEAR() (TIM4_ClearITPendingBit(TIM4_IT_UPDATE))
//#define BGRT_STOP_SCHEDULER() (TIM4_IER = 0x00)
//#define BGRT_START_SCHEDULER() (TIM4_IER = 0x01)

#define BGRT_PROC_STACK_SIZE (160)

#define LOWEST (BGRT_BITS_IN_INDEX_T - 1)

/**================================================================*/
/**               Don't edit this part of the file!!!              */
/**================================================================*/

extern void kernel_preemt_hook(void);
#define BGRT_KERNEL_PREEMPT() kernel_preemt_hook()

#endif /*BGRT_CONFIG_H*/
