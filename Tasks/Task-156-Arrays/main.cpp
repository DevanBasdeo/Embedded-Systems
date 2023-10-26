#include "uop_msb.h"
#include <chrono>
#include <cstdint>
using namespace uop_msb;
using namespace chrono;

//Output
DigitalOut redLED(TRAF_RED1_PIN);
DigitalOut yellowLED(TRAF_YEL1_PIN);
DigitalOut greenLED(TRAF_GRN1_PIN);

//Analogue Inputs
AnalogIn ldr(AN_LDR_PIN);
Buzzer buzz;


int main()
{
    unsigned short samples[100];

    for (unsigned int m=0; m<100; m++) {
        printf("%X\n ", samples[m]);
    }

    // Automatic headlamp 
    while (true) {

        for (unsigned int m=0; m<100; m++) {
            unsigned short ldrVal   = ldr.read_u16();
            samples[m] = ldrVal;
            wait_us(100000);          // 100ms

            int average;
            average = samples[m]/100;
            printf("The average value in the samples is %d\n", average);
            wait_us(100000);

            printf("The mean to 1dp is %d\n", average);
            wait_us(100000);

            if(average > 100){
                greenLED = 1;
            }else greenLED =0;
        }

        // TASK a. Calculate the average value in samples

        // TASK b. Display to 1dp

        // TASK c. Switch green LED on when dark;

    }  
}


