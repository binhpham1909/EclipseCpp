#ifdef __IN_ECLIPSE__
//This is a automatic generated file
//Please do not modify this file
//If you touch this file your change will be overwritten during the next build
//This file has been generated on 2017-02-14 09:06:55

#include "Arduino.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <DNSServer.h>
#include <TimeLib.h>
#include <Timezone.h>
#include "ModuleSettings.h"
#include "ESP8266WebServerEx.h"
#include "SendEmailSms.h"
#include "NTPClient.h"
#include "TimeSettings.h"
#include "SerialDebug.h"
#include "General.h"
#include "EmailSms.h"
#include "InputPinMgmt.h"
#include "HttpSession.h"
#include "InfoExchg.h"
#include "MyWiFi.h"
#include "ArmLogic.h"
#include "admin.html.h"
#include "email.html.h"
#include "favicon.png.h"
#include "general.html.h"
#include "gpio.html.h"
#include "prog.html.h"
#include "login.html.h"
#include "time.html.h"
#include "device.html.h"
#include "network.html.h"
#include "skeleton.css.h"
#include "normalize.css.h"
#include "main.css.h"
#include "main.js.h"
#include "jquery-3.1.0.min.js.gz.h"
#include "md5.min.js.gz.h"
void setup ( void ) ;
void loop ( void ) ;
void handleRoot() ;
void handleIoPinMaps() ;
void handleNotFound() ;
void SetupGPIO() ;
void handleGetTimeSettings() ;
void handleSetTimeSettings() ;
void handleGetGeneral() ;
void handleSetGeneral() ;
void handleGetEmailSms() ;
void handleSetEmailSms() ;
void handleGetDeviceInfo() ;
void handleGetGpio() ;
void handleGetDeviceList() ;
void handleScanWiFi() ;
void handleGetNetworkSettings(bool bHead) ;
void handleSetNetworkSettings() ;
bool StartAsWifiSTA() ;
bool StartAsWifiAP() ;
void handleRebootEsp() ;
void serialEvent() ;

#include "GarageWithCam_v1.ino"


#endif
