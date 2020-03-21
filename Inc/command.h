#ifndef __I3_COMMAND_H
#define __I3_COMMAND_H

#define COMMAND_START       (char)'#'
#define COMMAND_FINISH      (char)';'
#define COMMAND_MAX_LEN     7


#include <stdint.h>


volatile char command_buff[COMMAND_MAX_LEN+1];
volatile uint8_t command_received;


void Command_Proccessing(uint8_t byte);

#endif // __I3_COMMAND_H
