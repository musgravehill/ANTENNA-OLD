
//============================================   3.3V ONLY ===================================================================================================================
//============================================   3.3V ONLY ===================================================================================================================
//============================================   3.3V ONLY ===================================================================================================================
//============================================   3.3V ONLY ===================================================================================================================

// ADF4351 PLL-Synthesizer 33Mhz - 4,4Ghz
// Integer mode Demo OE6OCG 1/2015
// up/down = Freq +- with stepsize
// left = frequency step's from 6.25khz to 1Mhz
/*
         ============================================   3.3V ONLY ===================================================================================================================
         ============================================   3.3V ONLY ===================================================================================================================
         ============================================   3.3V ONLY ===================================================================================================================
         ============================================   3.3V ONLY ===================================================================================================================
         ============================================   3.3V ONLY ===================================================================================================================
         ============================================   3.3V ONLY ===================================================================================================================
   MOSI 11 ----> DATA
   MISO 12 ---- null, but d12 is SPI
   SCK 13 -----> CLK
   d3----------> LE

    TODO
   int LoNoisSpur = 1; //Low Spurious Mode
    int D_out_PWR = 11; //POut +5db

    ENCODER add
    if Freq>4.4GHz stop ++
    if Freq < 35Mhz stop --

*/

//============================================================= ADF4351 =========================================
#include <SPI.h>
#define ADF4351_ss_pin 3 //SPI-SS enable ADF4351
long ADF4351_frequency = 44220000; // *10 Hz
long ADF4351_referenceFreq = 2500000; //*10 Hz reference frequency = quartz 25 MHz
long ADF4351_freqStepCurrent = 625; //*10 Hz step 6.25 Khz
long ADF4351_stepsVariants[5]; //step`s variants
int ADF4351_stepsVariantsNumCurrent = 0;
unsigned long ADF4351_registers[6]; //ADF4351 Registers, see datasheet

byte tenHz, hundredHz, ones, tens, hundreds, thousands, tenthousands, hundredthousands, millions;

//========================================== INTERFACE ==========================================================
#define BUTTON_udo_push 6 //PD6

//OLED SDA A4, SCL A5
#include <OLED_I2C.h>
OLED  myOLED(SDA, SCL);
extern uint8_t SmallFont[]; //6*8
extern uint8_t MediumNumbers[]; //12*16
extern uint8_t BigNumbers[]; //14*24

//================================== TIMEMACHINE =================================================================
uint32_t TIMEMACHINE_prev_211ms = 0L;


void setup() {
  pinMode (ADF4351_ss_pin, OUTPUT);
  digitalWrite(ADF4351_ss_pin, LOW);
  SPI.setDataMode(SPI_MODE0);
  SPI.setBitOrder(MSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV128);
  SPI.begin();
  delay(500);

  ADF4351_stepsVariants[0] = 625; //*10 Hz 6,25 khz, 5khz does not work in Int-N mode (MOD> 4095) at 25Mhz Ref.
  ADF4351_stepsVariants[1] = 1000; //*10 Hz 10 khz
  ADF4351_stepsVariants[2] = 1250; //*10 Hz 12.5 khz
  ADF4351_stepsVariants[3] = 2500; //*10 Hz 25 khz
  ADF4351_stepsVariants[4] = 100000; //*10 Hz 1 Mhz ADF4351_stepsVariants

  ADF4351_setFreq(ADF4351_frequency);
}

void loop() {

  TIMEMACHINE_loop();

  //case btnLEFT:
  ADF4351_stepsVariantsNumCurrent += 1;
  if (ADF4351_stepsVariantsNumCurrent > 4) ADF4351_stepsVariantsNumCurrent = 0;
  ADF4351_freqStepCurrent = ADF4351_stepsVariants[ADF4351_stepsVariantsNumCurrent];


  // case btnUP:
  ADF4351_frequency += ADF4351_freqStepCurrent;
  ADF4351_setFreq(ADF4351_frequency);


  //case btnDOWN:
  ADF4351_frequency -= ADF4351_freqStepCurrent;
  ADF4351_setFreq(ADF4351_frequency);

}




