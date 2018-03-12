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


#ifndef _CLOSEDCUBE_SI7051_h

#define _CLOSEDCUBE_SI7051_h
#include <Arduino.h>

typedef union {
	uint8_t rawData;
	struct {
		uint8_t resolution0 : 1;
		uint8_t reserve1 : 4;
		uint8_t vdds : 1; // vdds = 1 if and only if VDD between 1.8V and 1.9V
		uint8_t reserved2 : 1;
		uint8_t resolution7 : 1;
	};
} SI7051_Register;


class ClosedCube_Si7051 {
public:
	ClosedCube_Si7051();

	void begin(uint8_t address);
	void setResolution(uint8_t resolution);

	void reset();

	uint8_t readFirmwareVersion();

	float readTemperature();
	float readT(); // short-cut for readTemperature

private:
	uint8_t _address;

};

#endif

