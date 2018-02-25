void BUTTON_check() {
  //int8_t btnState1, btnState2;
  //btnState1 = digitalRead(BUTTON_udo_push);

}

void ENCODER_init() {
  pinMode(ENCODER_button, INPUT_PULLUP);
  pinMode(ENCODER_A, INPUT_PULLUP);
  pinMode(ENCODER_B, INPUT_PULLUP);
}
void ENCODER_check() {

  boolean ENCODER_button_state = digitalRead(ENCODER_button);
  if (!ENCODER_button_state) {
    uint32_t  currMillis = millis();
    if ((currMillis - ADF4351_changeConfig_prev_ms) > 1111L) {
      ADF4351_changeConfig_prev_ms = currMillis;
      Serial.println("ENCODER BTN");
      ADF4351_setFreq();
    }
  }

  ENCODER_A_state = digitalRead(ENCODER_A);
  ENCODER_B_state = digitalRead(ENCODER_B);
  if ((!ENCODER_A_state) && (ENCODER_A_state_prev))  {
    if (ENCODER_B_state) {
      ADF4351_freq_inc();
    }
    else {
      ADF4351_freq_dec();
    }
  }
  ENCODER_A_state_prev = ENCODER_A_state;
}
