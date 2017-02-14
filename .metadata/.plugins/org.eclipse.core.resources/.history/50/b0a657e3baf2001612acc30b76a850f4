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

#endif /* GLOBALCONFIGS_H_ */
