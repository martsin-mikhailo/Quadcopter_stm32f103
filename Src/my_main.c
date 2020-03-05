 #include "my_main.h"
 #include "uart.h"
 #include "stm32f1xx_hal.h"
 #include <stdint.h>


uint32_t num = 12;
float fl = 1.2;

void my_main()
{
    while(1)
    {
        HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
        //UART_print("start");
        my_printf("dbg %f\n", fl);
        // uart_print("qwery %d", num);
        //HAL_Delay(1);
    }
    
}