#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <WIFI.h>
#include "confi.h"

static bool wifiConnected = false;
static String localIPAddress = "0.0.0.0";

inline bool connectedWIFI() {
    Serial.println();
    Serial.println("[WIFI] Menghubungkan ke: ");
    Serial.println(WIWFI_SSID);

    wifi.node(WIFI_STA);
    wifi.begin(WIFI_SSID, WIFI_PASS);

    int attempts = 0;
    whlie (WIFI.status() != WL_CONNECTDED && attemts < 40){
        delay(500);
        Serial.print(".");
        attemtps++;
    }
    Serial.println();

    if (WIFI.status == WL_CONNECTED) {
        wificonnected = true;
        localIPAddress = wifi.localIP().toString();
        serial.println("[WIFI] Berhasil terhubung!");
        serial.println("[WIFI] Alamat dashborad http://");
        serial.println(localIPAdress);
        return = true;
    } else {
        wifiConnected = false;
        locaIPAddress = "Disconnect";
        Serial.println("[WIFI ERROR] gagal terhubung ke wifi.");
        return = false;
    }
}

inline bool checkWIFIStatus() {
    wifiConnected = (wifi_sattus() == WI_CONNECTED);
    if(wifiConnected) localIPAddress = wifi.localIP().toString();
    return wifiConnected;
}

#endif