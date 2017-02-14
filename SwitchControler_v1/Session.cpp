/*
 * Seasion.cpp
 *
 *  Created on: 24 thg 1, 2017
 *      Author: MyPC
 */

#include "Session.h"

Session::Session() {
	// TODO Auto-generated constructor stub
	numSession = 0;
	SS = new SessionParam[1];
	strcpy(SS[0].name, "");
	SS[0].role = -1;
}

Session::~Session() {
	// TODO Auto-generated destructor stub
}

String Session::createSS(int role) {
	if(numSession == MAX_SESSION)	return String();
	numSession++;
	if(numSession==1){
		strcpy(SS[0].name, GetRandomString().c_str());
		SS[0].role = role;
		SS[0].time = SysTime::getInstance()->now();
		return String(SS[0].name);
	}else if(numSession>1){
		SessionParam *newSS = new SessionParam[numSession];
		for(int i=0; i< numSession-1; i++){
			newSS[i] = SS[i];
		}
		strcpy(newSS[numSession-1].name, GetRandomString().c_str());
		newSS[numSession-1].time = SysTime::getInstance()->now();
		newSS[numSession-1].role = role;
		delete SS;
		SS = newSS;
		DBG2F("New Session: ", SS[numSession-1].name);
		return String(SS[numSession-1].name);
	}
}

void Session::deleteSS(String session) {
	if(numSession < 1) return;
	if(numSession == 1){
		numSession = 0;
		return;
	}
	SessionParam *newSS = new SessionParam[numSession - 1];
	int j=0;
	for(int i=0; i< numSession; i++){
		if(session!=String(SS[i].name)){
			newSS[j++] = SS[i];
		}
	}
	delete SS;
	SS = newSS;
	numSession--;
}

void Session::checkExpireTime() {
	if(numSession < 1){
		DBGF("No has Session");
		return;
	}
	time_t cur = SysTime::getInstance()->now();
	for(int i=0; i< numSession; i++){
		DBG2F0("Session ", i);
		DBG2F("==> ", SS[i].name);
		if((cur - SS[i].time) > SESSION_EXPIRE_TIME){
			DBG2F("Delete Session expired: ", i);
			deleteSS(SS[i].name);
			i--;
		}
	}
}

int Session::getUserRole(String session) {
	if((numSession < 1)||(session.length()<32)) return -1;
	checkExpireTime();
	int retRole = -1;
	for(int i=0; i< numSession; i++){
		if(session==String(SS[i].name)){
			SS[i].time = SysTime::getInstance()->now();
			retRole = SS[i].role;
		}
	}
	return retRole;
}

int Session::setUserRole(String session, int role) {
	for(int i=0; i< numSession; i++){
		if(session==String(SS[i].name)){
			SS[i].role = role;
			return SS[i].role;
		}
	}
	return 0;
}

String Session::GetRandomString() {
	MD5Builder md5;
	md5.begin();
	md5.add(String(random(0x7fffffff)));
	md5.add(String(millis()));
	md5.calculate();
	return md5.toString();
}

