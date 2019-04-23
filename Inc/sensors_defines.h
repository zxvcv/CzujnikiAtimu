#ifndef SENSOR_DEFINES_H
#define SENSOR_DEFINES_H

#define VCC 1
#define GND 0


#define SENSORS_AMOUNT 4

#define READ 0x01
#define WRITE 0x00
#define MULTIPLE_RW 0x80			//dla barometru i magnetometru

//################ CZUJNIK POLOLU ALTIMU-10 ################

//#define SA0_POLOLU GND
#define SA0_POLOLU VCC

#ifndef SA0_POLOLU
	#define SA0_POLOLU GND
#endif

#if SA0_POLOLU == GND
	#define ACC_ADDRESS			0xd4
	#define GYR_ADDRESS			0xd4
	#define BAR_ADDRESS			0xb8
	#define MAG_ADDRESS			0x38
#else
	#define ACC_ADDRESS			0xd6
	#define GYR_ADDRESS			0xd6
	#define BAR_ADDRESS			0xba
	#define MAG_ADDRESS			0x3c
#endif

//################ akcelerometr i zyroskop ################
//AKCELEROMETR (accelerometer)
//rejestry:
#define ACC_CTRL1_XL		0x10     //adres rejestru kontrolnego akcelerometru
#define ACC_CTRL9_XL		0x18     //adres rejestru kontrolnego akcelerometru
#define ACC_OUTX_L_XL		0x28     //adres rejestru danych osi X czesci L
#define ACC_OUTX_H_XL		0x29     //adres rejestru danych osi X czesci H
#define ACC_OUTY_L_XL		0x2a     //adres rejestru danych osi Y czesci L
#define ACC_OUTY_H_XL		0x2b     //adres rejestru danych osi Y czesci H
#define ACC_OUTZ_L_XL		0x2c     //adres rejestru danych osi Z czesci L
#define ACC_OUTZ_H_XL		0x2d     //adres rejestru danych osi Z czesci H
//maski ustawien:
#define ACC_OFF_MASK		0x00     //(CTRL1_XL) maska wylaczajaca wykonywanie pomiarow akcelerometru	  (0000 xxxx)
#define ACC_52HZ_MASK		0x30     //(CTRL1_XL) maska uruchamiajaca akcelerometr z szybkoscia 52Hz	  (0011 xxxx)
#define ACC_104HZ_MASK		0x40     //(CTRL1_XL) maska uruchamiajaca akcelerometr z szybkoscia 104Hz	  (0100 xxxx)
#define ACC_416HZ_MASK		0x60     //(CTRL1_XL) maska uruchamiajaca akcelerometr z szybkoscia 416Hz     (0110 xxxx)
#define ACC_1660HZ_MASK		0x80     //(CTRL1_XL) maska uruchamiajaca akcelerometr z szybkoscia 1.66kHz   (1000 xxxx)
#define ACC_2G_MASK			0x00	 //(CTRL1_XL) maska ustawiajaca zakres pomiarowy na +-2g			  (xxxx 00xx)
#define ACC_16G_MASK		0x04	 //(CTRL1_XL) maska ustawiajaca zakres pomiarowy na +-16g			  (xxxx 01xx)
//inne
#define ACC_DATAREGISTER_NUM	6		//ilosc rejestrow danych akcelerometru

