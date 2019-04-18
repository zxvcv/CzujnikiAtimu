#ifndef SENSOR_DEFINES_H
#define SENSOR_DEFINES_H

#define SENSORS_AMOUNT 4

#define READ 0x01
#define WRITE 0x00

//################ akcelerometr i zyroskop ################
//AKCELEROMETR (accelerometer)
//adres:
#define ACC_ADDRESS			0xd4
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
//adres:
#define GYR_ADDRESS			0xd4
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
//inne
#define GYR_DATAREGISTER_NUM	6		//ilosc rejestrow danych zyroskopu

//################ barometr ################
//BAROMETR (barometer)
//adres:
#define BAR_ADDRESS			0xb8
//rejestry:
#define BAR_CTRL_REG1		0x20     //adres rejestru kontrolnego barometru
#define BAR_PRESS_OUT_XL	0x28     //adres rejestru danych czesci XL
#define BAR_PRESS_OUT_L		0x29     //adres rejestru danych czesci L
#define BAR_PRESS_OUT_H		0x2a     //adres rejestru danych czesci H
//maski ustawien:
//...
//inne
#define BAR_DATAREGISTER_NUM	3		//ilosc rejestrow danych akcelerometru


//################ magnetometr ################
//MAGNETOMETR (magnetometer)
//adres:
#define MAG_ADDRESS			0x38
//rejestry:
#define MAG_CTRL_REG1		0x20     //adres rejestru kontrolnego magnetometru
#define MAG_CTRL_REG2		0x21     //adres rejestru kontrolnego magnetometru
#define MAG_CTRL_REG3		0x22     //adres rejestru kontrolnego magnetometru
#define MAG_OUTX_L			0x28     //adres rejestru danych osi X czesci L
#define MAG_OUTX_H			0x29     //adres rejestru danych osi X czesci H
#define MAG_OUTY_L			0x2a     //adres rejestru danych osi Y czesci L
#define MAG_OUTY_H			0x2b     //adres rejestru danych osi Y czesci H
#define MAG_OUTZ_L			0x2c     //adres rejestru danych osi Z czesci L
#define MAG_OUTZ_H			0x2d     //adres rejestru danych osi Z czesci H
//maski ustawien:
//...
//inne
#define MAG_DATAREGISTER_NUM	6		//ilosc rejestrow danych akcelerometru


#endif //SENSOR_DEFINES_H
