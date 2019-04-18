/*
 * data_commands.c
 *
 *  Created on: 07.04.2019
 *      Author: zxvcv
 */

#include "data_commands.h"

void CommandPropertiesClear(CommandProperties* CmdPrt)
{
	CmdPrt->active_sensors.accelerometer = false;
	CmdPrt->active_sensors.barometer = false;
	CmdPrt->active_sensors.gyroscope = false;
	CmdPrt->active_sensors.magnetometer = false;

	CmdPrt->command = NULL;
	CmdPrt->command_set = false;

	CmdPrt->mesures.infinite_measurments = false;
	CmdPrt->mesures.measurments_num = 0;
	CmdPrt->mesures.measurments_speed = 0;
}
