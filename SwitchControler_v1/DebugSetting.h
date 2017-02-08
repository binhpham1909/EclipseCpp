/*
 * DebugSetting.h
 *
 *  Created on: 24 thg 1, 2017
 *      Author: MyPC
 */

#ifndef DEBUGSETTING_H_
#define DEBUGSETTING_H_
#include "Arduino.h"

#define _DEBUG_

#ifdef _DEBUG_
#define INIT_SERIAL_DEBUG() Serial.begin(115200)
#define DBG0(x) Serial.print(x)
#define DBGF0(x) Serial.print(F(x))
#define DBG(x) Serial.println(x)
#define DBG2(x,y) { Serial.print(x); Serial.println(y); }
#define DBGF(x) Serial.println(F(x))
#define DBG2F(x,y) { Serial.print(F(x)); Serial.println(y); }
#define DBG2F0(x,y) { Serial.print(F(x)); Serial.print(y); }
#else
#define INIT_SERIAL_DEBUG()
#define DBG0(x)
#define DBGF0(x)
#define DBG(x)
#define DBG2(x,y)
#define DBGF(x)
#define DBG2F(x,y)
#define DBG2F0(x,y)
#endif

#define MAX_GPIO_PIN	9

static const int GPIOList[MAX_GPIO_PIN] = { 16, 14, 12, 13, 15, 2, 0, 4, 5};

typedef enum { IN, TOGGLE, HOLD, FLIP } GPIOType_t;

typedef struct __attribute__((packed)){
	int index;
	GPIOType_t type;
	long FlipON;	// ms turn on
	long FlipOff; // ms turn off
	bool FlipState;
	int value;
} GPIO_t;

#endif /* DEBUGSETTING_H_ */