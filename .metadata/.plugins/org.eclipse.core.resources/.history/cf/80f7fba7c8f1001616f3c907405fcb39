/*
 * GPIOManager.h
 *
 *  Created on: 24 thg 1, 2017
 *      Author: MyPC
 */

#ifndef GPIOMANAGER_H_
#define GPIOMANAGER_H_
#include "Arduino.h"
#include "FirmwareSetting.h"
#include "Singleton.h"
#include "DebugSetting.h"


class GPIO_m : public Singleton<GPIO_m> {
public:
	GPIO_m();
	~GPIO_m();
	void init();
	void update();
private:
	long lastUpdate[MAX_GPIO_PIN];

};
#endif /* GPIOMANAGER_H_ */
