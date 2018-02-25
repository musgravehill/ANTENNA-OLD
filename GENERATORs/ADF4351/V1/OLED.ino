void OLED_init() {
  myOLED.begin();
  myOLED.setBrightness(1);
}

void OLED_display() {
  myOLED.clrScr();
  /*
  myOLED.setFont(SmallFont);
  myOLED.print(":", 28, 10);
  myOLED.setFont(BigNumbers);
  myOLED.printNumI(RTC_hour, 0, 0);
  myOLED.printNumI(RTC_minute, 34, 0);
  //tC
  myOLED.setFont(MediumNumbers);
  myOLED.printNumF(SENSOR_tC, 1, 74, 4);
  myOLED.setFont(SmallFont);
  myOLED.print("o", 122, 0);

  //error
  myOLED.setFont(SmallFont);
  myOLED.print("ALARM", 0, 28);
  if (ALARM__STEPPER_UDO_SENSOR_END_minmax) {
    myOLED.print("UDO", 72, 28);
  }
  if (ALARM__RTC_DATE_incorrect) {
    myOLED.print("DT", 54, 28);
  }
  if (ALARM__SENSOR_tC_minmax) {
    myOLED.print("tC", 36, 28);
  }

  //uptime
  myOLED.setFont(SmallFont);
  myOLED.print("UPTIME DAYS", 0, 40);
  myOLED.printNumI(millis() / 86400000, 72, 40);
*/
  myOLED.update();
}



void showFreq(long FREQ) {
  millions = int(FREQ / 100000000);
  hundredthousands = ((FREQ / 10000000) % 10);
  tenthousands = ((FREQ / 1000000) % 10);
  thousands = ((FREQ / 100000) % 10);
  hundreds = ((FREQ / 10000) % 10);
  tens = ((FREQ / 1000) % 10);
  ones = ((FREQ / 100) % 10);
  hundredHz = ((FREQ / 10) % 10);
  tenHz = ((FREQ) % 10);

  if (millions > 0) {
    //lcd.setCursor(0, 1);
    //lcd.print(millions);
    //lcd.print(".");
  }
  else {
    //lcd.setCursor(2, 1);
  }
  // lcd.print(hundredthousands);
  //lcd.print(tenthousands);
  //lcd.print(thousands);
  //lcd.print(",");
  //lcd.print(hundreds);
  // lcd.print(tens);
  //lcd.print(ones);
  //lcd.print(".");
  // lcd.print(hundredHz);
  //lcd.print(tenHz);
};

