
#include <Arduino.h>
#include "SPI.h"
#include <SoftwareSerial.h>
#include <TinyGPSPlus.h>

class GPS
{
    public:
     GPS()
     {
        SoftwareSerial ass(16,17,false,256);//16,17, false, 256
        TinyGPSPlus gps;
     }

     void begin()
     {
         ass.begin(115200);
           while  (!gps.altitude.isUpdated())
            {
                while (ass.available() > 0)
                {
                    gps.encode(ass.read());
                }
             } 
         
     }
     
     void earn_data_from_sat()
     {
        while (ass.available() > 0)
        {
            gps.encode(ass.read());
        }
     }


     double coord_X()
     {
        return(double(gps.location.lat())*63995);
     }

     double coord_y()
     {
        return(double(gps.location.lng())*111370);
     }

     double coord_z()
     {
        return(double(gps.location.lat()));
     }

    private:
    SoftwareSerial ass;
    TinyGPSPlus gps;   
};
