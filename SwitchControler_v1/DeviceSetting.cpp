/*
 * FirmwareSetting.cpp
 *
 *  Created on: 24 thg 1, 2017
 *      Author: MyPC
 */

#include "DeviceSetting.h"

DeviceSetting::DeviceSetting() {
	// TODO Auto-generated constructor stub
	loadSetting();
	if(isDirty()){
		DBGF("Invalid CRC, restore default setting");
		resetSettings();
		loadSetting();
	}
}

DeviceSetting::~DeviceSetting() {
	// TODO Auto-generated destructor stub
	saveSetting();
}

bool DeviceSetting::loadSetting() {
	int n = sizeof(DeviceSetting_t);
	DBG2F("Size of setting in EEPROM (byte):", n);
	uint8_t *p = (uint8_t*)(&_dv);
	EEPROM.begin(n);
	for (int i=0; i<n; i++) {
		delay(0);
		*p = EEPROM.read(i);
		p++;
	}
	EEPROM.end();
	return true;
}

bool DeviceSetting::saveSetting() {
	int n = sizeof(DeviceSetting_t);
	uint8_t *p = (uint8_t*)(&_dv);
	EEPROM.begin(n);
	for (int i = EEPROM_DEVICE_SETTING; i < n + EEPROM_DEVICE_SETTING; i++) {
		delay(0);
		EEPROM.write(i,0);
	}
	bool bRvl = EEPROM.commit();
	for (int i = EEPROM_DEVICE_SETTING; i < n + EEPROM_DEVICE_SETTING; i++) {
		delay(0);
		EEPROM.write(i,*p);
		p++;
	}
	bRvl = EEPROM.commit();
	EEPROM.end();
	return bRvl;
}

bool DeviceSetting::resetSettings() {
	strncpy(_dv.adminPassword, HBOS_Super_Password, 16);
	_dv.saveGPIOState = true;
	GPIOState_t state;
	state.isEnable = false;
	state.value = 0;
	for(int i = 0; i < MAX_GPIO_PIN; i++){
		_dv.gpioState[i] = state;
	}
	updateMD5();
	saveSetting();
	return true;
}

bool DeviceSetting::setDeviceSerial(String serial) {
	if(serial.length() > 16 || serial.length() < 10)	return false;
	strncpy(_dv.deviceSerial, serial.c_str(), serial.length()+1);
	return true;
}

String DeviceSetting::getDeviceSerial() {
	return String(_dv.deviceSerial);
}

bool DeviceSetting::setAdminPassword(String password) {
	if(password.length() > 16 || password.length() < 10)	return false;
	strncpy(_dv.adminPassword, password.c_str(), password.length()+1);
	return true;
}

String DeviceSetting::getAdminPassword() {
	return String(_dv.adminPassword);
}

GPIO_t DeviceSetting::getGPIOConfig(int index) {
	return _dv.gpio[index];
}

bool DeviceSetting::setGPIOConfig(int index, GPIO_t gpio) {
	_dv.gpio[index] = gpio;
	return true;
}

String DeviceSetting::calcMD5() {
	MD5Builder builder;
	int md5len = sizeof(_dv.md5);
	uint8_t *p = (uint8_t*)(&_dv);
	p += md5len;
	delay(0);
	builder.begin();
	builder.add(p,sizeof(DeviceSetting_t)-md5len);
	builder.calculate();
	return builder.toString();
}

void DeviceSetting::updateMD5() {
	strncpy(_dv.md5,calcMD5().c_str(),32);
}

bool DeviceSetting::isDirty() {
	DBG2F("MD5 of Settings: ",_dv.md5);
	DBG2F("Calculated MD5:  ",calcMD5());
	return calcMD5()!=_dv.md5;
}
