#include "mbed.h"

// main() runs in its own thread in the OS

DigitalOut leds(PC_2, PC_3, PC_6);

//Initialise Variables
int pattern, count, delay;

int main()
do {
    
    printf("\n\nEnter a Value between 0 and 7\n\n");
    pattern = scanf("%d", pattern);

    printf("Please Enter a Value for Count\n");
    count = scanf("%d", count);

    printf("Enter a Value for the Delay, this must be between 50 and 2000\n");
    delay = scanf("%d", delay);
    
} while ((pattern > 0) || (pattern < 7) || (count > 5) || (count < 20) || (delay > 50) || (delay < 2000));

leds = 1

