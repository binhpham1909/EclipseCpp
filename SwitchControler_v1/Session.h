/*
 * Seasion.h
 *
 *  Created on: 24 thg 1, 2017
 *      Author: MyPC
 */

#ifndef SESSION_H_
#define SESSION_H_
#include "Singleton.h"
#include "SysTime.h"
#include <ESP8266WiFi.h>
#include "GlobalConfigs.h"

#define MAX_SESSION  10
#define SESSION_ID_LENGTH 33
#define SESSION_EXPIRE_TIME   (600) //  seconds

#define USER_ROLE 1
#define ADMIN_ROLE 2

typedef struct __attribute__((packed)) {
	char name[33];
	int role;
	time_t time;
} SessionParam;
class Session : public Singleton<Session>{
public:
	Session();
	virtual ~Session();
	String createSS(int role);
	void deleteSS(String session);
	int getUserRole(String session);
	int setUserRole(String session, int role);
	static String GetRandomString();
	void checkExpireTime();
private:
	SessionParam *SS;
	int numSession;
};

#endif /* SESSION_H_ */
