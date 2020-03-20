#ifndef __DBG_UART_H
#define __DBG_UART_H 

 #include "stm32f1xx_hal.h"
 #include <stdint.h>
 #include <string.h>
 #include <stdarg.h>
 #include <stdio.h>
 #include <stdbool.h>



void dbg_print(const char *fmt, ...);

void dbg_uart_TxEndCallback();
void dbg_uart_RxEndCallback();



#endif /* __DBG_UART_H */ 
