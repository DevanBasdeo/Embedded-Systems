#include "uop_msb.h"
using namespace uop_msb;

BusIn bus(PG_0, PG_1, PG_2, PG_3);

DigitalOut redLED(TRAF_RED1_PIN);       //Red Traffic 1
DigitalOut yellowLED(TRAF_YEL1_PIN);    //Yellow Traffic 1
DigitalOut greenLED(TRAF_GRN1_PIN);     //Green Traffic 1

//Dual Digit 7-segment Display
LatchedLED disp(LatchedLED::SEVEN_SEG);

int main()
{
    int count = 0;

    // bus[2].mode(PinMode::PullDown);
    bus[2].mode(PinMode::PullDown);
    // bus[3].mode(PinMode::PullDown);
    bus[3].mode(PinMode::PullDown);
    

    //Turn ON the 7-segment display
    disp.enable(true);

    //Update display
    disp = count;

    while (true) {
        
        //Read button without blocking
        
        

        //Test Button A
        if (bus[0] == 1) {
            redLED = !redLED;    //Toggle RED led
            count = count + 1;
            disp = count;       //Update display           
            
        }

        else if(bus[1] == 1) {
            redLED = !redLED;
            count = count - 1;
            disp = count;       //Update display
        
        }
   

        // Slow it down a bit (and debounce the switches)
        wait_us(100000);  
    }
}


