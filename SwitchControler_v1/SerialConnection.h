/*
 * SerialConnection.h
 *
 *  Created on: 16 thg 2, 2017
 *      Author: MyPC
 */

#ifndef SERIALCONNECTION_H_
#define SERIALCONNECTION_H_
#include "ArduinoJson.h"
#include "GlobalConfigs.h"
#include "Singleton.h"
#include "DeviceSetting.h"

class SerialConnection : public Singleton<SerialConnection> {
	public:
		SerialConnection();
		virtual ~SerialConnection();
		void loop();
	private:
		void process();
		void flush();
		String _inputStr;
		bool _complete;
		bool _logined;
};

#endif /* SERIALCONNECTION_H_ */
