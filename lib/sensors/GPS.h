
#include <Arduino.h>
#include <HardwareSerial.h>
#include <TinyGPSPlus.h>

class GPS
{
    public:
     GPS():SerialGPS(2),gps()
     {}

    void GPS_setup() 
    {
      SerialGPS.begin(9600, SERIAL_8N1, 16, 17);
    }

     
     void earn_data_from_sat()
     {
      while (SerialGPS.available() > 0) 
            {
               gps.encode(SerialGPS.read());
            }
     }


     double coord_x_in_grad()
     {
        return(double(gps.location.lat()));
     }

     double coord_y_in_grad()
     {
        return(double(gps.location.lng()));
     }

     double coord_z()
     {
        return(double(gps.location.lat()));
     }

    private:
    HardwareSerial SerialGPS;
    TinyGPSPlus gps;   
};