//ZYROSKOP (gyroscope)
//rejestry:
#define GYR_CTRL2_G			0x11	 //adres rejestru kontrolnego zyroskopu
#define GYR_CTRL10_G		0x19 	 //adres rejestru kontrolnego zyroskopu
#define GYR_OUTX_L_G		0x22     //adres rejestru danych osi X czesci L
#define GYR_OUTX_H_G		0x23     //adres rejestru danych osi X czesci H
#define GYR_OUTY_L_G		0x24     //adres rejestru danych osi Y czesci L
#define GYR_OUTY_H_G		0x25     //adres rejestru danych osi Y czesci H
#define GYR_OUTZ_L_G		0x26     //adres rejestru danych osi Z czesci L
#define GYR_OUTZ_H_G		0x27     //adres rejestru danych osi Z czesci H
//maski ustawien:
#define GYR_OFF_MASK		0x00     //(CTRL2_G) maska wylaczajaca wykonywanie pomiarow akcelerometru	  (0000 xxxx)
#define GYR_52HZ_MASK		0x30     //(CTRL2_G) maska uruchamiajaca zyroskop z szybkoscia 52Hz		  	  (0011 xxxx)
#define GYR_104HZ_MASK		0x40     //(CTRL2_G) maska uruchamiajaca zyroskop z szybkoscia 104Hz	  	  (0100 xxxx)
#define GYR_416HZ_MASK		0x60     //(CTRL2_G) maska uruchamiajaca zyroskop z szybkoscia 416Hz      	  (0110 xxxx)
#define GYR_1660HZ_MASK		0x80     //(CTRL2_G) maska uruchamiajaca zyroskop z szybkoscia 1.66kHz    	  (1000 xxxx)
#define GYR_245DPS_MASK		0x00	 //(CTRL2_G) maska ustawiajaca zakres pomiarowy na 245dps			  (xxxx 00xx)
#define GYR_2000DPS_MASK	0x0c	 //(CTRL2_G) maska ustawiajaca zakres pomiarowy na 2000dps			  (xxxx 11xx)
//inne i wspolne
#define ACC_GYR_CTRL3_C		0x12	 //adres rejestru kontrolnego 3
#define ACC_GYR_BDU_MASK	0x40	 //(CTRL3_C) maska block data update (blokowanie zmiany danych podczas odczytu		(x1xx xxxx)
#define GYR_DATAREGISTER_NUM	6		//ilosc rejestrow danych zyroskopu

//################ barometr ################
//BAROMETR (barometer)
//rejestry:
#define BAR_CTRL_REG1		0x20     //adres rejestru kontrolnego barometru
#define BAR_PRESS_OUT_XL	0x28     //adres rejestru danych czesci XL
#define BAR_PRESS_OUT_L		0x29     //adres rejestru danych czesci L
#define BAR_PRESS_OUT_H		0x2a     //adres rejestru danych czesci H
//maski ustawien:
#define BAR_ACTIVE_MODE_MASK	0x80	 //(CTRL_REG1) maska uruchamiajaca barometr (bit PD (power down control)		(1xxx xxxx)
#define BAR_BDU_MASK		0x04	 //(CTRL_REG1) maska block data update (blokowanie zmiany danych podczas odczytu	(xxxx x1xx)
#define BAR_1HZ_MASK		0x10	 //(CTRL_REG1) maska uruchamiajaca probkowanie barometru z szybkoscia 1Hz		(x001 xxxx)
#define BAR_7HZ_MASK		0x20	 //(CTRL_REG1) maska uruchamiajaca probkowanie barometru z szybkoscia 7Hz		(x010 xxxx)
#define BAR_12d5HZ_MASK		0x30	 //(CTRL_REG1) maska uruchamiajaca probkowanie barometru z szybkoscia 12.5Hz	(x011 xxxx)
#define BAR_25HZ_MASK		0x40	 //(CTRL_REG1) maska uruchamiajaca probkowanie barometru z szybkoscia 25Hz		(x100 xxxx)
//inne
#define BAR_DATAREGISTER_NUM	3		//ilosc rejestrow danych akcelerometru


