/*
 * FirmwareSetting.h
 *
 *  Created on: 24 thg 1, 2017
 *      Author: MyPC
 */

#ifndef DEVICESETTING_H_
#define DEVICESETTING_H_
#include "Singleton.h"
#include <EEPROM.h>

#include "GlobalConfigs.h"
#include "GPIOManager.h"

// Cac khai bao cho thong so thiet bi
// cac thong so nay chinh la ma code truy xuat nguon goc va cac ket noi
// den he thong
#define EEPROM_DEVICE_SETTING	0
#define DV_SERIAL_LEN	16
#define DV_USER_LEN		16


typedef struct __attribute__((packed)){
	char md5[33];	// 33 bytes
	int firstBoot;	// 2	bytes
	char deviceSerial[DV_SERIAL_LEN + 1];	// 17 bytes
	char adminPassword[DV_USER_LEN + 1];	// 17 bytes
} DeviceSetting_t;

class DeviceSetting : public Singleton<DeviceSetting> {
	public:
		DeviceSetting();
		virtual ~DeviceSetting();
		bool saveSetting();
		bool resetSettings();
		bool setDeviceSerial(String serial);
		String getDeviceSerial();
		bool setAdminPassword(String password);
		String getAdminPassword();
	private:
		DeviceSetting_t *_dv;
};

#endif /* DEVICESETTING_H_ */