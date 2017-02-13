/*
 * TimerManager.h
 *
 *  Created on: 10 thg 2, 2017
 *      Author: MyPC
 */

#ifndef TIMERMANAGER_H_
#define TIMERMANAGER_H_

#include "DebugSetting.h"
#include "TimeLib.h"
#include "DNSServer.h"
#include "Singleton.h"

#define NTP_LOCAL_PORT 2395      // local port to listen for UDP packets
#define NTP_PACKET_SIZE 48 // NTP time stamp is in the first 48 bytes of the message
#define MAX_JOBS	50;

typedef enum TimerMode_t { Once, Repeat, Timer} TMode;
typedef struct Job_t {
	char name[11];
	void (*func)();
	bool (*conditionFunc)();
	int priority;
	TMode mode;
	unsigned long timer;
	time_t time;
	unsigned long atTime;
	time_t atTimeT;
	bool isRun;
}	TJob;

class TimerManager : public Singleton<TimerManager>{
public:
	TimerManager();
	virtual ~TimerManager();
	virtual void addJob(char* name, void (*func)(), bool (*conditionFunc)(), TMode mode, time_t time, unsigned long timer = 0, int priority = 1);
	virtual void startFirstJob();
	virtual void update();

	bool autoSync(time_t ifSyncOK = 14400, time_t ifSyncFailed = 300);
	void setNTPServer(const char *server);
	bool sync();
	bool sendNTPpacket(WiFiUDP& udp);
protected:
	void insertJob(TJob &);
	void sortRunJobs();

	String NtpServerName;
	byte* PacketBuffer;
	time_t LastSync;
	time_t ResyncPeriod;

	void increaseWorkTime(const int delta);
	void restart();
private:
	long long _count;
	unsigned long _workTime;
	TJob *_jobs;
	int *_runJobs;

	long long _lastCheckedJobId;
	unsigned long _lastEndTime;
};

#endif /* TIMERMANAGER_H_ */
