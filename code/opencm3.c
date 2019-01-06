/*
* To use libopencm3 with freeRTOS we need to to define 3 interlude routines.
*/

#include "FreeRTOS.h"
#include "task.h"
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/cm3/nvic.h>

extern void vPortSVCHandler( void ) __attribute__ (( naked ));
extern void xPortPendSVHandler( void ) __attribute__ (( naked ));
extern void xPortSysTickHandler( void );

void sv_call_handler(void) {
  vPortSVCHandler();
  return;
}

void pend_sv_handler(void) {
  xPortPendSVHandler();
  return;
}

void sys_tick_handler(void) {
  xPortSysTickHandler();
  return;
}
