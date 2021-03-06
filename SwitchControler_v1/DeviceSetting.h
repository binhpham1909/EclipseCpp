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
#define DV_SERIAL_MAX_LEN	16
#define DV_NAME_MAX_LEN	16
#define DV_USER_MAX_LEN		16

#define SSID_MAX_LEN 33
#define WIFI_PASSWORD_MAX_LEN 21
#define IP_MAX_LEN 15

#define MQTT_SERVER_MAX_LEN	48
#define MQTT_API_MAX_LEN	32
#define MQTT_USER_MAX_LEN	32

typedef struct __attribute__((packed)){
	char md5[34];	// 34 bytes

	char deviceSerial[DV_SERIAL_MAX_LEN + 1];	// 17 bytes
	char deviceName[DV_NAME_MAX_LEN + 1];	// 17 bytes
	char adminPassword[DV_USER_MAX_LEN + 1];	// 17 bytes
	char userPassword[DV_USER_MAX_LEN + 1];	// 17 bytes

	char STAssid[SSID_MAX_LEN + 1];	// 17 bytes
	char STApassword[WIFI_PASSWORD_MAX_LEN + 1];	// 17 bytes
	char STAip[IP_MAX_LEN + 1];	// 17 bytes
	char STAmask[IP_MAX_LEN + 1];	// 17 bytes
	char STAgateway[IP_MAX_LEN + 1];	// 17 bytes
	bool DHCP;
	char APpassword[WIFI_PASSWORD_MAX_LEN + 1];	// 17 bytes
	int timezone;

	char MQTTServer[MQTT_SERVER_MAX_LEN + 1];	// 17 bytes
	char MQTTUser[MQTT_USER_MAX_LEN + 1];	// 17 bytes
	char MQTTAPI[MQTT_API_MAX_LEN + 1];	// 17 bytes
	int	MQTTPort;

	int HTTPPort;
	GPIO_t gpio[MAX_GPIO_PIN];
	GPIOState_t gpioState[MAX_GPIO_PIN];
	bool saveGPIOState;

	GPIOTimer_t timer[TIMER_MAX_ALLOW];
	int numTimerEnable;
} DeviceSetting_t;

class DeviceSetting : public Singleton<DeviceSetting> {
	public:
		DeviceSetting();
		virtual ~DeviceSetting();
		void init();
		bool saveSetting();
		bool loadSetting();
		bool resetSettings();

		bool setDeviceSerial(const String& serial);
		String getDeviceSerial();
		bool setDeviceName(const String& value);
		String getDeviceName();
		bool setAdminPassword(const String& password);
		String getAdminPassword();
		bool setUserPassword(const String& value);
		String getUserPassword();
		bool setSTAssid(const String& value);
		String getSTAssid();
		bool setSTApassword(const String& value);
		String getSTApassword();
		bool setStaticIP(const String& value);
		String getStaticIP();
		bool setMask(const String& value);
		String getMask();
		bool setGateway(const String& value);
		String getGateway();
		bool setDHCP(bool value);
		bool getDHCP();
		bool setAPpassword(const String& value);
		String getAPpassword();

		bool setTimezone(int value);
		int getTimezone();

		bool setMqttServer(const String& value);
		String getMqttServer();
		bool setMqttUser(const String& value);
		String getMqttUser();
		bool setMqttAPI(const String& value);
		String getMqttAPI();
		bool setMQTTPort(int value);
		int getMQTTPort();

		bool setHTTPPort(int value);
		int getHTTPPort();

		bool setGPIOName(int index, const String& value);
		String getGPIOName(int index);

		GPIO_t getGPIOConfig(int index);
		bool setGPIOConfig(int index, GPIO_t gpio);
	private:
		String calcMD5();
		void updateMD5();
		bool isDirty();
		DeviceSetting_t _dv;
};

#endif /* DEVICESETTING_H_ */
