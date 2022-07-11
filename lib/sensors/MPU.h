#include "MPU9250.h"

class MPU
{
public:
    MPU()
    : update_time{millis()}
    {}

    inline bool setup()
    {
        return mpu.setup(0x68);
    }

    inline void callibrate()
    {
        mpu.verbose(true);
        mpu.calibrateAccelGyro();
        // mpu.calibrateMag();
        mpu.verbose(false);
    }

    inline void update()
    {
        if (millis() > update_time + pause_between_update)
        {
            mpu.update();
            update_time = millis();
        }
    }

    inline double get_pitch() const
    {
        return mpu.getPitch();
    }

    inline double get_yaw() const
    {
        return mpu.getYaw();
    }

    inline double get_roll() const
    {
        return mpu.getRoll();
    }

private:
    static constexpr uint32_t pause_between_update = 10;
    uint32_t update_time;
    MPU9250 mpu;
};