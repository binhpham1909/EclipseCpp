/*
 * WifiManager.cpp
 *
 *  Created on: 4 thg 2, 2017
 *      Author: MyPC
 */

#include "WifiManager.h"

WifiManager::WifiManager() {
	// TODO Auto-generated constructor stub

}

WifiManager::~WifiManager() {
	// TODO Auto-generated destructor stub
}

void WifiManager::loop() {
	if(inSTAMode()){
		if (WiFi.status() != WL_CONNECTED) {
			DBG0("Connecting to ");
			DBG0(ModuleSettings::getInstance()->getWifiSSID());
			DBG("...");
			WiFi.begin(ModuleSettings::getInstance()->getWifiSSID().c_str(), ModuleSettings::getInstance()->getWifiPassword().c_str());
			if (WiFi.waitForConnectResult() != WL_CONNECTED)
				return;
			DBG("WiFi connected");
		}
	}else {

	}

}

void WifiManager::setAPMode() {
	isAPMode = true;
}

bool WifiManager::inAPMode() {
	return isAPMode;
}

bool WifiManager::inSTAMode() {
	return !isAPMode;
}

void WifiManager::setSTAMode() {
	isAPMode = false;
}
