#include "command_manager.h"


void parse_command(CommandProperties* CmdPrt)
{
	char name[3];

	sscanf(ListStr_Front(ComData.in_commands), "%3s %*s", name);

	CommandPropertiesClear(CmdPrt);
	//CmdPrt->command = NULL;

	if(strncmp(name, "stp", 3) == 0)
	{
		CmdPrt->command = stop;
		CmdPrt->command_set = true;
	}
	else if(strncmp(name, "msr", 3) == 0)
	{

		CmdPrt->command = measure;

		int sensors = 0;
		sscanf(ListStr_Front(ComData.in_commands), "%*s -S%d -N%hu -T%hu", &sensors, &CmdPrt->mesures.measurments_num, &CmdPrt->mesures.measurments_speed);
		ComData.timDivision = CmdPrt->mesures.measurments_speed - 1;

		//CmdPrt->active_sensors.accelerometer = false;
		//CmdPrt->active_sensors.gyroscope = false;
		//CmdPrt->active_sensors.barometer = false;
		//CmdPrt->active_sensors.magnetometer = false;
		while(sensors > 0)
		{
			SENSOR sns = sensors % 10;
			switch(sns)
			{
			case ACCELEROMETER:
				CmdPrt->active_sensors.accelerometer = true;
				break;
			case GYROSCOPE:
				CmdPrt->active_sensors.gyroscope = true;
				break;
			case BAROMETER:
				CmdPrt->active_sensors.barometer = true;
				break;
			case MAGNETOMETER:
				CmdPrt->active_sensors.magnetometer = true;
				break;
			default:
				//CmdPrt->command_set = false;
				return;
			}
			sensors /= 10;
		}

		if(CmdPrt->mesures.measurments_num == 0)
			CmdPrt->mesures.infinite_measurments = true;

		CmdPrt->command_set = true;
	}
	else if(strncmp(name, "set", 3) == 0)
	{
		//chwilowo nieobslugiwane (nic nie robi)
		CmdPrt->command = settings;

		//CmdPrt->active_sensors.accelerometer = false;
		//CmdPrt->active_sensors.barometer = false;
		//CmdPrt->active_sensors.gyroscope = false;
		//CmdPrt->active_sensors.magnetometer = false;

		//CmdPrt->mesures.infinite_measurments = false;
		//CmdPrt->mesures.measurments_num = 0;
		//CmdPrt->mesures.measurments_speed = 0;

		CmdPrt->command_set = true;
	}
	else
	{
		CmdPrt->command_set = false;
	}

	ListStr_Pop_C(ComData.in_commands);
}


void send_msg_UART()
{
	uint8_t out_data_size = snprintf((char*)ComData.out_data,  OUT_BUFF_SIZE, "%s%c%c", ListStr_Front(ComData.out_commands), '\r', '\n');
	ComData.out_data[OUT_BUFF_SIZE - 3] = '\r';
	ComData.out_data[OUT_BUFF_SIZE - 2] = '\n';
	ComData.out_data[OUT_BUFF_SIZE - 1] = '\0';
	out_data_size = out_data_size < OUT_BUFF_SIZE ? out_data_size : OUT_BUFF_SIZE;
	HAL_UART_Transmit_IT(&huart2, ComData.out_data, out_data_size);

	ListStr_Pop_C(ComData.out_commands);
}
