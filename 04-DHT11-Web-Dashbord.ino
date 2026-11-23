#include "config.h"
#include "dht_sensor.h"
#include "oled_display.h"
#include "wifi_manager.h"
#include "async_server.h"


float currenTemp = 0.0;
float currenHum = 0.0;
unsigned long booolMillis = 0;
static unsigned long lastSensorMillis = 0;

void setup() {
    Serial.beging(SERIAL_BAUD);
    delay(1000);
    bootMillis = millis();

    Serial.println();
    Serial.println("=================================================");
    Serial.println("  PROYEK 4 : DHT11 ASYNC WEB DASHBOARD (LITTLEFS)");
    Serial.println("=================================================");

    initOLED();
    showConnectingWifi(WIFI_SSID);

    initDHT();

    initLittleFS();

    bool connected = connectedWIFI();

    if (connected) {
        initAyncWebServer();
    }
     
    readDHT(currenTemp, currenHum);
    drawDashbordOled(currenTemp, currenHum, connected, localIPAddress);
}


    void loop() {
        unsigned long now = millis();

        if (now - lastSensorMillis >= SENSOR_READ_INTERVAL) {
            lastSensorMillis = now;



        if (readDHT(currenTemp, currenHum )) {
            Serial.print("[ASYNC NODE] suhu:");
            Serial.print(currenTemp, 1);
            Serial.print(" c | Hum: ");
            Serial.print(currenHum, 1);
            Serial.print("%");

            drawDashboardOled(currenTemp, currenHum, wifiConnected, localIPAddress);
        }
    }
}

