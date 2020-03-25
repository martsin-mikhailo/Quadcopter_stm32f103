#include "command.h"
#include "stdint.h"
#include <stdlib.h>
#include <stdio.h>


static volatile uint8_t command_buff_p = 0;
volatile char command_buff[COMMAND_MAX_LEN+1] = {0};
volatile uint8_t command_received = 0;

uint16_t rx_throttle = 0;
uint16_t rx_roll     = 0;
uint16_t rx_pitch    = 0;
uint16_t rx_yaw      = 0;

uint8_t rx_command   = 0;
char temp[5] = {0};

typedef enum {
  COMMAND_INVALID = 0,
  CMD_ROLL,
  CMD_PITCH,
  CMD_YAW,
  CMD_THROTTLE
} command_enum;


void Command_Proccessing(uint8_t byte) 
{
  if (command_buff_p > COMMAND_MAX_LEN+1) command_buff_p = 0;
  switch (byte) 
  {
    case COMMAND_FINISH:
      command_buff[command_buff_p] = '\0';
      command_buff_p = 0;
      command_received = 1;
      break;
    case COMMAND_ROLL:
      command_buff_p = 0;
      command_received = 0;
      rx_command = CMD_ROLL;
      break;
    case COMMAND_PITCH:
      command_buff_p = 0;
      command_received = 0;
      rx_command = CMD_PITCH;
      break;
    case COMMAND_YAW:
      command_buff_p = 0;
      command_received = 0;
      rx_command = CMD_YAW;
      break;
    case COMMAND_THROTTLE:
      command_buff_p = 0;
      command_received = 0;
      rx_command = CMD_THROTTLE;
      break;
    default:
      command_buff[command_buff_p++] = byte;
      break;
  }

  if(command_received == 1)
  {
    switch (rx_command)
    {
    case CMD_ROLL:
    {
      char temp[5] = {command_buff[0], command_buff[1], command_buff[2], command_buff[3], '\0'};
      rx_roll = atoi(temp);
      break;
    }
    case CMD_PITCH:
    {
      char temp[5] = {command_buff[0], command_buff[1], command_buff[2], command_buff[3], '\0'};
      rx_pitch = atoi(temp);
      break;
    }
    case CMD_YAW:
    {
      char temp[5] = {command_buff[0], command_buff[1], command_buff[2], command_buff[3], '\0'};
      rx_yaw = atoi(temp);
      break;
    }
     case CMD_THROTTLE:
    {
      char temp[5] = {command_buff[0], command_buff[1], command_buff[2], command_buff[3], '\0'};
      rx_throttle = atoi(temp);
      break;
    }        
    
    default:
      break;
    }
    command_received = 0;
  }
}
