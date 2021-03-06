// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _heater_chamber_v1_H_
#define _heater_chamber_v1_H_
#include "Arduino.h"
//add your includes for the project heater_chamber_v1 here
#include <EEPROM.h>
#include <PID_v1.h>
#include <LCD5110_Graph.h>
#include <OneWire.h>
#include "DHT22.h"
#include <avr/pgmspace.h>

//end of add your includes here
#ifdef __cplusplus
extern "C" {
#endif
#define _ROM_CONFIG_ 0
void loop();
void setup();
#ifdef __cplusplus
} // extern "C"
#endif
//add your function definitions for the project heater_chamber_v1 here
#define ADDR_CONFIG 0
#define	DsSttScanning	0
#define	DsCRCError	1
#define DsChip18S20	2
#define	DsChip18B20	3
#define	DsChip1822	4
#define	DsChipError	5
extern uint8_t arduino_logo[];
extern unsigned char TinyFont[];
extern unsigned char SmallFont[];
extern unsigned char MediumNumbers[];

const char lb_menu0[] PROGMEM="Heater chamber";
const char lb_menu1[] PROGMEM="Setup Temp";
const char lb_menu2[] PROGMEM="Setup Humi";
const char* const lb_menu[] PROGMEM ={lb_menu0,lb_menu1,lb_menu2};
const char Scanning[] PROGMEM="Scanning sensor";
const char CRCError[] PROGMEM="CRC not valid!";
const char Chip18S20[] PROGMEM="Chip = DS18S20 ";
const char Chip18B20[] PROGMEM="Chip = DS18B20 ";
const char Chip1822[] PROGMEM="Chip = DS1822";
const char ChipError[] PROGMEM="Not DS18x20 device.";
const char* const DsStt[] PROGMEM ={Scanning,CRCError,Chip18S20,Chip18B20,Chip1822,ChipError};

struct configs{
  boolean debug=true;
  char* serial[10]={"THC0000001"};
  float DispTemp=60;
  float DispHumi=60;
};
void Display(void);
void InitButton(void);
void CheckButtons(void);
void MenuButton(void);
void ProcessButton(byte bt);
void UpButton(byte mn);
void DownButton(byte mn);
void read_configs(void);
void save_configs(void);
void set_debug(boolean _debug);
boolean set_serial(String _serial);
void set_temp(float _temp);
void set_humi(float _humi);
void DeCommand(String *_request, String _separate,String *_key,String *_val);
float read_ds(byte *stt);
void read_dht(float *t,float *h);


//Do not add code below this line
#endif /* _heater_chamber_v1_H_ */
