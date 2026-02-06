
#include "HardwareInterface.h"

HardwareInterface::HardwareInterface() : _panEncoder(&Wire), _tiltEncoder(&Wire1) {} 

bool HardwareInterface::begin() {
    bool success = true; 

    Wire.begin(I2C0_SDA, I2C0_SCL, 400000); 
    
    Wire1.begin(I2C1_SDA, I2C1_SCL, 400000);

    pinMode(LASER_PIN, OUTPUT); 
    digitalWrite(LASER_PIN, LOW); 

    if (!_mpu.begin(0x68, &Wire1)) {
        // Serial.println("MPU6050 bulunamadı");
        // success = false;
    }

    delay(500); 

    _panOffset = _panEncoder.readAngle() * (360.0 / 4096.0); 
    _tiltOffset = _tiltEncoder.readAngle() * (360.0 / 4096.0);

    return success;
}

float HardwareInterface::getPanAngle() {
    float angle = _panEncoder.readAngle() * (360.0 / 4096.0);
    
    if (angle >= 360.0f) angle -= 360.0f;
    if (angle < 0.0f)    angle += 360.0f;

    return angle;
}

float HardwareInterface::getTiltAngle() {
    float angle = _tiltEncoder.readAngle() * (360.0 / 4096.0);
    
    if (angle >= 360.0f) angle -= 360.0f;
    if (angle < 0.0f)    angle += 360.0f;

    return angle;
}

void HardwareInterface::getIMUData(float &ax, float &ay, float &az) {
    sensors_event_t a, g, temp;
    _mpu.getEvent(&a, &g, &temp);
    ax = a.acceleration.x;
    ay = a.acceleration.y;
    az = a.acceleration.z;
}

void HardwareInterface::setLaser(bool enable, bool fire) {
    if (enable && fire) {
        digitalWrite(LASER_PIN, HIGH);
    } else {
        digitalWrite(LASER_PIN, LOW);
    }
}