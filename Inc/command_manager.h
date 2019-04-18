#ifndef COMMAND_MANAGER
#define COMMAND_MANAGER

#include <string.h>
#include "data_commands.h"
#include "commands.h"
#include "main.h"
#include "FIFO_str.h"
#include "stm32f3xx_hal.h"

extern struct Communication_Data ComData;
extern UART_HandleTypeDef huart2;

void parse_command(CommandProperties* CmdPrt);

void send_msg_UART();

#endif //COMMAND_MANAGER
