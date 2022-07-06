#include "MPU9250.h"
#include<vector>
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

    std::vector<double> get_angles()
     {
        std::vector<double> angles;
        if (mpu.update()) {
        static uint32_t prev_ms = millis();
        if (millis() > prev_ms + 25) {
        angles.push_back(mpu.getYaw());
           angles.push_back(mpu.getPitch());
           angles.push_back(mpu.getRoll());
            prev_ms = millis();
            return(angles);
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