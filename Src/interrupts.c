/*
 * interrupts.c
 *
 *  Created on: 15.04.2019
 *      Author: zxvcv
 */
#include "interrupts.h"



void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
	if(huart2.gState != HAL_UART_STATE_BUSY_TX && ListStr_GetSize(ComData.out_commands) != 0)
	{
		send_msg_UART();
	}
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
	if(ComData.data_received == '\n')
	{
		ComData.in_data[ComData.in_counter] = '\0';

		if(strncmp((char*)ComData.in_data, "stp", 3) == 0) //jezeli otrzymano polecenie stop wykonaj natychmiast
		{
			ComData.stop_recieved = true;
			ComData.in_counter = 0;
			HAL_UART_Receive_IT(&huart2, &(ComData.data_received), 1);
			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
			return;
		}
		else
		{
			ListStr_Push_C(ComData.in_commands, (char*)ComData.in_data, strlen((char*)ComData.in_data));
			ComData.in_counter = 0;
		}
	}
	else if(ComData.in_counter < IN_BUFF_SIZE - 1)
	{
		ComData.in_data[ComData.in_counter++] = ComData.data_received;
	}

	HAL_UART_Receive_IT(&huart2, &(ComData.data_received), 1);
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
}


void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
	if(ListStr_GetSize(ComData.out_commands) != 0)
	{
		send_msg_UART();
	}
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
}


void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
	//HAL_UART_Receive_IT(&huart2, &data_received, 1);
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(ComData.timDivision >= CmdPrt.mesures.measurments_speed)
	{
		if(false)//poprzedni pomiar sie nie skonczyl jeszcze (i2c nasluchuje danych)
		{
			return;
		}

		if(CmdPrt. mesures.infinite_measurments == false && CmdPrt.mesures.measurments_num <= 0)
		{
			//CmdPrt.command_set = false;
			HAL_TIM_Base_Stop_IT(&htim6);
			ComData.tim6state = false;
		}

		if(CmdPrt.command_set == true)
		{
			ComData.msrSensLeft.accelerometer = CmdPrt.active_sensors.accelerometer;
			ComData.msrSensLeft.gyroscope = CmdPrt.active_sensors.gyroscope;
			ComData.msrSensLeft.barometer = CmdPrt.active_sensors.barometer;
			ComData.msrSensLeft.magnetometer = CmdPrt.active_sensors.magnetometer;

			if (ComData.msrSensLeft.accelerometer == true) {
				ComData.msrSensLeft.accelerometer = false;
				HAL_I2C_Mem_Read_IT(&hi2c1, ACC_ADDRESS, ACC_OUTX_L_XL, 1, ComData.measurements.accelerometrData, ACC_DATAREGISTER_NUM);
			} else if (ComData.msrSensLeft.gyroscope == true) {
				ComData.msrSensLeft.gyroscope = false;
				HAL_I2C_Mem_Read_IT(&hi2c1, GYR_ADDRESS, GYR_OUTX_L_G, 1, ComData.measurements.gyroscopeData, GYR_DATAREGISTER_NUM);
			} else if (ComData.msrSensLeft.barometer == true) {
				ComData.msrSensLeft.barometer = false;
				HAL_I2C_Mem_Read_IT(&hi2c1, BAR_ADDRESS, BAR_PRESS_OUT_XL, 1, ComData.measurements.barometerData, BAR_DATAREGISTER_NUM);
			} else if (ComData.msrSensLeft.magnetometer == true) {
				ComData.msrSensLeft.magnetometer = false;
				HAL_I2C_Mem_Read_IT(&hi2c1, MAG_ADDRESS, MAG_OUTX_L, 1, ComData.measurements.magnetometerData, MAG_DATAREGISTER_NUM);
			}
		}

		ComData.timDivision = 0;
	}
	else
	{
		++ComData.timDivision;
	}
}


