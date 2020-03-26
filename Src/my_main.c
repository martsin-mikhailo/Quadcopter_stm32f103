 #include "my_main.h"
 #include "dbg_uart.h"
 #include "bt_uart.h"
 #include "stm32f1xx_hal.h"
 #include <stdint.h>

extern uint16_t rx_throttle;
extern uint16_t rx_roll;
extern uint16_t rx_pitch;
extern uint16_t rx_yaw;
extern uint8_t command_received;

extern TIM_HandleTypeDef htim3;

void my_main()
{
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
  
    dbg_print("MCU start");
    while(1)
    {
        // dbg_print("ROLL     [%d]\n", rx_roll);
        // dbg_print("PITCH    [%d]\n", rx_pitch);
        // dbg_print("YAW      [%d]\n", rx_yaw);
        // dbg_print("THROTTLE [%d]\n\n", rx_throttle);
        __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, rx_roll);
        __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, rx_pitch);
        __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, rx_yaw);
        __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, rx_throttle);
        // HAL_Delay(100);
        
    }
    
}