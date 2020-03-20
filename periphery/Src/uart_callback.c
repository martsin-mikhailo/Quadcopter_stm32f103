 #include "stm32f1xx_hal.h"
 #include "dbg_uart.h"
 #include "bt_uart.h"




void HAL_UART_TxCpltCallback (UART_HandleTypeDef *huart) 
{
  if      (huart->Instance == USART2) dbg_uart_TxEndCallback();
  else if (huart->Instance == USART1) bt_uart_TxEndCallback();

}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) 
{
  if      (huart->Instance == USART2) dbg_uart_RxEndCallback();
  else if (huart->Instance == USART1) bt_uart_RxEndCallback();
}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart) 
{
  
}