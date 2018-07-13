#include "M5Stack.h"
#include "WeatherStation.h"

WeatherStationClass ws;
void setup(void)
{
    M5.begin();
   // M5.Lcd.setBrightness(130);
    M5.Lcd.fillScreen(TFT_BLACK);

    WiFi.begin("Master", "NissanTiida16");
    M5.Lcd.print("Connecting to Wifi");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        M5.Lcd.print(".");
    }

    M5.Lcd.println("WiFi connected");
    M5.Lcd.println("IP address: ");
    M5.Lcd.println(WiFi.localIP());
}

void loop()
{
    ws.Run();
}
