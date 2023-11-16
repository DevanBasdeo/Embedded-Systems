#include "uop_msb.h"
using namespace uop_msb;

//Declare Functions
static int getDelayMS();
int getAverageDelay(double alpha);

//Devices
static AnalogIn pot(AN_POT_PIN);

static int getDelayMS()
{
    float p = pot;
    int delay = 100 + 900*p;
    return delay;
}

//Calculate average delay by filtering the potentiometer value
int getAverageDelay(double alpha)
{
    static double meanPotValue = (double)getDelayMS();

    for (unsigned int n=0; n<32; n++) {
        int potValue = getDelayMS();
        meanPotValue = alpha*meanPotValue + (1.0-alpha)*potValue;
    }
    return(meanPotValue);

}