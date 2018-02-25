void OLED_init() {
  myOLED.begin();
  myOLED.setBrightness(1);
}

void OLED_display() {
  myOLED.clrScr();

  myOLED.setFont(SmallFont);
  //myOLED.print("MHz", 110, 5);

  myOLED.print("STEP", 0, 23);
  myOLED.print("kHz", 110, 23);

  myOLED.print("OUT", 0, 40);
  myOLED.print("dBm", 66, 41);

  myOLED.print("NOLOCK", 92, 56);
  myOLED.print("LOW NOISE", 0, 56);

  myOLED.setFont(MediumNumbers);
  float frq = ADF4351_frequency / 100000.0; // 1 000 00 (*10hz)
  myOLED.printNumF(frq, 5, 0, 0);

  float fstep = ADF4351_stepsVariants[ADF4351_stepsVariantsNumCurrent] / 100.0; //100*10Hz
  myOLED.printNumF(fstep, 2, 36, 18);

  int8_t fpower = -3;
  myOLED.printNumI(fpower, 36, 36);

  myOLED.update();
}




