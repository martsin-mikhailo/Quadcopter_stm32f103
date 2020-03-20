 #include "bt_uart.h"


 #define PRINT_BUFFER_LEN 1024

 extern UART_HandleTypeDef huart1;

 static volatile uint8_t uart_busy_flag = 0;


// void bt_uart_start_receiving() {
//   while(HAL_UART_Receive_IT(&huart2, &byte_buff, 1) != HAL_OK);
// }


void bt_uart_TxEndCallback() {
  uart_busy_flag = 0;
}

void bt_uart_RxEndCallback() {
  //TODO обробка прийнятого байту
  //HAL_UART_Receive_IT(&huart6, &byte_buff, 1);
}


static void __vprint(const char *fmt, va_list argp)
{
    char string[PRINT_BUFFER_LEN];
    if(0 < vsprintf(string,fmt,argp)) 
    {
        while(uart_busy_flag);
        uart_busy_flag = 1;
        while(HAL_UART_Transmit_IT(&huart1, (uint8_t*)string, strlen(string)) != HAL_OK);
    }
}

void bt_print(const char *fmt, ...)
{
    va_list argp;
    va_start(argp, fmt);
    __vprint(fmt, argp);
    va_end(argp);
}
