/*
 * GPIOManager.h
 *
 *  Created on: 24 thg 1, 2017
 *      Author: MyPC
 */

#ifndef GPIOMANAGER_H_
#define GPIOMANAGER_H_
#include "Arduino.h"

#include "DeviceSetting.h"
#include "GlobalConfigs.h"
#include "Singleton.h"

// Cac khai bao cho GPIO va vung nho cua no trong EEPROM
#define EEPROM_GPIO_SETTING	129
#define MAX_GPIO_PIN	9

static const int GPIOList[MAX_GPIO_PIN] = { 16, 14, 12, 13, 15, 2, 0, 4, 5};

typedef enum { IN, TOGGLE, HOLD, FLIP } GPIOType_t;

typedef struct __attribute__((packed)){
	int index;
	GPIOType_t type;
	long ONTime;	// ms turn on
	long OFFTime; // ms turn off
	bool lastValue;
	int value;
} GPIO_t;

typedef struct __attribute__((packed)){
	GPIO_t gpio[MAX_GPIO_PIN];
} GPIOSetting_t;

class GPIOManager : public Singleton<GPIOManager> {
public:
	GPIOManager();
	~GPIOManager();
	void init();
	void update();
private:
	GPIOSetting_t _gpio;
	GPIO_t getGPIOConfig(int index);
	bool setGPIOConfig(int index, GPIO_t gpio);
	long lastUpdate[MAX_GPIO_PIN];

};
#endif /* GPIOMANAGER_H_ */
