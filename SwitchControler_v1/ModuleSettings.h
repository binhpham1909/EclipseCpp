/*
 * ModuleSettings.h
 *
 *  Created on: 24 thg 1, 2017
 *      Author: MyPC
 */

#ifndef MODULESETTINGS_H_
#define MODULESETTINGS_H_

#include "Singleton.h"
#include "FS.h"
#include "ArduinoJson.h"

#include "GlobalConfigs.h"
#include "GPIOManager.h"
#include "Session.h"

#define SETTINGS_FILE "settings.json"
#define ST_DEVICE_NAME "name"
#define ST_DEVICE_USER "userDevice"
#define ST_DEVICE_PASS "passDevice"
#define ST_STA_SSID "ssid"
#define ST_STA_PASSWORD "password"
#define ST_STA_DHCP "dhcp"
#define ST_STA_IP "ip"
#define ST_STA_MASK "mask"
#define ST_STA_GATEWAY "gw"
#define ST_GPIO_NAME "gpioName"
#define ST_MQTT_USER "mqttUser"
#define ST_MQTT_API "mqttAPI"
#define ST_SERVER_PORT "serverPort"
#define ST_TIMEZONE	"timezone"


class ModuleSettings : public Singleton<ModuleSettings> {
public:
	ModuleSettings();
	virtual ~ModuleSettings();
	bool resetSetting();
	bool loadSettings();
	bool saveSettings();
	bool setPassDevice(String value);
	String getPassDevice();
	bool setDeviceName(String value);
	String getUserDevice();
	bool setUserDevice(String value);
	String getDeviceName();
	bool setWifiSSID(String value);
	String getWifiSSID();
	bool setWifiPassword(String value);
	String getWifiPassword();
	bool setMqttUser(String value);
	String getMqttUser();
	bool setMqttAPI(String value);
	String getMqttAPI();
	bool setGPIOName(int index, String value);
	String getGPIOName(int index);
	bool setServerPort(int value);
	int getServerPort();
	bool setTimezone(int value);
	int getTimezone();
	bool setDHCP(bool value);
	bool getDHCP();
	bool setStaticIP(String value);
	String getStaticIP();
	bool setMask(String value);
	String getMask();
	bool setGateway(String value);
	String getGateway();
private:
	String Settings;
	String readSettings(char* key);
	bool writeSettings(char* key, String& value);
	bool writeSettings(char* key, int& value);
	String readArrSettings(char* key, int index);
	bool writeArrSettings(char* key, int index, String& value);
};

const char DEF_SETTING[] PROGMEM  = "{\"name\":\"Wifiswitch\", \"userDevice\":\"user\", \"passDevice\":\"12345678\", \"ssid\":\"Tang_2_nha_moi\", \"password\":\"0313837124\", \"dhcp\":false, \"ip\":\"10.0.0.100\", \"mask\":\"255.0.0.0\", \"gw\":\"10.0.0.1\", \"serverPort\":80, \"timezone\":59, \"mqttUser\":\"binhpham\", \"mqttAPI\":\"19D5E9D6E86834E05CB27D7D0703E30C\", \"gpioName\":[\"a\",\"b\"]}";
#endif /* MODULESETTINGS_H_ */
