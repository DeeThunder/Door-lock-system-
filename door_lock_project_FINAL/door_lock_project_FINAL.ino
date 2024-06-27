#include "functionDeclaration.h"  // include the functionDeclaration.h tab
#include "functionTab.h" // include the functionTab.h tab
 
void setup()
{
  Serial.begin(9600);
  myservo.attach(25);
  if (!EEPROM.begin (EEPROM_SIZE))
  {
  Serial.println(" EEPROM failed");
  }
lcd.init(); // inititialize lcd
lcd.backlight(); // turn on backlight
lcd.clear();
lcd.setCursor(0,0); // set cursor to row 0 column 0
lcd.print("SET ADMIN"); // print set admin on the lcd
Serial.println("SET ADMIN"); // print set admin on the serial monitor
admin(); // call admin function
delay(1000); // delay for 1000ms
lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("*= SET USER PASSKEY"); 
  Serial.println("*= SET USER PASSKEY");
keyss = Getkeyvalue(); // wait for a key to be pressed
esp_task_wdt_reset(); //Reset the watchdog timer to prevent a reset
if (keyss == '*'){ 
  esp_task_wdt_reset(); //Reset the watchdog timer to prevent a reset
  setuser(); // when * is pressed call the setuser function
  esp_task_wdt_reset(); //Reset the watchdog timer to prevent a reset
  delay(1000);
}
  else { // else skip set user
    lcd.setCursor(0,1);
    lcd.print("USER SET");
  Serial.println("USER SET");
}
  
}

void loop()
{
//  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("WELCOME HOME");
  Serial.println("WELCOME HOME");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ENTER PASSKEY");
  Serial.println("ENTER PASSKEY");
  passkeyy(); // call the passkey function
  delay(3000);
  closedoor(); // call the function to close the door 

delay(2000);

}
