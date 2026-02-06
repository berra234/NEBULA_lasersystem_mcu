#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <Arduino.h>

#define PAN_STEP_PIN 1 
#define PAN_DIR_PIN 2
#define TILT_STEP_PIN 4 
#define TILT_DIR_PIN 5
#define MOTOR_ENABLE_PIN 6
#define LASER_PIN 7

#define I2C0_SDA 8 
#define I2C0_SCL 9
#define I2C1_SDA 10
#define I2C1_SCL 11

const float MICROSTEP = 32.0f; //microstep ayarı 
const float REDUCTION_RATIO = 1.0f; //redüktör oranı
const float STEPS_PER_REV = 200.0f;
const float STEPS_PER_DEGREE = (STEPS_PER_REV * MICROSTEP * REDUCTION_RATIO) / 360.0f;

const float MIN_ANGLE = -180.0f; //açı sınırları
const float MAX_ANGLE = 180.0f;

const uint8_t HEADER1 = 0xAA; //ROS2 kodlarından gelecek serial mesajının içeriğindeki header'lar
const uint8_t HEADER2 = 0xFF;
const long BAUD_RATE = 921600;

const float DEAD_ZONE = 0.1f;

const float MAX_ANGULAR_VELOCITY = 100.0f;

struct PIDConfig {
    float kp = 2.0f;
    float ki = 0.05f;
    float kd = 0.15f;
};

#endif