#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Servo.h>
//#include "PID.h"
#include "Accelerometer.h"

MPU mpu;
Servo aileron_l;
Servo aileron_r;
double des_roll = 0;
PID roll_pid(5., 0, 0, 1200, 2000);

void setup()
{
    aileron_l.attach(5);
    aileron_r.attach(4);

    Serial.begin(115200);
    Wire.begin();
    delay(2000);

    if (!mpu.setup())
    {
        while (1)
        {
            Serial.println("MPU connection failed. Please check your connection with `connection_check` example.");
            delay(5000);
        }
    }
    mpu.callibrate();
    
}

void loop()
{
    mpu.update();
    double cur_roll = mpu.get_roll();

    int ailer_err = int(roll_pid.calculate(cur_roll, des_roll));
    aileron_l.writeMicroseconds(1500 - ailer_err);
    aileron_r.writeMicroseconds(1500 - ailer_err);
    Serial.println(mpu.get_roll(), 2);
}
