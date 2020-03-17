 #include "stm32f1xx_hal.h"
 #include "dbg_uart.h"


extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart1;


void HAL_UART_TxCpltCallback (UART_HandleTypeDef *huart) 
{
  if      (huart->Instance == USART2) dbg_uart_TxEndCallback();
  //else if (huart->Instance == USART1) //TODO поставити колбек блютуз

}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) 
{
  if      (huart->Instance == USART2) dbg_uart_RxEndCallback();
  //else if (huart->Instance == USART1) //TODO поставити колбек блютуз
}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart) 
{
  
}