/*
 * FirmwareSetting.cpp
 *
 *  Created on: 24 thg 1, 2017
 *      Author: MyPC
 */

#include "DeviceSetting.h"

DeviceSetting::DeviceSetting() {
	// TODO Auto-generated constructor stub
	_dv = new DeviceSetting_t;
	EEPROM.begin(sizeof(DeviceSetting_t));
	EEPROM.get(EEPROM_DEVICE_SETTING, _dv );
	EEPROM.end();
}

DeviceSetting::~DeviceSetting() {
	// TODO Auto-generated destructor stub
	saveSetting();
	delete _dv;
}

bool DeviceSetting::saveSetting() {
	EEPROM.begin(sizeof(DeviceSetting_t));
	EEPROM.put(EEPROM_DEVICE_SETTING, _dv );
	EEPROM.commit();
	EEPROM.end();
	return true;
}

bool DeviceSetting::resetSettings() {
	//strncpy(_fw.adminUser, admin_user, 16);
	//strncpy(_fw.adminPassword, admin_password, 16);
}

