#include "WirelessButton.h"

WirelessButton::WirelessButton() : _server(80), _pressed(false), _released(false) {
}

void WirelessButton::begin(const char* ssid, const char* password) {
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }
    _server.begin();
}

void WirelessButton::checkForCommands() {
    WiFiClient client = _server.available();
    if (client) {
        while (client.connected()) {
            if (client.available()) {
                String currentLine = client.readStringUntil('\r');
                if (currentLine.length() > 0) {
                    _lastCommand = currentLine;
                    _pressed = true;
                    // Response to client
                    client.println("HTTP/1.1 200 OK");
                    client.println("Content-type:text/html");
                    client.println();
                    client.println("<!DOCTYPE HTML><html><body>");
                    client.println("<h1>Button Pressed!</h1>");
                    client.println("</body></html>");
                    client.stop();
                }
            }
        }
    }
}

bool WirelessButton::isPressed(const String& command) {
    if (_pressed && _lastCommand == command) {
        _pressed = false;
        return true;
    }
    return false;
}

bool WirelessButton::wasPressed() {
    return _pressed;
}

bool WirelessButton::wasReleased() {
    if (_released) {
        _released = false;
        return true;
    }
    return false;
}
