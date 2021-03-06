/*
 * GlobalConfigs.h
 *
 *  Created on: 24 thg 1, 2017
 *      Author: MyPC
 */

#ifndef GLOBALCONFIGS_H_
#define GLOBALCONFIGS_H_
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

/*
 * Global define - Nhung thiet lap di theo ban build
 */

#define HBOS_Version	"1.000.000"
#define	HBOS_Super_User	"admin"

#define	HBOS_Super_Password	"TNENVIBH@9091+"
#define	HBOS_User_Password	"1234567890"
#define	HBOS_Device_Name_DEF	"Thiet Bi"
#define HBOS_GPIO_Type	""
#define HBOS_MQTT_SERVER	"mqtt.hbinvent.com"
#define HBOS_WIFI_SSID_DEF	"HBInvent"
#define HBOS_WIFI_PASS_DEF	"!()(!(*("

/* Cau truc vung nho EEPROM:
 * 0 - 128: Device setting chua du lieu truy xuat nguon goc:
 * 			xem class DeviceSetting.h
 * 129 - 1xx: GPIO setting( xem class GPIOManager)
 *
 *
 */

/* Cau truc file setting luu tren FS (xem class ModuleSetting.h):
 *
 */

/*
 * Cac thiet lap cho GPIO
 */
#define MAX_GPIO_PIN	9
#define GPIO_NAME_MAX_LEN	32

// Mang index lai thu tu GPIO
static const int GPIOList[MAX_GPIO_PIN] = { 16, 14, 12, 13, 15, 2, 0, 4, 5};

// Cac kieu GPIO: INPUT,
typedef enum { IN = 1, OUT, CLICK, FLASH } GPIOType_t;

typedef struct __attribute__((packed)){
	int index;
	GPIOType_t type;
	char name[GPIO_NAME_MAX_LEN + 1];
	long ONTime;	// ms turn on
	long OFFTime; // ms turn off
} GPIO_t;

typedef struct __attribute__((packed)){
	unsigned long lastUpdate[MAX_GPIO_PIN];
	int value;
	int isEnable;
} GPIOState_t;

/*
 * Cac khai bao va dinh nghia cho Timer
 */
#define TIMER_MAX_ALLOW	50

typedef struct __attribute__((packed)){
	int time;
	unsigned long weekend;
	int isEnable;
} GPIOTimer_t;

/*
 * Cac chuoi luu trong PROGMEM
 */


const char JsonTrue[] PROGMEM = "{\"status\":true}";
const char JsonFalse[] PROGMEM = "{\"status\":false}";

#endif /* GLOBALCONFIGS_H_ */
