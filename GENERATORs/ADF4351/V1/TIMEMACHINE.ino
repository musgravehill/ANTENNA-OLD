void TIMEMACHINE_loop() {
  uint32_t  TIMEMACHINE_currMillis = millis();
  if ((TIMEMACHINE_currMillis - TIMEMACHINE_prev_3ms) > 3L) {
    TIMEMACHINE_3ms();
    TIMEMACHINE_prev_3ms = TIMEMACHINE_currMillis;
  }
  if ((TIMEMACHINE_currMillis - TIMEMACHINE_prev_211ms) > 211L) {
    TIMEMACHINE_211ms();
    TIMEMACHINE_prev_211ms = TIMEMACHINE_currMillis;
  }
  if ((TIMEMACHINE_currMillis - TIMEMACHINE_prev_1103ms) > 4444L) {
    TIMEMACHINE_1103ms();
    TIMEMACHINE_prev_1103ms = TIMEMACHINE_currMillis;
  }
}

void TIMEMACHINE_3ms() {
  ENCODER_check();
}

void TIMEMACHINE_211ms() {
  OLED_display();
}

void TIMEMACHINE_1103ms() {
  ADF4351_stepsVariantsNumCurrent += 1;
  if (ADF4351_stepsVariantsNumCurrent > 6) {
    ADF4351_stepsVariantsNumCurrent = 0;
  }
  //ADF4351_freqStepCurrent = ADF4351_stepsVariants[ADF4351_stepsVariantsNumCurrent];
  //ADF4351_frequency += ADF4351_freqStepCurrent;
  //ADF4351_setFreq(ADF4351_frequency);




}
