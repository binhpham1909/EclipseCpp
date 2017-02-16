/*
 * MQTTConnection.h
 *
 *  Created on: 4 thg 2, 2017
 *      Author: MyPC
 */

#ifndef MQTTCONNECTION_H_
#define MQTTCONNECTION_H_

#include "WiFiClient.h"
#include "Singleton.h"
#include "DeviceSetting.h"
#include "Commander.h"
#include "WifiManager.h"
#include <PubSubClient.h>
#include "GlobalConfigs.h"


class MQTTConnection : public Singleton<MQTTConnection>{
public:
	MQTTConnection();
	virtual ~MQTTConnection();
	void init();
	void loop();
	bool publish(String message);
private:
	void callback(char* topic, uint8_t* payload, unsigned int length);
	WiFiClient _wclient;
	PubSubClient *_client;
	String _topic;
	String _server;
};

#endif /* MQTTCONNECTION_H_ */
