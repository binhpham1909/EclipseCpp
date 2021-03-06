// Do not remove the include below
#include "heater_chamber_v1.h"

// PIN connector
// LCD pin connect
#define LCD_SCK 17
#define LCD_MOSI  16
#define LCD_DC 15
#define LCD_RST 11
#define LCD_CS 14
#define LCD_LIGHT 12	// write LOW to turn on backlight
// Sensor pin
#define DS18B20_PIN 6	// Pin to sensor ds18b20
#define DHTPIN 7	// Pin to sensor humi DHT22

// Button and led indicator
#define MENU_BUTTON 4	// Pin connect to menu button, pull up internal
#define UP_BUTTON 2
#define ALERT_LAMP  13
#define DOWN_BUTTON 3
#define LIGHT_BUTTON 5
// Output pin
#define	HUMI_GENERATE	8	// Connect to moisture generate
#define SSR_PIN 9	// Connect to IGBT control

// define for button and menu
#define DEBOUNCE 10	// time wait between two times press
#define NUMBUTTONS sizeof(buttons)
#define MAX_MENU  2	// Maximum menu after view screen
#define MENU_NORMAL  0	// View status screen
#define MENU_SETTEMP  1	// Menu setup temp
#define MENU_SETHUMI  2	// Menu etup humi

#define STEP_SET_TEMP 0.1	// Step setup value of temp set
#define STEP_SET_HUMI 0.1	// Step setup value of humi set
byte buttons[] = {MENU_BUTTON, UP_BUTTON, DOWN_BUTTON,LIGHT_BUTTON};
char  NowMenu=0;
volatile boolean last_state[NUMBUTTONS];
volatile long lasttime;

boolean OutHumi=false;
float dht_temp,dht_humi;
double SetTemp,SetHumi, NowTemp, OutPWM, LastInput;
//Define the aggressive and conservative Tuning Parameters
double aggKp=4, aggKi=0.2, aggKd=1;
double consKp=1, consKi=0.05, consKd=0.25;

char row1[14];
char row6[14];
byte ds_stt;
configs cfg;
OneWire  ds(DS18B20_PIN);
DHT22 dht(DHTPIN);
PID myPID(&NowTemp, &OutPWM, &SetTemp, consKp, consKi, consKd, DIRECT);
LCD5110 LCD(LCD_SCK,LCD_MOSI,LCD_DC,LCD_RST,LCD_CS);

void setup(void) {
//  save_configs();
  Serial.begin(115200);
  read_configs();
  InitButton();
  LCD.InitLCD();
  pinMode(LCD_LIGHT, OUTPUT); digitalWrite(LCD_LIGHT, LOW);
  pinMode(ALERT_LAMP, OUTPUT);  digitalWrite(ALERT_LAMP, HIGH);
  pinMode(SSR_PIN, OUTPUT);
  SetTemp=cfg.DispTemp;
  myPID.SetMode(AUTOMATIC);
  LCD.drawBitmap(0, 0, arduino_logo, 84, 48); delay(2000);
  LCD.invert(true); delay(500); LCD.invert(false);  delay(500);
  digitalWrite(ALERT_LAMP, LOW);
}
SIGNAL(TIMER2_OVF_vect) { CheckButtons();}

