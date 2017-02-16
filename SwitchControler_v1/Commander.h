/*
 * Commander.h
 *
 *  Created on: 4 thg 2, 2017
 *      Author: MyPC
 */

#ifndef COMMANDER_H_
#define COMMANDER_H_

#include "ArduinoJson.h"

#include "GlobalConfigs.h"
#include "Singleton.h"
#include "DeviceSetting.h"

#define COMM_COM	"cmd"
typedef enum { MQTT, HTTP } CmdProvider_t;

class Commander : public Singleton<Commander> {
	public:
		Commander();
		virtual ~Commander();
		String process(String commandJson, CmdProvider_t cmdr);
	private:
};

#endif /* COMMANDER_H_ */
