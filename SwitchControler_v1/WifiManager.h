/*
 * WifiManager.h
 *
 *  Created on: 4 thg 2, 2017
 *      Author: MyPC
 */

#ifndef WIFIMANAGER_H_
#define WIFIMANAGER_H_

#include "Singleton.h"
#include "ModuleSettings.h"
#include "Commander.h"
#include "GlobalConfigs.h"

#define MAX_LIST_AP	20
typedef struct {
  char ssid[32];
  int rssi;
} WifiList_t;

class WifiManager : public Singleton<WifiManager> {
	public:
		WifiManager();
		virtual ~WifiManager();
		void loop();
		void setAPMode();
		bool inAPMode();
		bool inSTAMode();
		void setSTAMode();
	private:
		boolean isAPMode;
};

#endif /* WIFIMANAGER_H_ */
