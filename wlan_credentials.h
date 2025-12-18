// wlan_credentials.h
// WLAN_SSID, Name de WLAN routers
#define WIFI_SSID "NAME_WLAN"

// WLAN Passwort
#define WIFI_PASS "PASSWORT_WLAN"

// MYHOST: Name, unter dem dein ESP32 im WLAN zu finden ist
#define MYHOST "esp32_deinname"

// Optionally override credentials in wlan_credentials_private.h (not tracked in
// git)
#ifdef __has_include
#if __has_include("wlan_credentials_private.h")
#include "wlan_credentials_private.h"
#endif
#endif
