#ifndef _M5STACK_H_
#define _M5STACK_H_

#if defined(ESP32)

// #define MPU9250_INSDE
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include "FS.h"
#include "SD.h"
#include "SD_MMC.h"
#include "WiFi.h"
#include "M5Display.h"
#include "utility/Config.h"
#include "utility/Button.h"
#ifdef M5STACK
#include "utility/Speaker.h"
#endif

#ifdef MPU9250_INSDE
#include "utility/MPU9250.h"
#include "utility/quaternionFilters.h"
#endif


class M5Stack {

 public:
    void begin(bool LCDEnable=true, bool SDEnable=true);
    void update();

    void setWakeupButton(uint8_t button);
    void powerOFF();

    // Button API
    #define DEBOUNCE_MS 5
    Button BtnA = Button(BUTTON_A_PIN, true, DEBOUNCE_MS);
    Button BtnB = Button(BUTTON_B_PIN, true, DEBOUNCE_MS);
    Button BtnC = Button(BUTTON_C_PIN, true, DEBOUNCE_MS);

    // SPEAKER
    #ifdef M5STACK
    SPEAKER Speaker;
    #endif

    // LCD
    M5Display Lcd = M5Display();

    // UART
    // HardwareSerial Serial0 = HardwareSerial(0);
    // HardwareSerial Serial2 = HardwareSerial(2);

    // MPU9250
#ifdef MPU9250_INSDE
    MPU9250 IMU = MPU9250();
#endif

 private:
    uint8_t _wakeupPin;
};

extern M5Stack M5;
#define m5 M5
#define lcd Lcd

#else
#error “This library only supports boards with ESP32 processor.”
#endif

#endif

