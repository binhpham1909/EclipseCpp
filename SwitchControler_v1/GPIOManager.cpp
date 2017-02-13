/*
 * GPIOManager.cpp
 *
 *  Created on: 24 thg 1, 2017
 *      Author: MyPC
 */
#include "GPIOManager.h"

GPIOManager::GPIOManager() {

	EEPROM.begin(sizeof(GPIOSetting_t));
	EEPROM.get(EEPROM_GPIO_SETTING, _gpio );
	EEPROM.end();
}

GPIOManager::~GPIOManager() {

}
void GPIOManager::update() {
	for (int i = 0; i < MAX_GPIO_PIN; ++i) {
		GPIO_t gpio = _gpio.gpio[i];
		int pin = GPIOList[i];
		if (gpio.type == IN) {
			gpio.value = digitalRead(pin);
		}else if(gpio.type == FLIP){
			if(gpio.value){
				long curr = millis();
				if(gpio.lastValue){
					if((curr-lastUpdate[i]) > gpio.ONTime){
						gpio.lastValue = LOW;
					}
				}else{
					if((curr-lastUpdate[i]) > gpio.OFFTime){
						gpio.lastValue = HIGH;
					}
				}
			}else{
				gpio.lastValue = LOW;
			}
			digitalWrite(pin, gpio.lastValue);
		} else {
			digitalWrite(pin, gpio.value);
		}
	}
}

void GPIOManager::init() {
	for (int i = 0; i < MAX_GPIO_PIN; ++i) {
		int _pin = GPIOList[i];
		if (_gpio.gpio[i].type == IN) {
			pinMode(_pin, INPUT);
		} else{
			pinMode(_pin, OUTPUT);
		}
	}
}

GPIO_t GPIOManager::getGPIOConfig(int index) {
	return _gpio.gpio[index];
}

bool GPIOManager::setGPIOConfig(int index, GPIO_t gpio) {
	_gpio.gpio[index] = gpio;
	return true;
}
