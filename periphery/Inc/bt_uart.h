#ifndef __BT_UART_H
#define __BT_UART_H 

 #include "stm32f1xx_hal.h"
 #include <stdint.h>
 #include <string.h>
 #include <stdarg.h>
 #include <stdio.h>
 #include <stdbool.h>



void bt_print(const char *fmt, ...);

void bt_uart_TxEndCallback();
void bt_uart_RxEndCallback();
void bt_uart_start_receiving();



#endif /* __BT_UART_H */ 
