#include "SPI.h"
#include <TinyGPSPlus.h>

class GPS
{


    public:
     GPS(int pin1, int pin2)
     {
        SoftwareSerial ass(pin1,pin2,false,256);
     }




    private:
    SoftwareSerial ass(16,17,false,256);
    TinyGPSPlus gps;
    
}