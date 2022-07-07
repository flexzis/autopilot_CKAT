#include <Arduino.h>
#include<accel.h>
#include <SoftwareSerial.h>


Accel mpu;

void setup() {
    Serial.begin(115200);
    Wire.begin();
    delay(2000);

    if (!mpu.accel_begin()) {  // cohange to your own address
        while (1) {
            Serial.println("MPU connection failed. Please check your connection with `connection_check` example.");
            delay(5000);
        }
    }

    // calibrate anytime you want to
    mpu.callibration();
}

void loop()
 {
    mpu.get_angles();
    Serial.print("Yaw, Pitch, Roll: ");
    Serial.print(mpu.yaw(), 2);
    Serial.print(", ");
     Serial.print(mpu.pitch(), 2);
    Serial.print(", ");
    Serial.println(mpu.roll(), 2);
    
}
