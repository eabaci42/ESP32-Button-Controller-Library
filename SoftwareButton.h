#ifndef SOFTWAREBUTTON_H
#define SOFTWAREBUTTON_H

#include "Arduino.h"

class SoftwareButton {
public:
    SoftwareButton();
    void trigger();
    void update();
    bool isPressed();
    bool wasPressed();
    bool wasReleased();

private:
    bool _pressedState;
    bool _lastPressedState;
    bool _triggered;
    bool _released;
};

#endif
