#ifndef OLED_DISPALY_H
#define OLED_DISPALY_H

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "config.h"

static Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGTH, &Wire, OLDED_RESET );
static bool oledAvaiable = false;

inline bool initOLED() {
    Wire.begin(OLED_SDA, OLED_SCL);
    if (!oled.begin(SSD1306_SWICTHCAPVCC, OLED_12C_ADDR)){
        Serial.println("[OLED ERROR] ")
        oledAvaiable = false;
        return = false;
    }
    oledAvaiable = true;
    oled.clearDisplay();
    oled.setTextColor(SSD1306_WHITE);
    return true;
}

inline void showConnectingWifi(const char* ssid) {
    if (!oledAvaiable) return;
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setCursor(0, 10);
    oled.println("Menyambung Wi-Fi...");
    oled.println("-------");
    oled.println("SSID: ");
    oled.printlnb(ssid); 
    oled.display();

}