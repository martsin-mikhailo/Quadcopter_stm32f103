 #include "uart.h"
 #include "stm32f1xx_hal.h"
 #include <stdint.h>
 #include <string.h>
 #include <stdarg.h>
 #include <stdio.h>
 #include <stdbool.h>

 #define PRINT_BUFFER_LEN 1024

 extern UART_HandleTypeDef huart2;



void UART_print(char msg[]) 
{
  while(HAL_UART_Transmit_IT(&huart2, (uint8_t*) msg, strlen(msg)) != HAL_OK);

}


void __vprint(const char *fmt, va_list argp)
{
    char string[PRINT_BUFFER_LEN];
    if(0 < vsprintf(string,fmt,argp)) 
    {
        HAL_UART_Transmit_IT(&huart2, (uint8_t*)string, strlen(string));
    }
}

void my_printf(const char *fmt, ...)
{
    va_list argp;
    va_start(argp, fmt);
    __vprint(fmt, argp);
    va_end(argp);
}