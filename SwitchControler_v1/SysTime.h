/*
 * SysTime.h
 *
 *  Created on: 14 thg 2, 2017
 *      Author: MyPC
 */

#ifndef SYSTIME_H_
#define SYSTIME_H_

#include "Arduino.h"
#include "GlobalConfigs.h"
#include "Singleton.h"
#include "DeviceSetting.h"
#include "DNSServer.h"
#include "ProgmemStruct.h"

#if !defined(__time_t_defined) // avoid conflict with newlib or other posix libc
typedef unsigned long time_t;
#endif


typedef enum {
    dowInvalid, dowSunday, dowMonday, dowTuesday, dowWednesday, dowThursday, dowFriday, dowSaturday
} timeDayOfWeek_t;

typedef enum {
    tmSecond, tmMinute, tmHour, tmWday, tmDay,tmMonth, tmYear, tmNbrFields
} tmByteFields;

typedef struct  {
  uint8_t Second;
  uint8_t Minute;
  uint8_t Hour;
  uint8_t Wday;   // day of week, sunday is day 1
  uint8_t Day;
  uint8_t Month;
  uint8_t Year;   // offset from 1970;
} 	tmElements_t, TimeElements, *tmElementsPtr_t;

//convenience macros to convert to and from tm years
#define  tmYearToCalendar(Y) ((Y) + 1970)  // full four digit year
#define  CalendarYrToTm(Y)   ((Y) - 1970)
#define  tmYearToY2k(Y)      ((Y) - 30)    // offset is from 2000
#define  y2kYearToTm(Y)      ((Y) + 30)



/*==============================================================================*/
/* Useful Constants */
#define SECS_PER_MIN  60UL
#define SECS_PER_HOUR 3600UL
#define SECS_PER_DAY  86400UL
#define DAYS_PER_WEEK 7UL
#define SECS_PER_WEEK 604800UL
#define SECS_PER_YEAR 31499600UL
#define SECS_YR_2000  946684800UL // the time at the start of y2k

/* Useful Macros for getting elapsed time */
#define numberOfSeconds(_time_) (_time_ % SECS_PER_MIN)
#define numberOfMinutes(_time_) ((_time_ / SECS_PER_MIN) % SECS_PER_MIN)
#define numberOfHours(_time_) (( _time_% SECS_PER_DAY) / SECS_PER_HOUR)
#define dayOfWeek(_time_)  ((( _time_ / SECS_PER_DAY + 4)  % DAYS_PER_WEEK)+1) // 1 = Sunday
#define elapsedDays(_time_) ( _time_ / SECS_PER_DAY)  // this is number of days since Jan 1 1970
#define elapsedSecsToday(_time_)  (_time_ % SECS_PER_DAY)   // the number of seconds since last midnight
// The following macros are used in calculating alarms and assume the clock is set to a date later than Jan 1 1971
// Always set the correct time before settting alarms
#define previousMidnight(_time_) (( _time_ / SECS_PER_DAY) * SECS_PER_DAY)  // time at the start of the given day
#define nextMidnight(_time_) ( previousMidnight(_time_)  + SECS_PER_DAY )   // time at the end of the given day
#define elapsedSecsThisWeek(_time_)  (elapsedSecsToday(_time_) +  ((dayOfWeek(_time_)-1) * SECS_PER_DAY) )   // note that week starts on day 1
#define previousSunday(_time_)  (_time_ - elapsedSecsThisWeek(_time_))      // time at the start of the week for the given time
#define nextSunday(_time_) ( previousSunday(_time_)+SECS_PER_WEEK)          // time at the end of the week for the given time


/* Useful Macros for converting elapsed time to a time_t */
#define minutesToTime_t ((M)) ( (M) * SECS_PER_MIN)
#define hoursToTime_t   ((H)) ( (H) * SECS_PER_HOUR)
#define daysToTime_t    ((D)) ( (D) * SECS_PER_DAY) // fixed on Jul 22 2011
#define weeksToTime_t   ((W)) ( (W) * SECS_PER_WEEK)

