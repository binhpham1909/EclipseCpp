/*
 * Commander.cpp
 *
 *  Created on: 4 thg 2, 2017
 *      Author: MyPC
 */

#include "Commander.h"

Commander::Commander() {
	// TODO Auto-generated constructor stub

}

Commander::~Commander() {
	// TODO Auto-generated destructor stub
}

String Commander::process(char* commandJson) {
	DynamicJsonBuffer jsonBuffer;
	JsonObject& root = jsonBuffer.parseObject(commandJson);
	String cmd = root["cmd"];
	if(cmd=="control"){
		DBG("control");
	}
	else if(cmd=="networkSetup") {
		bool dhcp = root["dhcp"];
		bool result;
		if(dhcp){
			result = ModuleSettings::getInstance()->setWifiSSID(root["ssid"])&
					ModuleSettings::getInstance()->setWifiPassword(root["wifiPassword"])&
					ModuleSettings::getInstance()->setServerPort(root["port"])&
					ModuleSettings::getInstance()->setStaticIP(root["ip"])&
					ModuleSettings::getInstance()->setMask(root["mask"])&
					ModuleSettings::getInstance()->setGateway(root["gw"])&
					ModuleSettings::getInstance()->setDHCP(dhcp);
		}else{
			result = ModuleSettings::getInstance()->setWifiSSID(root["ssid"])&
					ModuleSettings::getInstance()->setWifiPassword(root["wifiPassword"])&
					ModuleSettings::getInstance()->setServerPort(root["port"])&
					ModuleSettings::getInstance()->setDHCP(dhcp);
		}
		if(result){
			ModuleSettings::getInstance()->saveSettings();
			return FPSTR(JsonTrue);
		}
		else return FPSTR(JsonFalse);
	}
	else if(cmd=="debug") {
		DBG("debug");
	}else {
		DBG("exit");
	}
	return FPSTR(JsonFalse);
}

String Commander::process(String commandJson) {
	DynamicJsonBuffer jsonBuffer;
	JsonObject& root = jsonBuffer.parseObject(commandJson);
	String cmd = root["cmd"];
	if(cmd=="control"){
		DBG("control");
	}
	else if(cmd=="networkSetup") {
		bool dhcp = root["dhcp"];
		bool result;
		if(dhcp){
			result = ModuleSettings::getInstance()->setWifiSSID(root["ssid"])&
					ModuleSettings::getInstance()->setWifiPassword(root["wifiPassword"])&
					ModuleSettings::getInstance()->setServerPort(root["port"])&
					ModuleSettings::getInstance()->setStaticIP(root["ip"])&
					ModuleSettings::getInstance()->setMask(root["mask"])&
					ModuleSettings::getInstance()->setGateway(root["gw"])&
					ModuleSettings::getInstance()->setDHCP(dhcp);
		}else{
			result = ModuleSettings::getInstance()->setWifiSSID(root["ssid"])&
					ModuleSettings::getInstance()->setWifiPassword(root["wifiPassword"])&
					ModuleSettings::getInstance()->setServerPort(root["port"])&
					ModuleSettings::getInstance()->setDHCP(dhcp);
		}
		if(result)	return FPSTR(JsonTrue);
		else return FPSTR(JsonFalse);
	}
	else if(cmd=="debug") {
		DBG("debug");
	}else {
		DBG("exit");
	}
	return FPSTR(JsonFalse);
}