//################ magnetometr ################
//MAGNETOMETR (magnetometer)
//rejestry:
#define MAG_CTRL_REG1		0x20     //adres rejestru kontrolnego magnetometru
#define MAG_CTRL_REG2		0x21     //adres rejestru kontrolnego magnetometru
#define MAG_CTRL_REG3		0x22     //adres rejestru kontrolnego magnetometru
#define MAG_CTRL_REG5		0x24	 //adres rejestru kontrolnego magnetometru
#define MAG_OUTX_L			0x28     //adres rejestru danych osi X czesci L
#define MAG_OUTX_H			0x29     //adres rejestru danych osi X czesci H
#define MAG_OUTY_L			0x2a     //adres rejestru danych osi Y czesci L
#define MAG_OUTY_H			0x2b     //adres rejestru danych osi Y czesci H
#define MAG_OUTZ_L			0x2c     //adres rejestru danych osi Z czesci L
#define MAG_OUTZ_H			0x2d     //adres rejestru danych osi Z czesci H
//maski ustawien:
#define MAG_0d625HZ_MASK	0x00	 //(CTRL_REG1) maska uruchamiajaca probkowanie magnetometru z szybkoscia 0.625Hz tylko single conversion mode	(xxx0 00xx)
#define MAG_1d25HZ_MASK		0x04	 //(CTRL_REG1) maska uruchamiajaca probkowanie magnetometru z szybkoscia 1.25Hz	 tylko single conversion mode	(xxx0 01xx)
#define MAG_2d5HZ_MASK		0x08	 //(CTRL_REG1) maska uruchamiajaca probkowanie magnetometru z szybkoscia 2.5Hz	 tylko single conversion mode	(xxx0 10xx)
#define MAG_5HZ_MASK		0x0c	 //(CTRL_REG1) maska uruchamiajaca probkowanie magnetometru z szybkoscia 5Hz	 tylko single conversion mode	(xxx0 11xx)
#define MAG_10HZ_MASK		0x10	 //(CTRL_REG1) maska uruchamiajaca probkowanie magnetometru z szybkoscia 10Hz	 tylko single conversion mode	(xxx1 00xx)
#define MAG_20HZ_MASK		0x14	 //(CTRL_REG1) maska uruchamiajaca probkowanie magnetometru z szybkoscia 20Hz	 tylko single conversion mode	(xxx1 01xx)
#define MAG_40HZ_MASK		0x18	 //(CTRL_REG1) maska uruchamiajaca probkowanie magnetometru z szybkoscia 40Hz	 tylko single conversion mode	(xxx1 10xx)
#define MAG_80HZ_MASK		0x1c	 //(CTRL_REG1) maska uruchamiajaca probkowanie magnetometru z szybkoscia 80Hz	 tylko single conversion mode	(xxx1 11xx)
#define MAG_155HZ_MASK		0x62	 //(CTRL_REG1) maska uruchamiajaca probkowanie magnetometru z szybkoscia 155Hz	 (x11x xx1x)
#define MAG_300HZ_MASK		0x42	 //(CTRL_REG1) maska uruchamiajaca probkowanie magnetometru z szybkoscia 300Hz	 (x10x xx1x)
#define MAG_560HZ_MASK		0x22	 //(CTRL_REG1) maska uruchamiajaca probkowanie magnetometru z szybkoscia 560Hz	 (x01x xx1x)
#define MAG_1000HZ_MASK		0x02	 //(CTRL_REG1) maska uruchamiajaca probkowanie magnetometru z szybkoscia 1000Hz	 (x00x xx1x)

#define MAG_4G_MASK			0x00	 //(CTRL_REG2) maska uruchamiajaca zakres pomiarowy na +-4 gauss					(x00x xxxx)
#define MAG_8G_MASK			0x20	 //(CTRL_REG2) maska uruchamiajaca zakres pomiarowy na +-8 gauss					(x01x xxxx)
#define MAG_12G_MASK		0x40	 //(CTRL_REG2) maska uruchamiajaca zakres pomiarowy na +-12 gauss					(x10x xxxx)
#define MAG_16G_MASK		0x60	 //(CTRL_REG2) maska uruchamiajaca zakres pomiarowy na +-16 gauss					(x11x xxxx)
#define MAG_CONTINUOUS_MODE_MASK	0x00	//(CTRL_REG3) maska uruchamiajaca magnetometr w trybie ciaglej konwersji		(xxxx xx00)
#define MAG_SINGLE_CONV_MODE_MASK	0x01	//(CTRL_REG3) maska uruchamiajaca magnetometr w trybie pojedynczej konwersji	(xxxx xx01)
#define MAG_POWER_DOWN_MODE_MASK	0x11	//(CTRL_REG3) maska wylaczajaca konwersje										(xxxx xx01)
#define MAG_BDU_MASK		0x80	 //(CTRL_REG5) maska block data update (blokowanie zmiany danych podczas odczytu	(xxxx x1xx)
//inne
#define MAG_DATAREGISTER_NUM	6		//ilosc rejestrow danych akcelerometru





//################ CZUJNIK AM2320 ################

//################ termometr i czujnik wilgotnosci ################
//TERMOMETR (thermometer)
//adres:
#define TRM_ADDRESS			0xb8

//rejestry:

//maski ustawien:

//inne


//CZUJNIK WILGOTNOSCI (humidity sensor)
//adres:
#define HMD_ADDRESS			0xb8

//rejestry:

//maski ustawien:

//inne


#endif //SENSOR_DEFINES_H
