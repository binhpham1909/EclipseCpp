/*
 * SerialConnection.cpp
 *
 *  Created on: 16 thg 2, 2017
 *      Author: MyPC
 */

#include "SerialConnection.h"

SerialConnection::SerialConnection() {
	// TODO Auto-generated constructor stub
	_inputStr = "";
	_complete = false;
	_logined = false;
}

SerialConnection::~SerialConnection() {
	// TODO Auto-generated destructor stub
}

void SerialConnection::loop() {
	// TODO Doc gia tri tu bo dem serial
	while (Serial.available()) {
		// doc byte moi tu bo nho dem:
		char inChar = (char)Serial.read();
		// them no vao inputStr:
		_inputStr += inChar;
		// gap ky tu xuong dong thi ket thuc
		if (inChar == '\n')	_complete = true;
	}
	if(_complete) process();
}

void SerialConnection::process() {
	// TODO

	DBG(_inputStr);
	// Xu ly o day
	DynamicJsonBuffer jsonBuffer;
	JsonObject& root = jsonBuffer.parseObject(_inputStr);
	String cmd = root["cmd"].asString();
	if(cmd == "login"){
		String pass = root["cmdPassword"].asString();
		if(pass == DeviceSetting::getInstance()->getAdminPassword())	_logined = true;
	}else if(_logined && cmd == "logout"){
		_logined = false;
	}else if(_logined && cmd == "reboot"){
		ESP.reset();
	}else if(_logined && cmd == "restore"){
		DeviceSetting::getInstance()->resetSettings();
	}else if(_logined && cmd == "setSerial"){
		String val = root["newSerial"].asString();
		if(DeviceSetting::getInstance()->setDeviceSerial(val))
			Serial.println(FPSTR(JsonTrue));
		else
			Serial.println(FPSTR(JsonFalse));
	}else if(_logined && cmd == "changePass"){
		String val = root["newPass"].asString();
		if(DeviceSetting::getInstance()->setAdminPassword(val))
			Serial.println(FPSTR(JsonTrue));
		else
			Serial.println(FPSTR(JsonFalse));
	}
	flush();
}

void SerialConnection::flush() {
	// Xoa bo nho dem, flag complete
	if(!_logined){
		Serial.println(F("Dang nhap de thiet lap"));
	}
	_complete = false;
	_inputStr = "";
	Serial.flush();
}