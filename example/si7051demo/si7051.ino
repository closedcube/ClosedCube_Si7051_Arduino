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

	si7051.begin(0x40);	
}

void loop()
{
	Serial.print("T=");
	Serial.print(si7051.readTemperature());
	Serial.println("C");
	delay(300);
}
