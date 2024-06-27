#include <Keypad.h> // including the libarary for keypad
#include<EEPROM.h> // including the EEPROM library
#include <Wire.h>  // including the wire library
#include <LiquidCrystal_I2C.h> // including the liquidcrystal library
#include <ESP32Servo.h> // including the servo motor library
#include <esp_task_wdt.h> // including the inbuilt library for reseting the waiting time 

Servo myservo; // initializing the servo motor
  int pos = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2); // setting  the  display size of the lcd
// delaring varaibalesint j; 
  int password[8];
  int user1[8];
  int user2[8];
  int user3[8];
  int user4[8];
  int passkey[8];
  int keyss;

#define EEPROM_SIZE 100 // defining the address size of the eeprom

const byte rows = 4; //defining the row size of thr keypad
const byte columns = 4; // defining the column size of the keypad
// defining the keypad lock accoring to physical view 
char hexaKeys[rows][columns] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};
byte row_pins[rows] = {16,15,14,13};  // defining the pin for connecting R1, R2, R3,R4
byte column_pins[columns]= {17,5,18,19}; // defining the pin for connecting C1, C2, C3, C4
Keypad keypad_key=Keypad( makeKeymap(hexaKeys),row_pins,column_pins,rows,columns); //initializing the defined keypad


extern char Getkeyvalue(); // calling the external function Getkeyvalue
extern void admin(); // calling the external function admin
extern void userA(); // calling the external function userA
extern void userB(); // calling the external function userB
extern void userC(); // calling the external function userC
extern void userD(); // calling the external function userD
extern int setuser(); // calling the external function setuser
extern void opendoor(); // calling the external function opendoor
extern void closedoor(); // calling the external function closedoor
extern void passkeyy(); // calling the external function passkeyy
extern bool confirm( int startAddress,int passkey[8]); // calling the external function confirm