/*
 * NTP sync time
 *
 */
#define NTP_LOCAL_PORT 2395      // local port to listen for UDP packets
#define NTP_PACKET_SIZE 48 // NTP time stamp is in the first 48 bytes of the message
/*
 * Cac khai bao danh cho TimeZone
 */
//	Cac kieu du lieu
enum week_t {Last, First, Second, Third, Fourth};
enum dow_t {Sun=1, Mon, Tue, Wed, Thu, Fri, Sat};
enum month_t {Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

typedef struct
{
    char abbrev[6];    //five chars max
    uint8_t week;      //First, Second, Third, Fourth, or Last week of the month
    uint8_t dow;       //day of week, 1=Sun, 2=Mon, ... 7=Sat
    uint8_t month;     //1=Jan, 2=Feb, ... 12=Dec
    uint8_t hour;      //0-23
    int offset;        //offset from UTC in minutes
} TimeChangeRule;

// Luu bang timezone vao progmem
const TimeChangeRule TimeZone[] PROGMEM = {
		{"IDLW", First, Sun, Nov, 2, -720}, {"IDLW", First, Sun, Nov, 2, -720},
		{"CUT11", First, Sun, Nov, 2, -660},{"CUT11", First, Sun, Nov, 2, -660},
		{"HAST", First, Sun, Nov, 2, -600}, {"HAST", First, Sun, Nov, 2, -600},
		{"AKDT", Second, Sun, Mar, 2, -480},{"AKST", First, Sun, Nov, 2, -540},
		{"PDT", Second, Sun, Mar, 2, -420}, {"PST", First, Sun, Nov, 2, -480},
		{"PDT", Second, Sun, Mar, 2, -420}, {"PST", First, Sun, Nov, 2, -480},
		{"MDT", Second, Sun, Mar, 2, -360}, {"MST", First, Sun, Nov, 2, -420},
		{"MDT", Second, Sun, Mar, 2, -360}, {"MST", First, Sun, Nov, 2, -420},
		{"MST", First, Sun, Nov, 2, -420},  {"MST", First, Sun, Nov, 2, -420},
		{"CDT", Second, Sun, Mar, 2, -300}, {"CST", First, Sun, Nov, 2, -360},
		{"CST", First, Sun, Nov, 2, -360},  {"CST", First, Sun, Nov, 2, -360},
		{"CDT", Second, Sun, Mar, 2, -300}, {"CST", First, Sun, Nov, 2, -360},
		{"CST", First, Sun, Nov, 2, -360},  {"CST", First, Sun, Nov, 2, -360},
		{"EDT", Second, Sun, Mar, 2, -240}, {"EST", First, Sun, Nov, 2, -300},
		{"EDT", Second, Sun, Mar, 2, -240}, {"EST", First, Sun, Nov, 2, -300},
		{"ACT", First, Sun, Nov, 2, -300},  {"ACT", First, Sun, Nov, 2, -300},
		{"ADT", Second, Sun, Mar, 2, -240}, {"AST", First, Sun, Nov, 2, -180},
		{"VET", First, Sun, Nov, 2, -270},  {"VET", First, Sun, Nov, 2, -270},
		{"CLT", Second, Sun, May, 0, -240}, {"CLST", Second, Sun, Aug, 0, -180},
		{"PYT", Fourth, Sun, Mar, 0, -240}, {"PYST", First, Sun, Oct, 0, -180},
		{"AMT", Third, Sun, Feb, 0, -240},  {"AMST", Third, Sun, Oct, 0, -180},
		{"GYT", First, Sun, Nov, 2, -240},  {"GYT", First, Sun, Nov, 2, -240},
		{"NDT", Second, Sun, Mar, 2, -150}, {"NST", First, Sun, Nov, 2, -210},
		{"BRT", Third, Sun, Feb, 0, -180},  {"BRST", Third, Sun, Oct, 0, -120},
		{"ART", First, Sun, Nov, 2, -180},  {"ART", First, Sun, Nov, 2, -180},
		{"WGT", Fourth, Sat, Mar, 22, -180},{"WGST", Fourth, Sat, Oct, 23, -120},
		{"MALT", First, Sun, Nov, 2, -120}, {"MALT", First, Sun, Nov, 2, -120},
		{"AZOST", Last, Sun, Mar, 0, 0},  {"AZOT", Last, Sun, Oct, 1, -60},
		{"CVE", First, Sun, Nov, 2, -60}, {"CVE", First, Sun, Nov, 2, -60},
		{"BST", Last, Sun, Mar, 1, 60},   {"GMT", Last, Sun, Oct, 2, 0},
		{"CEST", Last, Sun, Mar, 2, 120}, {"CET", Last, Sun, Oct, 3, 60},
		{"CEST", Last, Sun, Mar, 2, 120}, {"CET", Last, Sun, Oct, 3, 60},
		{"CEST", Last, Sun, Mar, 2, 120}, {"CET", Last, Sun, Oct, 3, 60},
		{"CEST", Last, Sun, Mar, 2, 120}, {"CET", Last, Sun, Oct, 3, 60},
		{"WAT", First, Sun, Nov, 2, 60},  {"WAT", First, Sun, Nov, 2, 60},
		{"EEST", Last, Sun, Mar, 3, 180}, {"EET", Last, Sun, Mar, 4, 120},
		{"EET", Last, Sun, Mar, 2, 120},  {"EET", Last, Sun, Mar, 2, 120},
		{"EEST", Last, Sun, Mar, 3, 180}, {"EET", Last, Sun, Mar, 4, 120},
		{"EEST", Last, Sun, Mar, 3, 180}, {"EET", Last, Sun, Mar, 4, 120},
		{"EEST", Last, Sun, Mar, 3, 180}, {"EET", Last, Sun, Mar, 4, 120},
		{"EEST", Last, Sun, Mar, 3, 180}, {"EET", Last, Sun, Mar, 4, 120},
		{"MSK", First, Sun, Nov, 2, 120}, {"MSK", First, Sun, Nov, 2, 120},
		{"IDT", Fourth, Fri, Mar, 2, 180},  {"IST", Last, Sun, Oct, 2, 120},
		{"CAT", First, Sun, Nov, 2, 120}, {"CAT", First, Sun, Nov, 2, 120},
		{"MSK", First, Sun, Nov, 2, 180}, {"MSK", First, Sun, Nov, 2, 180},
		{"AST", First, Sun, Nov, 2, 180}, {"AST", First, Sun, Nov, 2, 180},
		{"EAT", First, Sun, Nov, 2, 180}, {"EAT", First, Sun, Nov, 2, 180},
		{"AST", First, Sun, Nov, 2, 180}, {"AST", First, Sun, Nov, 2, 180},
		{"GST", First, Sun, Nov, 2, 240}, {"GST", First, Sun, Nov, 2, 240},
		{"AZT", First, Sun, Nov, 2, 240}, {"AZT", First, Sun, Nov, 2, 240},
		{"AFT", First, Sun, Nov, 2, 270}, {"AFT", First, Sun, Nov, 2, 270},
		{"YEKT", First, Sun, Nov, 2, 300},  {"YEKT", First, Sun, Nov, 2, 300},
		{"PKT", First, Sun, Nov, 2, 300}, {"PKT", First, Sun, Nov, 2, 300},
		{"IST", First, Sun, Nov, 2, 330}, {"IST", First, Sun, Nov, 2, 330},
		{"NPT", First, Sun, Nov, 2, 345}, {"NPT", First, Sun, Nov, 2, 345},
		{"BST", First, Sun, Nov, 2, 360}, {"BST", First, Sun, Nov, 2, 360},
		{"IST", First, Sun, Nov, 2, 360}, {"IST", First, Sun, Nov, 2, 360},
		{"ALMT", First, Sun, Nov, 2, 360},  {"ALMT", First, Sun, Nov, 2, 360},
		{"MMT", First, Sun, Nov, 2, 390}, {"MMT", First, Sun, Nov, 2, 390},
		{"ICT", First, Sun, Nov, 2, 420}, {"ICT", First, Sun, Nov, 2, 420},
		{"KRAT", First, Sun, Nov, 2, 420},  {"KRAT", First, Sun, Nov, 2, 420},
		{"CST", First, Sun, Nov, 2, 480}, {"CST", First, Sun, Nov, 2, 480},
		{"SGT", First, Sun, Nov, 2, 480}, {"SGT", First, Sun, Nov, 2, 480},
		{"CST", First, Sun, Nov, 2, 480}, {"CST", First, Sun, Nov, 2, 480},
		{"AWST", First, Sun, Nov, 2, 480},  {"AWST", First, Sun, Nov, 2, 480},
		{"ULAST", Last, Sat, Mar, 2, 540},  {"ULAT", Last, Sat, Sep, 0, 480},
		{"KST", First, Sun, Nov, 2, 540}, {"KST", First, Sun, Nov, 2, 540},
		{"JST", First, Sun, Nov, 2, 540}, {"JST", First, Sun, Nov, 2, 540},
		{"YAKT", First, Sun, Nov, 2, 540},  {"YAKT", First, Sun, Nov, 2, 540},
		{"ACST", First, Sun, Nov, 2, 570},  {"ACST", First, Sun, Nov, 2, 570},
		{"ACDT", First, Sun, Oct, 2, 630},  {"ACST", First, Sun, Apr, 3, 570},
		{"AEDT", First, Sun, Oct, 2, 660},  {"AEST", First, Sun, Apr, 3, 600},
		{"AEST", First, Sun, Nov, 2, 600},  {"AEST", First, Sun, Nov, 2, 600},
		{"AEDT", First, Sun, Oct, 2, 660},  {"AEST", First, Sun, Apr, 3, 600},
		{"VLAT", First, Sun, Nov, 2, 600},  {"VLAT", First, Sun, Nov, 2, 600},
		{"CHST", First, Sun, Nov, 2, 600},  {"CHST", First, Sun, Nov, 2, 600},
		{"NCT", First, Sun, Nov, 2, 660}, {"NCT", First, Sun, Nov, 2, 660},
		{"MHT", First, Sun, Nov, 2, 720}, {"MHT", First, Sun, Nov, 2, 720},
		{"NZDT", Last, Sun, Sep, 2, 780}, {"NZST", First, Sun, Apr, 3, 720}
};

/*
 * Cac khai bao danh cho dinh dang chuoi thu, ngay, thang
 *
 */
static char dt_buffer[10];

typedef struct{
	char full[10];
	char min[4];
}	nameMonthDay_t;


const nameMonthDay_t DayStr[8] PROGMEM = {
		{"Err", "Err"},
		{"Sunday", "Sun"},
		{"Monday", "Mon"},
		{"Tuesday", "Tue"},
		{"Wednesday", "Wed"},
		{"Thursday", "Thu"},
		{"Friday", "Fri"},
		{"Saturday", "Sat"}
};

const nameMonthDay_t MonthStr[13] PROGMEM = {
		{"", "Err"},
		{"January", "Jan"},
		{"February", "Feb"},
		{"March", "Mar"},
		{"April", "Apr"},
		{"May", "May"},
		{"June", "Jun"},
		{"July", "Jul"},
		{"August", "Aug"},
		{"September", "Sep"},
		{"October", "Oct"},
		{"November", "Nov"},
		{"December", "Dec"}
};
const uint8_t monthDays[]={31,28,31,30,31,30,31,31,30,31,30,31}; // API starts months from 1, this array starts from 0
// the short strings for each day or month must be exactly dt_SHORT_STR_LEN


class SysTime : public Singleton<SysTime>{
public:
	SysTime();
	virtual ~SysTime();
	void init();
	void    setTime(time_t t);
	void    setTime(int hr,int min,int sec,int day, int month, int yr);
	void    adjustTime(long adjustment);

