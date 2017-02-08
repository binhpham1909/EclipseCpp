#include "Arduino.h"
#include "ModuleSettings.h"
#include "MQTTConnection.h"
#include "WifiManager.h"
#include "ServerManager.h"


//The setup function is called once at startup of the sketch
void setup()
{
// Add your initialization code here
	INIT_SERIAL_DEBUG();
	delay(100);
	//ModuleSettings::getInstance()->resetSetting();
	ModuleSettings::getInstance()->loadSettings();
	//DBG(ModuleSettings::getInstance()->setDeviceName("Wifi Device"));
	//DBG(ModuleSettings::getInstance()->saveSettings());
	DBG2F("Device name: ", ModuleSettings::getInstance()->getDeviceName());
	DBG2F("Username: ", ModuleSettings::getInstance()->getUserDevice());
	DBG2F("Password: ", ModuleSettings::getInstance()->getPassDevice());
	DBG2F("Wifi SSID: ", ModuleSettings::getInstance()->getWifiSSID());
	DBG2F("Wifi password: ", ModuleSettings::getInstance()->getWifiPassword());
	DBG2F("HTTP Server port: ", ModuleSettings::getInstance()->getServerPort());
	DBG2F("MQTT Username: ", ModuleSettings::getInstance()->getMqttUser());
	DBG2F("MQTT API: ", ModuleSettings::getInstance()->getMqttAPI());
	DBG2F("GPIO 0 name: ", ModuleSettings::getInstance()->getGPIOName(0));
	DBG2F("GPIO 1 name: ", ModuleSettings::getInstance()->getGPIOName(1));
}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here
	WifiManager::getInstance()->loop();
	ServerManager::getInstance()->loop();
	MQTTConnection::getInstance()->loop();
	//Session::getInstance()->checkExpireTime();
}