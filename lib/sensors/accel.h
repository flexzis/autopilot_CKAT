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
    
}