	/*  time and date functions   */
	time_t	nowLocal();              // tra lai so giay tai dia phuong tinh tu 1/1/1970
	time_t	now();              // tra lai so giay tinh tu 1/1/1970
	int     hour();            // gio hien tai
	int     hour(time_t t);    // gio tinh theo giay unix nhap vao
	int     hourFormat12();    // gio hien tai dinh dang 12 h
	int     hourFormat12(time_t t); // gio tinh theo giay unix nhap vao dinh dang 12 h
	uint8_t isAM();            // returns true if time now is AM
	uint8_t isAM(time_t t);    // returns true the given time is AM
	uint8_t isPM();            // returns true if time now is PM
	uint8_t isPM(time_t t);    // returns true the given time is PM
	int     minute();          // the minute now
	int     minute(time_t t);  // the minute for the given time
	int     second();          // the second now
	int     second(time_t t);  // the second for the given time
	int     day();             // the day now
	int     day(time_t t);     // the day for the given time
	int     weekday();         // the weekday now (Sunday is day 1)
	int     weekday(time_t t); // the weekday for the given time
	int     month();           // the month now  (Jan is month 1)
	int     month(time_t t);   // the month for the given time
	int     year();            // the full four digit year: (2009, 2010 etc)
	int     year(time_t t);    // the year for the given time
	char* 	monthStr(uint8_t month);
	char*	dayStr(uint8_t day);
	char*	monthShortStr(uint8_t month);
	char*	dayShortStr(uint8_t day);

