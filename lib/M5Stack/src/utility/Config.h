#ifndef _CONFIG_H_
#define _CONFIG_H_

#define ILI9341_DRIVER
//#define ST7735_DRIVER
//#define ILI9163_DRIVER
//#define S6D02A1_DRIVER
//#define RPI_ILI9486_DRIVER // 20MHz maximum SPI
#include "ILI9341_Defines.h"
#define  TFT_DRIVER 0x9341

// Screen
// #define SPI_FREQUENCY   1000000
// #define SPI_FREQUENCY   5000000
// #define SPI_FREQUENCY  10000000
// #define SPI_FREQUENCY  20000000
// #define SPI_FREQUENCY  27000000 // Actually sets it to 26.67MHz = 80/3
#define SPI_FREQUENCY 40000000 // Maximum to use SPIFFS
// #define SPI_FREQUENCY  80000000

#define LOAD_GLCD  // Font 1. Original Adafruit 8 pixel font needs ~1820 bytes in FLASH
#define LOAD_FONT2 // Font 2. Small 16 pixel high font, needs ~3534 bytes in FLASH, 96 characters
#define LOAD_FONT4 // Font 4. Medium 26 pixel high font, needs ~5848 bytes in FLASH, 96 characters
#define LOAD_FONT6 // Font 6. Large 48 pixel font, needs ~2666 bytes in FLASH, only characters 1234567890:-.apm
#define LOAD_FONT7 // Font 7. 7 segment 48 pixel font, needs ~2438 bytes in FLASH, only characters 1234567890:.
#define LOAD_FONT8 // Font 8. Large 75 pixel font needs ~3256 bytes in FLASH, only characters 1234567890:-.
//#define LOAD_FONT8N // Font 8. Alternative to Font 8 above, slightly narrower, so 3 digits fit a 160 pixel TFT
#define LOAD_GFXFF // FreeFonts. Include access to the 48 Adafruit_GFX free fonts FF1 to FF48 and custom fonts

#define BTN_A 0
#define BTN_B 1
#define BTN_C 2
#define BUTTON_A 0
#define BUTTON_B 1
#define BUTTON_C 2

// BEEP PIN
#define SPEAKER_PIN 25
#define TONE_PIN_CHANNEL 0

#ifdef M5STACK
#define TFT_MISO 19
#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_CS 14  // Chip select control pin
#define TFT_DC 27  // Data Command control pin
#define TFT_RST 33 // Reset pin (could connect to Arduino RESET pin)
#define TFT_BL 32  // LED back-light

// SD card
#define TFCARD_CS_PIN 4

// Buttons
#define BUTTON_A_PIN 39
#define BUTTON_B_PIN 38
#define BUTTON_C_PIN 37

#else

#define TFT_MISO 25
#define TFT_MOSI 23
#define TFT_SCLK 19
#define TFT_CS 22  // Chip select control pin
#define TFT_DC 21  // Data Command control pin
#define TFT_RST 18 // Reset pin (could connect to Arduino RESET pin)
#define TFT_BL 5  // LED back-light

#define BUTTON_A_PIN 32
#define BUTTON_B_PIN 27
#define BUTTON_C_PIN 33

#endif

// UART
#define USE_SERIAL Serial

#endif /* SETTINGS_C */
