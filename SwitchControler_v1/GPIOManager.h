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
#include "ProgmemStruct.h"
#include "MQTTConnection.h"



class GPIOManager : public Singleton<GPIOManager> {
	public:
		GPIOManager();
		~GPIOManager();
		void update();
		void setState(int index, GPIOState_t state);
		GPIOState_t getState(int index);
	private:
		void processInput(int index);
		GPIOState_t _state[MAX_GPIO_PIN];
		long lastUpdate[MAX_GPIO_PIN];

};
#endif /* GPIOMANAGER_H_ */
