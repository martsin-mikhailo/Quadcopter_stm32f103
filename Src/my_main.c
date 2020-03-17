 #include "my_main.h"
 #include "dbg_uart.h"
 #include "stm32f1xx_hal.h"
 #include <stdint.h>



void my_main()
{
    my_printf("MCU_START\n");
    while(1)
    {
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_3);
        HAL_Delay(500);
    }
    
}