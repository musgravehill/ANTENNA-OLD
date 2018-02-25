
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
uint32_t ADF4351_referenceFreq = 2500000; //*10 Hz reference frequency = quartz 25 MHz
uint32_t ADF4351_frequency;
uint32_t ADF4351_freqStepCurrent;
uint32_t ADF4351_stepsVariants[7] = {
  625, //*10Hz 6,25 khz, 5khz does not work in Int-N mode (MOD> 4095) at 25Mhz Ref.
  1000, //*10Hz 10 khz
  1250, //*10Hz 12.5 khz
  2500, //*10Hz 25 khz
  100000, //*10Hz 1 Mhz
  1000000, //*10Hz 10 Mhz
  10000000 //*10Hz 100 Mhz
};
String OLED_stepsVariants_val[7] = {"6.25", "10", "12.5", "25", "1", "10", "100"};
String OLED_stepsVariants_kmhz[7] = {"kHz", "kHz", "kHz", "kHz", "MHz", "MHz", "MHz"};

int ADF4351_stepsVariantsNumCurrent = 0;
unsigned long ADF4351_registers[6]; //ADF4351 Registers, see datasheet

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
uint32_t TIMEMACHINE_prev_1103ms = 0L;


void setup() {
  ADF4351_init();
  OLED_init();

  Serial.begin(9600);
}

void loop() {

  TIMEMACHINE_loop();

  /*
    //case btnLEFT:
    ADF4351_stepsVariantsNumCurrent += 1;
    if (ADF4351_stepsVariantsNumCurrent > 6) ADF4351_stepsVariantsNumCurrent = 0;
     ADF4351_frequency += ADF4351_stepsVariants[ADF4351_stepsVariantsNumCurrent];


    // case btnUP:

    ADF4351_setFreq(ADF4351_frequency);


    //case btnDOWN:
    ADF4351_frequency -= ADF4351_stepsVariants[ADF4351_stepsVariantsNumCurrent];
    ADF4351_setFreq(ADF4351_frequency);
  */
}




