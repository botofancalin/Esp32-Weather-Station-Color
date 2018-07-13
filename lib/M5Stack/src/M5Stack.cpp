// Copyright (c) M5Stack. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include "M5Stack.h"

void M5Stack::begin(bool LCDEnable, bool SDEnable)
{

    // UART
    Serial.begin(115200);
    Serial.flush();
    Serial.print("M5Stack initializing...");

#ifdef M5STACK
    // I2C Startup BUG?
    pinMode(SCL, OUTPUT);
    digitalWrite(SCL, 1);
#endif

    // Setup the button with an internal pull-up
    pinMode(BUTTON_A_PIN, INPUT_PULLUP);
    pinMode(BUTTON_B_PIN, INPUT_PULLUP);
    pinMode(BUTTON_C_PIN, INPUT_PULLUP);

    // M5 LCD INIT
    if (LCDEnable)
        Lcd.begin();

// TF Card
#ifdef M5STACK
    if (SDEnable)
        SD.begin(TFCARD_CS_PIN, SPI, 40000000);
#else
    SD_MMC.begin();
    Lcd.setRotation(3);
#endif

    // Set wakeup button
    setWakeupButton(BUTTON_A_PIN);

// MPU9250
#ifdef MPU9250_INSDE
    Wire.begin();
#endif

    Serial.println("OK");
}

void M5Stack::update()
{
    //Button update
    BtnA.read();
    BtnB.read();
    BtnC.read();
}

void M5Stack::setWakeupButton(uint8_t button)
{
    _wakeupPin = button;
}

void M5Stack::powerOFF()
{
    // power off the Lcd
    Lcd.setBrightness(0);
    Lcd.sleep();

    // ESP32 into deep sleep
    USE_SERIAL.printf("Enabling EXT0 wakeup on pins GPIO%d\n", _wakeupPin);
    esp_sleep_enable_ext0_wakeup((gpio_num_t)_wakeupPin, LOW);

    while (digitalRead(_wakeupPin) == LOW)
    {
        delay(10);
    }
    USE_SERIAL.println("On deep sleep mode.");
    esp_deep_sleep_start();
    USE_SERIAL.println("On power OFF fail!");
}

M5Stack M5;
