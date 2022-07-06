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
    std::vector<double> angles=mpu.get_angles();
    Serial.print("Yaw, Pitch, Roll: ");
    Serial.print(angles[0], 2);
    Serial.print(", ");
    Serial.print(angles[1], 2);
    Serial.print(", ");
    Serial.println(angles[2], 2);
    
}
