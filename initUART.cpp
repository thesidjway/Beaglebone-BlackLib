#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sstream>
#include <string>
#include <iostream>

#include "BlackUART.h" //Place in the same folder as the BlackLib

using namespace std;
using namespace BlackLib;

int main(){
   std::string writeToUart1;
    std::string readFromUart1;
    int counter;
    std::ostringstream os1;

    BlackLib::BlackUART  Uart1(BlackLib::UART1,
                               BlackLib::Baud9600,
                               BlackLib::ParityEven,
                               BlackLib::StopOne,
                               BlackLib::Char8 );
    // Pins on BeagleBone Black REV C
    // UART1_RX -> GPIO_15 (P9.24)
    // UART1_RX -> GPIO_14 (P9.26)
    
    std::cout << "Program UART start" << std::endl << std::flush;

    Uart1.open( BlackLib::ReadWrite | BlackLib::NonBlock );

    string string1="chadarmod";
    while (true){

        os1.str("");
        os1.clear();
        os1 << "Uart: " << string1 << "\n";
        writeToUart1 = os1.str();
        Uart1 << writeToUart1;

        readFromUart1 = "";
        Uart1 >> readFromUart1;
        if (readFromUart1.compare("") != 0)
        {
            std::cout << "Uart1 from RX: " << readFromUart1 << "\n" << std::flush;
        }
        Uart1.flush( BlackLib::bothDirection );
        sleep(2);

 }

    return 1;
}
/* For compilation instructions follow the PWM and GPIO files*/
