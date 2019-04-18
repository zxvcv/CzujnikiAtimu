#include "commands.h"



bool stop(CommandProperties* CmdPrt)
{
	uint8_t out[40];
	uint8_t out_size = sprintf((char*)out, "STOP: |%d|X|%hu|%hu|%d|X|%d|%d|%d|%d|\n", CmdPrt->command_set,
																			CmdPrt->mesures.measurments_num,
																			CmdPrt->mesures.measurments_speed,
																			CmdPrt->mesures.infinite_measurments,
																			CmdPrt->active_sensors.accelerometer,
																			CmdPrt->active_sensors.gyroscope,
																			CmdPrt->active_sensors.barometer,
																			CmdPrt->active_sensors.magnetometer);

	if(out_size >= OUT_BUFF_SIZE)
		out[OUT_BUFF_SIZE - 1] = '\0';
	ListStr_Push_C(ComData.out_commands, (char*)out, out_size);

	ComData.stop_recieved = false;
	CmdPrt->command_set = false;
	return true;
}

bool measure(CommandProperties* CmdPrt)
{
	if(CmdPrt->command_set == true && ComData.tim6state == false)
	{
		uint8_t out[40];
		uint8_t out_size;
		//sprawdzenie ustawien

		out_size = sprintf((char*) out, "MEASURE BEGIN %d%d%d%d %hu\n",	CmdPrt->active_sensors.accelerometer,
																CmdPrt->active_sensors.gyroscope,
																CmdPrt->active_sensors.barometer,
																CmdPrt->active_sensors.magnetometer,
																CmdPrt->mesures.measurments_num);
		ListStr_Push_C(ComData.out_commands, (char*) out, out_size);


		ComData.timDivision = 0;
		HAL_TIM_Base_Start_IT(&htim6);
		ComData.tim6state = true;
		return true;
	}

	if(CmdPrt->command_set == true && CmdPrt->mesures.infinite_measurments == false && CmdPrt->mesures.measurments_num <= 0)
	{
		uint8_t out[40];
		uint8_t out_size;

		out_size = sprintf((char*) out, "MEASURE END.M %d%d%d%d %hu\n",	CmdPrt->active_sensors.accelerometer,
																CmdPrt->active_sensors.gyroscope,
																CmdPrt->active_sensors.barometer,
																CmdPrt->active_sensors.magnetometer,
																CmdPrt->mesures.measurments_num);
		ListStr_Push_C(ComData.out_commands, (char*) out, out_size);

		CmdPrt->command_set = false;
		return true;
	}
	return false;
}

bool settings(CommandProperties* CmdPrt)
{
	//-----operacje BEGIN
	uint8_t out[40];
	uint8_t out_size = sprintf((char*)out, "settings: |%d|\n|%hu|%hu|%d|\n|%d|%d|%d|%d|\n", CmdPrt->command_set,
																				CmdPrt->mesures.measurments_num,
																				CmdPrt->mesures.measurments_speed,
																				CmdPrt->mesures.infinite_measurments,
																				CmdPrt->active_sensors.accelerometer,
																				CmdPrt->active_sensors.gyroscope,
																				CmdPrt->active_sensors.barometer,
																				CmdPrt->active_sensors.magnetometer);
	ListStr_Push_C(ComData.out_commands, (char*)out, out_size);
	//-----operacje END

	CmdPrt->command_set = false;
	return true;
}
