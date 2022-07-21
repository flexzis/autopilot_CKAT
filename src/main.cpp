#include <TinyGPSPlus.h>
#include<vector>
#include <HardwareSerial.h>

double target_coordinates[3]={55.614714, 38.103408, 137};


HardwareSerial SerialGPS(2);
TinyGPSPlus gps;

void setup() {
  Serial.begin(115200);
  SerialGPS.begin(9600, SERIAL_8N1, 16, 17);


}

void loop() 
{
  while (SerialGPS.available() > 0) 
  {
    gps.encode(SerialGPS.read());

  }
    Serial.println(String(gps.location.lat(),6) + " " + String(gps.location.lng(), 6)+" "+String(gps.altitude.meters(), 1));    
    double our_x=double(gps.location.lat());
    double our_y=double(gps.location.lng());
    double our_z=gps.altitude.meters();
    double our_coordinates[3]={our_x,our_y,our_z };
    double x=target_coordinates[0]-our_coordinates[0];
    double y=target_coordinates[1]-our_coordinates[1];
    double z=target_coordinates[2]-our_coordinates[2];
    double vector_to_target[3]={x,y ,z };
 // Serial.println(String(vector_to_target[0],6) + " " + String(vector_to_target[1],6)+" "+String(vector_to_target[2],1));
  
delay(500);
}