void loop(void) {
	SetTemp=cfg.DispTemp;
	SetHumi=cfg.DispHumi;
	float ndo = read_ds(&ds_stt);
	if(ndo!=9999) NowTemp=ndo;
	read_dht(&dht_temp,&dht_humi);
	double gap = abs(SetTemp-NowTemp); //distance away from setpoint
	if (gap < 10){  //we're close to setpoint, use conservative tuning parameters
		myPID.SetTunings(consKp, consKi, consKd);
	}else{	//we're far from setpoint, use aggressive tuning parameters
		myPID.SetTunings(aggKp, aggKi, aggKd);
	}
	myPID.Compute();
	analogWrite(SSR_PIN, (byte)OutPWM);
	if(dht_humi<SetHumi){	digitalWrite(HUMI_GENERATE, HIGH);}else{		digitalWrite(HUMI_GENERATE, LOW);}
	Display();
}
void Display(void){
	strcpy_P(row1, (char*)pgm_read_word(&(lb_menu[NowMenu])));
	strcpy_P(row6, (char*)pgm_read_word(&(DsStt[ds_stt])));
	LCD.clrScr();
	LCD.drawRect(0, 0, 83,47);
	LCD.setFont(SmallFont);
	LCD.print(row1, 1, 1);
	LCD.print("Hot", 1, 11);LCD.printNumF(NowTemp,1,30,11,1);LCD.printNumI(OutPWM,59,11,1);
	if((NowMenu==MENU_NORMAL)||(NowMenu==MENU_SETHUMI)){
		LCD.print("Humi", 1, 21);LCD.printNumF(dht_humi,1,30,21,1);LCD.printNumI(SetHumi,59,21,1);
	}
	if((NowMenu==MENU_NORMAL)||(NowMenu==MENU_SETTEMP)){
		LCD.print("Temp", 1, 31);LCD.printNumF(dht_temp,1,30,31,1);LCD.printNumI(SetTemp,59,31,1);
	}
	LCD.setFont(TinyFont);
	LCD.print(row6, 1, 41);
	LCD.update();
}
void InitButton(void){
	// Make input & enable pull-up resistors on switch pins
	  for (byte i=0; i<NUMBUTTONS;i++){
	    pinMode(buttons[i], INPUT);
	    digitalWrite(buttons[i], HIGH);
	  }
	// Run timer2 interrupt every 15 ms
	  TCCR2A = 0;
	  TCCR2B = 1<<CS22 | 1<<CS21 | 1<<CS20;
	//Timer2 Overflow Interrupt Enable
	  TIMSK2 |= 1<<TOIE2;
}
void CheckButtons(void){
  byte now_state[NUMBUTTONS];
  digitalWrite(ALERT_LAMP,(boolean)NowMenu);
  if ((lasttime + DEBOUNCE) > millis()) {
    return; // not enough time has passed to debounce
  }
  // ok we have waited DEBOUNCE milliseconds, lets reset the timer
  lasttime = millis();
  for (byte i=0; i<NUMBUTTONS;i++){
    now_state[i]=digitalRead(buttons[i]);   // read the button
    if (now_state[i] != last_state[i]) {
      if (now_state[i] == LOW) {
        //process button
    	  ProcessButton(i);
      }
    last_state[i] = now_state[i];   // keep a running tally of the buttons
    }
  }
};

void ProcessButton(byte bt){
    switch (buttons[bt]) {
    case MENU_BUTTON:
    	MenuButton();
      break;
    case UP_BUTTON:
      UpButton(NowMenu);
      break;
    case DOWN_BUTTON:
      DownButton(NowMenu);
      break;
    case LIGHT_BUTTON:
      digitalWrite(LCD_LIGHT, !digitalRead(LCD_LIGHT));
      break;
  }
};
void MenuButton(void){
	NowMenu++;
	if(NowMenu>MAX_MENU){NowMenu=0;}
};
void UpButton(byte mn){
    switch (mn) {
    case MENU_SETTEMP:
      set_temp(cfg.DispTemp + STEP_SET_TEMP);
      break;
    case MENU_SETHUMI:
      set_humi(cfg.DispHumi + STEP_SET_HUMI);
      break;
  }
};
void DownButton(byte mn){
    switch (mn) {
    case MENU_SETTEMP:
      set_temp(cfg.DispTemp - STEP_SET_TEMP);
      break;
    case MENU_SETHUMI:
      set_humi(cfg.DispTemp - STEP_SET_HUMI);
      break;
  }
};
void read_configs(void){
  EEPROM.get( ADDR_CONFIG, cfg );
};
void save_configs(void){
  EEPROM.put( ADDR_CONFIG, cfg );
};

