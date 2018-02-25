void OLED_init() {
  myOLED.begin();
  myOLED.setBrightness(1);
}

void OLED_display() {
  myOLED.clrScr();

  myOLED.setFont(SmallFont);
  myOLED.print("STEP", 0, 23);
  myOLED.print(OLED_stepsVariants_kmhz[ADF4351_stepsVariantsNumCurrent], 90, 25);
  myOLED.print("OUT", 0, 40);
  myOLED.print("dBm", 66, 41);
  myOLED.print("NOLOCK", 92, 56);
  myOLED.print("LOW NOISE", 0, 56);
  if (ADF4351_isNeedSetNewFreq) {
    if (OLED_blynk_state) {
      myOLED.print("*", 122, 6);
      OLED_blynk_state = false;
    } else {
      //myOLED.print(" ", 122, 6);
      OLED_blynk_state = true;
    }

  }

  myOLED.setFont(MediumNumbers);
  long f_m = (long)ADF4351_frequency / (long)100000; //*10Hz
  long f_k =  (ADF4351_frequency % 100000); //*10Hz
  myOLED.printNumI(f_m, 0, 0, 4, '0');
  myOLED.printNumI(f_k, 60, 0, 5, '0');
  myOLED.print(".", 47, 0);

  myOLED.print(OLED_stepsVariants_val[ADF4351_stepsVariantsNumCurrent], 36, 18);

  int8_t fpower = -3;
  myOLED.printNumI(fpower, 36, 36);

  myOLED.update();
}




