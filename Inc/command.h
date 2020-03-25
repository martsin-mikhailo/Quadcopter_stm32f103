#ifndef __I3_COMMAND_H
#define __I3_COMMAND_H

#define COMMAND_FINISH      (char)';'
#define COMMAND_MAX_LEN     6

//comand controll
#define COMMAND_ROLL          (char)'R'
#define COMMAND_PITCH         (char)'P'
#define COMMAND_YAW           (char)'Y'
#define COMMAND_THROTTLE      (char)'T'




#include <stdint.h>


volatile char command_buff[COMMAND_MAX_LEN+1];
volatile uint8_t command_received;


void Command_Proccessing(uint8_t byte);

#endif // __I3_COMMAND_H
