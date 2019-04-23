/*
 * data_commands.h
 *
 *  Created on: 07.04.2019
 *      Author: zxvcv
 */

#ifndef DATA_COMMANDS_H_
#define DATA_COMMANDS_H_

#include <stdbool.h>
#include "stm32f3xx_hal.h"
#include "FIFO_str.h"
#include "sensors_defines.h"

#define IN_BUFF_SIZE 40
#define OUT_BUFF_SIZE 53



typedef struct SENSORS{
	bool accelerometer;
	bool gyroscope;
	bool barometer;
	bool magnetometer;
} Sensors;


typedef struct Measurements{
	uint8_t accelerometrData[ACC_DATAREGISTER_NUM];
	uint8_t gyroscopeData[GYR_DATAREGISTER_NUM];
	uint8_t barometerData[BAR_DATAREGISTER_NUM];
	uint8_t magnetometerData[MAG_DATAREGISTER_NUM];
}Measurements;


typedef struct Communication_Data{
	List_str* in_commands;
	List_str* out_commands;

	uint8_t in_data[IN_BUFF_SIZE];
	uint8_t out_data[OUT_BUFF_SIZE];

	uint8_t in_counter;

	uint8_t data_received;
	bool stop_recieved;

	bool tim6state;
	uint16_t timDivision;

	Sensors msrSensLeft;

	Measurements measurements;
}Communication_Data;





struct CommandProperties;


typedef enum SENSOR {
	NONE = 0,
	ACCELEROMETER = 1,
	GYROSCOPE = 2,
	BAROMETER = 3,
	MAGNETOMETER = 4
} SENSOR;


typedef bool(*exe_ptr)(struct CommandProperties*);


typedef struct CommandProperties{
	bool command_set;

	exe_ptr command;			//wskaznik na komende do wywolania

	Sensors active_sensors;		//aktywne czujniki

	struct{
		uint16_t measurments_num;	//ilosc pomiarow ktore zostaly jeszcze do wykonania
		uint16_t measurments_speed;	//odstep w [ms] od kolejnych pomiarow
		bool infinite_measurments;	//czy pomiary sa wykonywane w nieskonczonosc (ma priorytet nad measurments_num)
	}mesures;			//dane do pomiarow
}CommandProperties;



//--------------functions

void CommandPropertiesClear(CommandProperties* CmdPrt);

#endif /* DATA_COMMANDS_H_ */