	// Timezone
	time_t toLocal(time_t utc);
	time_t toUTC(time_t local);
	boolean utcIsDST(time_t utc);
	boolean locIsDST(time_t local);

	// Time NTP
	void setNTPServer(const char *server);
	bool syncNTP();
	bool AutoSync(time_t ifSyncOK = 14400, time_t ifSyncFailed = 300);
private:
	tmElements_t _tm;          // a cache of time elements
	time_t _cacheTime;   // the time the cache was updated
	uint32_t _syncInterval;  // time sync will be attempted after this many seconds
	uint32_t _sysTime;
	uint32_t _prevMillis;
	uint32_t _nextSyncTime;
	bool _isSetTime;
	int _localIndex;

	void	refreshCache(time_t t);
	bool isSetTime(); // indicates if time has been set and recently synchronized
	void breakTime(time_t time, tmElements_t &tm);  // chuyen time_t thanh cac gia tri thoi gian
	time_t makeTime(tmElements_t &tm);  // chuyen cac gia tri thoi gian thanh time_t
	bool isLeapYear(uint8_t year);	// return true neu la nam nhuan
	// TimeZone
	void calcTimeChanges(int yr);
	time_t toTime_t(TimeChangeRule r, int yr);
	TimeChangeRule _dst;    //rule for start of dst or summer time for any year
	TimeChangeRule _std;    //rule for start of standard time for any year
	time_t _dstUTC;         //dst start for given/current year, given in UTC
	time_t _stdUTC;         //std time start for given/current year, given in UTC
	time_t _dstLoc;         //dst start for given/current year, given in local time
	time_t _stdLoc;         //std time start for given/current year, given in local time
	// NTP time
	bool sendNTPpacket(WiFiUDP& udp);
	String _NtpServerName;
	byte* _packetBuffer;
	time_t _lastSync;
	time_t _resyncPeriod;
};


#endif /* SYSTIME_H_ */
