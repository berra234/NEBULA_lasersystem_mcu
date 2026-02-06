#ifndef HARDWARE_INTERFACE_H
#define HARDWARE_INTERFACE_H

#include <Arduino.h>
#include <Wire.h> 
#include <Adafruit_MPU6050.h> 
#include <AS5600.h> 
#include "Constants.h" 

class HardwareInterface {
public:
    HardwareInterface(); 
    bool begin();
    
    float getPanAngle(); //yatay eksen encoder
    float getTiltAngle(); //dikey eksen encoder
    void getIMUData(float &ax, float &ay, float &az); 
    

    void setLaser(bool enable, bool fire); 

private:
    AS5600 _panEncoder;    
    AS5600 _tiltEncoder;   
    Adafruit_MPU6050 _mpu;

    float _panOffset = 0.0f; 
    float _tiltOffset = 0.0f;
};

#endif