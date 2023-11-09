#include "mbed.h"
#include <iostream>
using namespace std;

DigitalOut greenLED(LED1);
DigitalOut blueLED(LED2);
DigitalOut redLED(LED3);

int main()
{
    //Writing strings in C++
    int x = 1234;

    cout << "Hello ";
    cout << "World:";
    cout << x << endl;

    string str1 = "Hello World: " + to_string(x);
    cout << str1 << endl;

    // String input
    cout << "Type in an integer" << endl;
    cin >> x;
    cout << "You typed: " << x << endl;

    // Convert to C string
    string elec143 = "Welcome to ELEC144"; 
    const char *str = elec143.c_str();
    printf("C string is %s\n", str);

    // Convert C string to C++ string
    char cstr[] = "ELEC144";
    string cppStr = "Welcome to " + string(cstr);
    cout << cppStr << endl;

    // Simple string compare
    string strInput = "      ";
    while (true) {
        cout << "What colour?" << endl;
        cin >> strInput;
        if (strInput == "red") {
            redLED = !redLED;
        }
        else if (strInput == "green") {
            greenLED = !greenLED;
        }
        else if (strInput == "blue") {
            blueLED = !blueLED;
        }
        else if (strInput == "wait"){
                wait_us(1000000);
                redLED = 0;
                greenLED = 0;
                blueLED = 0;
                
            }
        else {
            cout << "Please specify red, green or blue" << endl;
        }
    }
}

