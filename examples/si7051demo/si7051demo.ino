/**************************************************************************************
This is example for ClosedCube Si7051 ±0.1°C Digital Temperature Sensor breakout board

Initial Date: 15-May-2016

Hardware connections for Arduino Uno:
VDD to 3.3V DC
SCL to A5
SDA to A4
GND to common ground

Written by AA for ClosedCube

MIT License
**************************************************************************************/

#include <Wire.h>
#include "ClosedCube_Si7051.h"

ClosedCube_Si7051 si7051;

void setup()
{
	Serial.begin(9600);
	Serial.println("ClosedCube Si7051 Arduino Test");

	si7051.begin(0x40); // default I2C address is 0x40 and 14-bit measurement resolution

	Serial.print("firmware revision: ");
	switch (si7051.readFirmwareVersion())
	{
	case 0xFF:
		Serial.println("version 1.0");
		break;
	case 0x20:
		Serial.println("version 2.0");
		break;
	default:
		Serial.println("unknow");
			break;
	}

	// si7051.setResolution(<num>), where num = 14,12,13,11-bits, default = 14

}

void loop()
{
	Serial.print("T=");
	Serial.print(si7051.readTemperature());
	Serial.println("C");
	delay(300);
}