void set_debug(boolean _debug){
  cfg.debug=_debug;
  save_configs();
  read_configs();
};
boolean set_serial(String _serial){
  if(_serial.length()==9){
    _serial.toCharArray(*cfg.serial, _serial.length()+1);
    save_configs();
    read_configs();
    return true;
  }else{
    return false;
  }
};
void set_temp(float _temp){
  cfg.DispTemp = _temp;
  save_configs();
  read_configs();
};
void set_humi(float _humi){
  cfg.DispHumi = _humi;
  save_configs();
  read_configs();
};
// Analysis command : key==value\n

// == separate
// "\n" end
void DeCommand(String *_request, String _separate,String *_key,String *_val){
    int g_end,g_compare;
    g_compare = _request->indexOf(_separate,0);
    g_end = _request->indexOf('\n',g_compare);
  *_key=_request->substring(0, g_compare);
    *_val=_request->substring(g_compare+_separate.length(), g_end);
}
float read_ds(byte *stt){
  byte i;
  byte present = 0;
  byte type_s;
  byte data[12];
  byte addr[8];
  boolean update_temp=0;
  if ( !ds.search(addr)) {
    *stt=DsSttScanning;
    ds.reset_search();
    delay(250);
    return 9999;
  }

  if (OneWire::crc8(addr, 7) != addr[7]) {
    *stt=DsCRCError;
    return 9999;
  }
  // the first ROM byte indicates which chip
  switch (addr[0]) {
    case 0x10:
      *stt=DsChip18S20;  // or old DS1820
      type_s = 1;
      update_temp=1;
      break;
    case 0x28:
      *stt=DsChip18B20;
      type_s = 0;
      update_temp=1;
      break;
    case 0x22:
      *stt=DsChip1822;
      type_s = 0;
      update_temp=1;
      break;
    default:
      *stt=DsChipError;
      update_temp=0;
  }

  ds.reset();
  ds.select(addr);
  ds.write(0x44, 1);        // start conversion, with parasite power on at the end

  delay(1000);     // maybe 750ms is enough, maybe not
  // we might do a ds.depower() here, but the reset will take care of it.

  present = ds.reset();
  ds.select(addr);
  ds.write(0xBE);         // Read Scratchpad
  for ( i = 0; i < 9; i++) {           // we need 9 bytes
    data[i] = ds.read();
  }
  // Convert the data to actual temperature
  // because the result is a 16 bit signed integer, it should
  // be stored to an "int16_t" type, which is always 16 bits
  // even when compiled on a 32 bit processor.
  int16_t raw = (data[1] << 8) | data[0];
  if (type_s&&update_temp) {
    raw = raw << 3; // 9 bit resolution default
    if (data[7] == 0x10) {
      // "count remain" gives full 12 bit resolution
      raw = (raw & 0xFFF0) + 12 - data[6];
    }
  } else if((!type_s)&&update_temp) {
    byte cfg = (data[4] & 0x60);
    // at lower res, the low bits are undefined, so let's zero them
    if (cfg == 0x00) raw = raw & ~7;  // 9 bit resolution, 93.75 ms
    else if (cfg == 0x20) raw = raw & ~3; // 10 bit res, 187.5 ms
    else if (cfg == 0x40) raw = raw & ~1; // 11 bit res, 375 ms
    //// default is 12 bit resolution, 750 ms conversion time
  }
  return (double)raw / 16.0;
};
void read_dht(float *t,float *h){
	DHT22_ERROR_t errorCode;
	errorCode = dht.readData();
	  switch(errorCode)
	  {
	    case DHT_ERROR_NONE:
	    	*t=dht.getTemperatureC();
	    	*h=dht.getHumidity();
	    break;
	    default :

	    break;
	  }
};
