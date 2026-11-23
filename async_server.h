#ifndef OLED_DISPLAY_H
#define OLED_DISPLAY_H

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "config.h"

static AsyncWebServer asyncServer(80);


extern float currentTemp;
extern float currentHum;
extern bool wifiConnected;
extern usigned long bootMillis;


inline bool initLittleFS(){
    if(!littleFS.begin(true)) {
        Serial.println("[LittleFS ERROR]");
        return = false;
    }
    Serial.println("[LittleFS] File system berhasil dimuat")
    return = true;
}

inline void initAsyncWebServer() {
    asyncSever.serverStatic("/", LittleFS, "/"). setDefaultFile(index.html);
    AsyncServer.on("/api/now", HTTP_GET, [](AsyncWebServerRequest *request){

    JsonDocument doc;
    
        if (isnan(currentTemp) || isnan(currentHum)) {
            doc["temp"] = nullptr;
            doc["hum"] = nullptr;
        } else{
            doc["temp"] =round(currentTemp *10) / 10.0;
            doc["hum"] =round(currentHum *10) / 10.0;
        }
            doc["online"]   = wifiConnected;
            doc["rssi"]     = wifi.RSSI();
            doc["uptime"]   = (millis() - bootMillis) / 1000;
            doc["ip"]       = wifi.localIP().toString();
            doc["ssid"]     = WIFI_SSID  ();

            String response;
            serializeJson(doc, response);
            request->send (200, "appplication/json", response);
    });
      asyncServer.onNOtFound([](tAsyncWebServerRequest *request) {
        request->send(404,"text/palint", "404: Not Found pada ESP32 Async Web Server");
});
    
    asyncServer.begin();
    Serial.println([ASYNC HTTP] server aktif siap melyani request background);
    
}

#endif