void HAL_I2C_MemRxCpltCallback(I2C_HandleTypeDef *hi2c)
{
	if (ComData.msrSensLeft.accelerometer == true) {
		ComData.msrSensLeft.accelerometer = false;
		HAL_I2C_Mem_Read_IT(&hi2c1, ACC_ADDRESS, ACC_OUTX_L_XL, 1, ComData.measurements.accelerometrData, ACC_DATAREGISTER_NUM);
	} else if (ComData.msrSensLeft.gyroscope == true) {
		ComData.msrSensLeft.gyroscope = false;
		HAL_I2C_Mem_Read_IT(&hi2c1, GYR_ADDRESS, GYR_OUTX_L_G, 1, ComData.measurements.gyroscopeData, GYR_DATAREGISTER_NUM);
	} else if (ComData.msrSensLeft.barometer == true) {
		ComData.msrSensLeft.barometer = false;
		HAL_I2C_Mem_Read_IT(&hi2c1, BAR_ADDRESS, BAR_PRESS_OUT_XL, 1, ComData.measurements.barometerData, BAR_DATAREGISTER_NUM);
	} else if (ComData.msrSensLeft.magnetometer == true) {
		ComData.msrSensLeft.magnetometer = false;
		HAL_I2C_Mem_Read_IT(&hi2c1, MAG_ADDRESS, MAG_OUTX_L, 1, ComData.measurements.magnetometerData, MAG_DATAREGISTER_NUM);
	} else {
		--CmdPrt.mesures.measurments_num;
		ListStr_Push_C(ComData.out_commands, "### msr: ###\n", 13);

		uint8_t out[40];
		uint8_t out_size;
		int16_t work16;
		//int32_t work32;
		float measure_outputX;
		float measure_outputY;
		float measure_outputZ;

		if(CmdPrt.active_sensors.accelerometer == true)
		{
			work16 = ((ComData.measurements.accelerometrData[1] << 8) | ComData.measurements.accelerometrData[0]);
			measure_outputX = ((float) work16 * 2.0) / (float) INT16_MAX;
			work16 = ((ComData.measurements.accelerometrData[3] << 8) | ComData.measurements.accelerometrData[2]);
			measure_outputY = ((float) work16 * 2.0) / (float) INT16_MAX;
			work16 = ((ComData.measurements.accelerometrData[5] << 8) | ComData.measurements.accelerometrData[4]);
			measure_outputZ = ((float) work16 * 2.0) / (float) INT16_MAX;
			out_size = sprintf((char*)out, "acc: X:%.3f Y:%.3f Z:%.3f\n", measure_outputX, measure_outputY, measure_outputZ);
			ListStr_Push_C(ComData.out_commands, (char*)out, out_size);
		}
		if(CmdPrt.active_sensors.gyroscope == true)
		{
			work16 = ((ComData.measurements.gyroscopeData[1] << 8) | ComData.measurements.gyroscopeData[0]);
			measure_outputX = ((float) work16 * 245) / (float) INT16_MAX;
			work16 = ((ComData.measurements.gyroscopeData[3] << 8) | ComData.measurements.gyroscopeData[2]);
			measure_outputY = ((float) work16 * 245) / (float) INT16_MAX;
			work16 = ((ComData.measurements.gyroscopeData[5] << 8) | ComData.measurements.gyroscopeData[4]);
			measure_outputZ = ((float) work16 * 245) / (float) INT16_MAX;
			out_size = sprintf((char*)out, "gyr: X:%.3f Y:%.3f Z:%.3f\n", measure_outputX, measure_outputY, measure_outputZ);
			ListStr_Push_C(ComData.out_commands, (char*)out, out_size);
		}
		if(CmdPrt.active_sensors.barometer == true)
		{
			//obliczenia
			//sprintf((char*)out, "acc: X:%f Y:%f Z:%f\n%c", measure_outputX, measure_outputY, measure_outputZ, '\0');
			//ListStr_Push_C(ComData.out_commands, (char*)out);
		}
		if(CmdPrt.active_sensors.magnetometer == true)
		{
			//obliczenia
			//sprintf((char*)out, "acc: X:%f Y:%f Z:%f\n%c", measure_outputX, measure_outputY, measure_outputZ, '\0');
			//ListStr_Push_C(ComData.out_commands, (char*)out);
		}
		//dodac sprawdzenie czy nie ma alokacji pamieci za duzej
	}
}



//void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c) {
//	ListStr_Push_C(ComData.out_commands, "ErrorCallback\n");
//}
//
//void HAL_I2C_AbortCpltCallback(I2C_HandleTypeDef *hi2c) {
//	ListStr_Push_C(ComData.out_commands, "AbortCpltCallback\n");
//}
//
//void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *hi2c) {
//	ListStr_Push_C(ComData.out_commands, "MasterTxCpltCallback\n");
//}
//
//void HAL_I2C_MasterRxCpltCallback(I2C_HandleTypeDef *hi2c) {
//	ListStr_Push_C(ComData.out_commands, "HAL_I2C_MasterRxCpltCallback\n");
//}
//void HAL_I2C_SlaveTxCpltCallback(I2C_HandleTypeDef *hi2c) {
//	ListStr_Push_C(ComData.out_commands, "HAL_I2C_SlaveTxCpltCallback\n");
//}
//
//void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c) {
//	ListStr_Push_C(ComData.out_commands, "HAL_I2C_SlaveRxCpltCallback\n");
//}
//
//void HAL_I2C_AddrCallback(I2C_HandleTypeDef *hi2c, uint8_t TransferDirection,
//		uint16_t AddrMatchCode) {
//	ListStr_Push_C(ComData.out_commands, "HAL_I2C_AddrCallback\n");
//}
//
//void HAL_I2C_ListenCpltCallback(I2C_HandleTypeDef *hi2c) {
//	ListStr_Push_C(ComData.out_commands, "HAL_I2C_ListenCpltCallback\n");
//}
//
//void HAL_I2C_MemTxCpltCallback(I2C_HandleTypeDef *hi2c) {
//	ListStr_Push_C(ComData.out_commands, "HAL_I2C_MemTxCpltCallback\n");
//}
