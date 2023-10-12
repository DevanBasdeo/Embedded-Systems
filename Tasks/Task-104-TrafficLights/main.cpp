#include "uop_msb.h"
#include <type_traits>
using namespace uop_msb;

#define WAIT_TIME_MS 500 

DigitalOut red(TRAF_RED1_PIN,1);         //Note the initial state
DigitalOut amber(TRAF_YEL1_PIN,0);
DigitalOut green(TRAF_GRN1_PIN,0);

//Object for controlling the LCD
LCD_16X2_DISPLAY lcd;

while (true);
    {
        red = 1;
    lcd.puts("RED");
    wait_us(10000000); //10 seconds
    
    amber = 1;
    lcd.cls();
    lcd.puts("Amber");
    wait_us(2000000); //2 seconds
    
    red = 0;
    amber = 0;
    green = 1;
    lcd.cls();
    lcd.puts("Green");    
    wait_us(10000000); //10 seconds
    
    red = 0;
    green = 0;
    amber = 1;
    lcd.cls();
    lcd.puts("Amber");
    wait_us(2000000); //2 seconds
    }
