 #include "dbg_uart.h"


 #define PRINT_BUFFER_LEN 1024

 extern UART_HandleTypeDef huart2;

 static volatile uint8_t uart_busy_flag = 0;

void dbg_uart_TxEndCallback() {
  uart_busy_flag = 0;
}

static void __vprint(const char *fmt, va_list argp)
{
    char string[PRINT_BUFFER_LEN];
    if(0 < vsprintf(string,fmt,argp)) 
    {
        while(HAL_UART_Transmit_IT(&huart2, (uint8_t*)string, strlen(string)) != HAL_OK);
    }
}

void dbg_print(const char *fmt, ...)
{
    while(uart_busy_flag);
    va_list argp;
    va_start(argp, fmt);
    __vprint(fmt, argp);
    va_end(argp);
    uart_busy_flag = 1;
}
