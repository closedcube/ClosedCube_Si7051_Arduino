/*

Arduino Library for Silicon Labs Si7051 ±0.1°C (max) Digital Temperature Sensor
Written by AA for ClosedCube

---

The MIT License (MIT)

Copyright (c) 2016 ClosedCube Limited

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*/

#include <Wire.h>
#include "ClosedCube_Si7051.h"

ClosedCube_Si7051::ClosedCube_Si7051()
{
}

void ClosedCube_Si7051::begin(uint8_t address) {
	_address = address;
	Wire.begin();

	setResolution(14);
}

void ClosedCube_Si7051::reset()
{
	Wire.beginTransmission(_address);
	Wire.write(0xFE);
	Wire.endTransmission();
}

uint8_t ClosedCube_Si7051::readFirmwareVersion()
{
	Wire.beginTransmission(_address);
	Wire.write(0x84);
	Wire.write(0xB8);
	Wire.endTransmission();

	Wire.requestFrom(_address, (uint8_t)1);

	return Wire.read();
}

void ClosedCube_Si7051::setResolution(uint8_t resolution)
{
	SI7051_Register reg;

	switch (resolution)
	{
		case 12:
			reg.resolution0 = 1;
			break;	
		case 13:
			reg.resolution7 = 1;
			break;
		case 11:
			reg.resolution0 = 1;
			reg.resolution7 = 1;
			break;
	}
	
	Wire.beginTransmission(_address);
	Wire.write(0xE6);
	Wire.write(reg.rawData);
	Wire.endTransmission();
}


float ClosedCube_Si7051::readT() {
	return readTemperature();
}

float ClosedCube_Si7051::readTemperature() {
	Wire.beginTransmission(_address);
	Wire.write(0xF3);
	Wire.endTransmission();

	delay(10);

	Wire.requestFrom(_address, (uint8_t)2);

	byte msb = Wire.read();
	byte lsb = Wire.read();

	uint16_t val = msb << 8 | lsb;

	return (175.72*val) / 65536 - 46.85;
}




