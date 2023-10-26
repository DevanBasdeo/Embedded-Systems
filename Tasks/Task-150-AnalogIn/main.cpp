#include "uop_msb.h"
#include <chrono>
#include <cstdint>
using namespace uop_msb;
using namespace chrono;

//Fun output stuff
LCD_16X2_DISPLAY disp;
Buzzer buzz;
LatchedLED ledDisp(LatchedLED::STRIP);

//Analogue Inputs
AnalogIn pot(AN_POT_PIN);
AnalogIn ldr(AN_LDR_PIN);
AnalogIn mic(MIC_AN_PIN);

//LED Lights
DigitalOut greenLED(PC_6);
DigitalOut redLED(PC_2);
DigitalOut yellowLED(PC_3);

int main()
{

    //Test LED Bar Display
    ledDisp.enable(true);

    ledDisp.setGroup(LatchedLED::LEDGROUP::RED);
    for (unsigned int n=0; n<8; n++) {
        ledDisp = 1 << n;
        wait_us(250000);
    }
    ledDisp = 0;

    ledDisp.setGroup(LatchedLED::LEDGROUP::GREEN);
    for (unsigned int n=0; n<8; n++) {
        ledDisp = 1 << n;
        wait_us(250000);
    }
    ledDisp = 0;
    
    ledDisp.setGroup(LatchedLED::LEDGROUP::BLUE);
    for (unsigned int n=0; n<8; n++) {
        ledDisp = 1 << n;
        wait_us(250000);
    }     
    ledDisp = 0;


    while (true) {
        //Read Analog to Digital Converter values (16 bit)
        unsigned short potVal   = pot.read_u16();
        unsigned short lightVal = ldr.read_u16();
        unsigned short micVal   = mic.read_u16(); 

        //Write to terminal
        printf("--------------------------------\n");
        printf("Potentiometer: %X\n", potVal);
        printf("Light Dependant Resistor: %X\n", lightVal);
        printf("Microphone: %X\n", micVal);   

        //Wait 0.25 seconds
        wait_us(500000);

        //Turning on Lights for each Condition
        if(potVal > 33000){
            ledDisp.setGroup(LatchedLED::LEDGROUP::RED);
            ledDisp = 255;       
        } else {
            ledDisp.setGroup(LatchedLED::LEDGROUP::RED);
            ledDisp = 0;
        }


        if(lightVal < 1500){
            ledDisp.setGroup(LatchedLED::LEDGROUP::GREEN);
            ledDisp = 255;
        } else {
            ledDisp.setGroup(LatchedLED::LEDGROUP::GREEN);
            ledDisp = 0;
        }

        if(micVal > 40000){
            ledDisp.setGroup(LatchedLED::LEDGROUP::BLUE);
            ledDisp = 255;
        } else {
            ledDisp.setGroup(LatchedLED::LEDGROUP::BLUE);
            ledDisp = 0;
        }


    }


}

