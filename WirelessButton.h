#ifndef WIRELESSBUTTON_H
#define WIRELESSBUTTON_H

#include "Arduino.h"
#include <WiFi.h>

class WirelessButton {
public:
    WirelessButton();
    void begin(const char* ssid, const char* password);
    void checkForCommands();
    bool isPressed(const String& command);
    bool wasPressed();
    bool wasReleased();

private:
    WiFiServer _server;
    String _lastCommand;
    bool _pressed;
    bool _released;
};

#endif
