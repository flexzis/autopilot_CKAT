#include "MPU9250.h"
class Accel
{


    public:
     Accel()
     {
        MPU9250 mpu;
     }

     void callibration()
     {
        mpu.verbose(true);
        mpu.calibrateAccelGyro();
        mpu.calibrateMag();
        mpu.verbose(false);
     }
     
     int accel_begin()
     {
       return(mpu.setup(0x68));
     }

   void get_angles()
     {
        if (mpu.update()) {
        static uint32_t prev_ms = millis();
        if (millis() > prev_ms + 25) 
        {
            Serial.print("Yaw, Pitch, Roll: ");
            Serial.print(mpu.getYaw(), 2);
            Serial.print(", ");
            Serial.print(mpu.getPitch(), 2);
            Serial.print(", ");
            Serial.println(mpu.getRoll(), 2);
            prev_ms = millis();
        }
    }

     }

    double yaw()
    {
        return(mpu.getYaw());
    }


    double pitch()
    {
        return(mpu.getPitch());
    }


    double roll()
    {
        return(mpu.getRoll());
    }

    private:
    MPU9250 mpu;
    
};