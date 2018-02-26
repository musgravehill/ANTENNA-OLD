void TIMEMACHINE_loop() {
  uint32_t  TIMEMACHINE_currMillis = millis();
  if ((TIMEMACHINE_currMillis - TIMEMACHINE_prev_3ms) > 3L) {
    TIMEMACHINE_3ms();
    TIMEMACHINE_prev_3ms = TIMEMACHINE_currMillis;
  }
  if ((TIMEMACHINE_currMillis - TIMEMACHINE_prev_311ms) > 311L) {
    TIMEMACHINE_311ms();
    TIMEMACHINE_prev_311ms = TIMEMACHINE_currMillis;
  }
  
}

void TIMEMACHINE_3ms() {
  ENCODER_check();
  BUTTON_check();
  mySerial.print("bobobobobobobob");
}

void TIMEMACHINE_311ms() {
  OLED_display();
  
}

