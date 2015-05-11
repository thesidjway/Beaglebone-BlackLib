#include <iostream>
#include <unistd.h>
#include "BlackGPIO.h" //place this cpp in same folder as BlackLib

using namespace std;
using namespace BlackLib; //part of BlackLib

int main()
{
BlackGPIO led1(GPIO_68,output); //set this pin as output. Check BlackLib user manual pdf for more details
led1.setValue(high); 
while(true){
// give some time to Beaglebone Black
sleep(1); // wait 1 second
led1.toggleValue(); // toogle led1
}
return 0;
}

/* Code must be run in sudo environment else the led won't toggle. The compilation command is:
g++ BlackGPIO.cpp sidGPIO.cpp BlackCore.cpp -std=c++0x
*/
