#include "command.h"


static volatile uint8_t command_buff_p = 0;
volatile char command_buff[COMMAND_MAX_LEN+1] = {0};
volatile uint8_t command_received = 0;


void Command_Proccessing(uint8_t byte) 
{
  if (command_buff_p > COMMAND_MAX_LEN+1) command_buff_p = 0;
  switch (byte) 
  {
    case COMMAND_FINISH:
      command_buff[command_buff_p] = '\0';
      command_received = 1;
      command_buff_p = 0;
      break;
    case COMMAND_START:
      command_buff_p = 0;
      command_received = 0;
      break;
    default:
      command_buff[command_buff_p++] = byte;
      break;
  }
}
