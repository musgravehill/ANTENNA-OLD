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
  myOLED.print(ADF4351_lowNoiseOrSpur_verb[ADF4351_lowNoiseOrSpur_current], 0, 56);
  if (ADF4351_isNeedSetNewConfig) {
    if (OLED_blynk_state) {
      myOLED.print("*", 122, 5);
      OLED_blynk_state = false;
    } else {
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

  myOLED.print(ADF4351_outputPower_verb[ADF4351_outputPower_current], 36, 36);

  myOLED.update();
}




