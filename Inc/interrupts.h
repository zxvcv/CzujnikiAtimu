/*
 * interrupts.h
 *
 *  Created on: 15.04.2019
 *      Author: zxvcv
 */

#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include <stdbool.h>
#include "main.h"
#include "stm32f3xx_hal.h"
#include "data_commands.h"
#include "command_manager.h"
#include "sensors_defines.h"

extern I2C_HandleTypeDef hi2c1;
extern TIM_HandleTypeDef htim6;
extern UART_HandleTypeDef huart2;

extern Communication_Data ComData;
extern CommandProperties CmdPrt;

#endif /* INTERRUPTS_H_ */
