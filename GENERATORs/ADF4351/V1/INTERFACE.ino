
void BUTTON_init() {
  pinMode(BTN_step, INPUT_PULLUP);
  pinMode(BTN_lownoisespur, INPUT_PULLUP);
  pinMode(BTN_out_power, INPUT_PULLUP);
}

void BUTTON_check() {
  boolean button_state;

  //BTN STEP
  button_state = digitalRead(BTN_step);
  if (!button_state) {
    uint32_t  currMillis = millis();
    if ((currMillis - INTERFACE_action_prev_ms) > 1111L) {
      INTERFACE_action_prev_ms = currMillis;
      ADF4351_step_next();
    }
  }

  //BTN LOW noise\spur mode
  button_state = digitalRead(BTN_lownoisespur);
  if (!button_state) {
    uint32_t  currMillis = millis();
    if ((currMillis - INTERFACE_action_prev_ms) > 1111L) {
      INTERFACE_action_prev_ms = currMillis;
      ADF4351_lowNoiseSpurMode_next();
    }
  }

  //BTN output rf power
  button_state = digitalRead(BTN_lownoisespur);
  if (!button_state) {
    uint32_t  currMillis = millis();
    if ((currMillis - INTERFACE_action_prev_ms) > 1111L) {
      INTERFACE_action_prev_ms = currMillis;
      ADF4351_out_power_next();
    }
  }

}

void ENCODER_init() {
  pinMode(ENCODER_button, INPUT_PULLUP);
  pinMode(ENCODER_A, INPUT_PULLUP);
  pinMode(ENCODER_B, INPUT_PULLUP);
}

void ENCODER_check() {
  boolean ENCODER_button_state = digitalRead(ENCODER_button);
  if (!ENCODER_button_state) {
    ADF4351_setConfig();
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
