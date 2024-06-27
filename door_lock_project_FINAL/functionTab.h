char Getkeyvalue() { // function to wait for a key to be pressed
  int keys = keypad_key.getKey();
  esp_task_wdt_reset();
  while (keys == NO_KEY) { // while no key is pressed it should wait for a key to be pressed
    keys = keypad_key.getKey();
    //Reset the watchdog timer to prevent a reset
    esp_task_wdt_reset();
  }
  return keys;
}

void admin() { //function to save admin passkey
  int j;
  lcd.setCursor(0, 1);
  lcd.print("ENTER ADMIN PASSKEY");
  Serial.println("ENTER ADMIN PASSKEY");
  for (j = 0; j < 8; j++) //initalizes the size of admin pasaskey
  {
    password[j] = Getkeyvalue()  - '0';
    //Reset the watchdog timer to prevent a reset
    esp_task_wdt_reset();
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("*");
    Serial.println(password[j]);
    EEPROM.write(j, password[j]); // writes each passkey to the defined address // saves admin passkey to address starting from 0
    EEPROM.commit();
  }
  for (j = 0; j < 8; j++)
  {
    esp_task_wdt_reset();
    password[j] = EEPROM.read(j); // reads the admin passkey from the eeprom
    Serial.print(EEPROM.read(j));
  }
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("SAVED ADMIN");
  Serial.println("SAVED ADMIN");
}

void userA() { // function to save userA passkey
  int j;
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("ENTER USER A PASSKEY");
  Serial.println("ENTER USER A PASSKEY");
  for (j = 0; j < 8; j++)
  {
    user1[j] = Getkeyvalue()  - '0'; // accepts userA passkey
    //Reset the watchdog timer to prevent a reset
    esp_task_wdt_reset();
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("*");
    Serial.println(user1[j]);
    EEPROM.write(11 + j, user1[j]); // saves user a passkey to address starting from 11
    EEPROM.commit();
  }
  for (j = 11; j < 19; j++)
    esp_task_wdt_reset();
  {
    user1[j] = EEPROM.read(j); // reads the userA passkey from the eeprom
  }
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("SAVED USER A");
  Serial.println("SAVED USER A");
}

void userB() { // function to save userB passkey
  int j;
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("ENTER USER B PASSKEY");
  Serial.println("ENTER USER B PASSKEY");
  for (j = 0; j < 8; j++)
  {
    user2[j] = Getkeyvalue()  - '0'; // accepts userB passkey
    //Reset the watchdog timer to prevent a reset
    esp_task_wdt_reset();
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("*");
    Serial.println(user2[j]);
    EEPROM.write(21 + j, user2[j]); // saves user b passkey to address starting from 21
    EEPROM.commit();
  }
  for (j = 21; j < 29; j++)
    esp_task_wdt_reset();
  {
    user2[j] = EEPROM.read(j); // reads the userB passkey from the eeprom
  }
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("SAVED USER B");
  Serial.println("SAVED USER B");
}
void userC() { // function to save userC passkey
  int j;
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("ENTER USER C PASSKEY");
  Serial.println("ENTER USER C PASSKEY");
  for (j = 0; j < 8; j++)
  {
    user3[j] = Getkeyvalue()  - '0'; // accepts userA passkey
    //Reset the watchdog timer to prevent a reset
    esp_task_wdt_reset();
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("*");
    Serial.println(user3[j]);
    EEPROM.write(31 + j, user3[j]); // saves user c passkey to address starting from 31
    EEPROM.commit();
  }
  for (j = 31; j < 39; j++)
    esp_task_wdt_reset();
  {
    user3[j] = EEPROM.read(j); // reads the userC passkey from the eeprom
  }
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("SAVED USER C");
  Serial.println("SAVED USER C");
}

void userD() {
  int j;
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("ENTER USER D PASSKEY");
  Serial.println("ENTER USER D PASSKEY");
  for (j = 0; j < 8; j++)
  {
    user4[j] = Getkeyvalue()  - '0';
    //Reset the watchdog timer to prevent a reset
    esp_task_wdt_reset();
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("*");
    Serial.println(user4[j]);
    EEPROM.write(41 + j, user4[j]);
    EEPROM.commit();
  }
  for (j = 41; j < 49; j++)
    esp_task_wdt_reset();
  {
    user4[j] = EEPROM.read(j);
  }
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("SAVED USER D");
  Serial.println("SAVED USER D");
}

int setuser() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("A=user A   B=user B");
  lcd.setCursor(0, 1);
  lcd.print("C=user C   D=user D");

  Serial.println ("A=user A   B=user B");
  Serial.println ("C=user C   D=user D");

  delay(500);

  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("0=TERMINATE");
  Serial.println("Press 8 to terminate");


  char keyss = Getkeyvalue() ;
  esp_task_wdt_reset();
  Serial.println(keyss);
  if (keyss == 'A') {
    esp_task_wdt_reset();
    userA();
  }
  else if (keyss == 'B') {
    //Reset the watchdog timer to prevent a reset
    esp_task_wdt_reset();
    userB();

  }
  else if (keyss == 'C') {
    //Reset the watchdog timer to prevent a reset
    esp_task_wdt_reset();
    userC();

  }
  else if (keyss == 'D') {
    //Reset the watchdog timer to prevent a reset
    esp_task_wdt_reset();
    userD();
  }
  else if (keyss == '0') {
    lcd.setCursor(0, 1);
    lcd.print("Terminate User Set");
    Serial.println("Terminate User Set");
  }
  return keyss;
}

void opendoor() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("OPENING DOOR");
  Serial.println("OPENING DOOR");
  for (pos = 0; pos <= 180; pos += 90) {
    myservo.write(pos);
    delay(50);
  }
}

void closedoor() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("CLOSING DOOR");
  Serial.println("CLOSING DOOR");
  for (pos = 90; pos >= 0; pos -= 90) {
    myservo.write(pos);
    delay(50);
  }
}

void passkeyy() {
  int j;
  for (j = 0; j < 8; j++)
  {
    passkey[j] = Getkeyvalue()  - '0';
    //Reset the watchdog timer to prevent a reset
    esp_task_wdt_reset();
    lcd.setCursor(0, 1);
    lcd.print("*");
    Serial.println(passkey[j]);
  }
  bool passok1 = confirm(0, passkey);
  bool passok2 = confirm(11, passkey);
  bool passok3 = confirm(21, passkey);
  bool passok4 = confirm(31, passkey);
  bool passok5 = confirm(41, passkey);
  if (passok1) {
    opendoor();
  }
  else if (passok2) {
    opendoor();
  }
  else if (passok3) {
    opendoor();
  }
  else if (passok4) {
    opendoor();
  }
  else if (passok5) {
    opendoor();
  }
  else {
    Serial.println(" WRONG PASSKEY ");
  }
}


bool confirm( int startAddress, int passkey[8]) {
  for ( int j = 0; j < 8; j++) {
    if (EEPROM.read (j + startAddress) != passkey[j])
    {
      return false;
    }
  }
  return true;
}
