#include <Arduino.h>
#include "Constants.h"
#include "SerialParser.h"
#include "GimbalController.h"

SerialParser parser; 
GimbalController gimbal; 
GimbalData incomingData {0, 0, false, false}; //monitörden okunan veri nesnesi

unsigned long lastUpdateTick = 0;
const unsigned long updateInterval = 10; //çalışma hızı 10ms yani saniyede 100 kez 100Hz

void setup() {
    Serial.begin(BAUD_RATE); 
    while (!Serial) {
        ;
    }

    while(Serial.available() > 0){
        Serial.read(); 
    }

    gimbal.setup(); 
    
    Serial.println("MCU is Ready...");
}

void loop() {
    if (parser.readPacket(incomingData)) { 
        gimbal.handleNewData(incomingData); 
    }


    unsigned long currentMillis = millis();
    if (currentMillis - lastUpdateTick >= updateInterval) {
        lastUpdateTick = currentMillis;
        
        gimbal.update();
    }
}