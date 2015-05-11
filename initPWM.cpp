#include <iostream>
#include <unistd.h>
#include "BlackPWM.h" //place in the same folder as BlackLib

using namespace std;
using namespace BlackLib;

int main()
{
BlackPWM pwmLed2(EHRPWM2A); // initialization pwm with second led
float percent =0.0;
led1.setValue(high);

pwmLed2.setPeriodTime(5000000); // set period of pwm to 5000000 nanosecond
pwmLed2.setDutyPercent(0.0); // set percentage of pwm to 0 

while(true)
{
sleep(1); // wait 1 second
pwmLed2.setDutyPercent(percent); // set percentage of pwm
percent += 5.0; // increase percent

if (percent>=95)
{
percent=0; //if duty percent grows above 95%, LED goes back to zero brightness
}
}

return 0;
}

/* The file must be run and compiled in sudo environment
Compilation command:
g++ BlackPWM.cpp initPWM.cpp BlackCore.cpp -std=c++0x
*/
