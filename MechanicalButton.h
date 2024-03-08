#ifndef MECHANICALBUTTON_H
#define MECHANICALBUTTON_H

#include "Arduino.h"

class MechanicalButton {
public:
    MechanicalButton(int pin, unsigned long debounceDelay = 50);
    void update();
    bool isPressed();
    bool wasPressed();
    bool wasReleased();
    bool isHeld(unsigned long holdTime = 1000);

private:
    int _pin;
    unsigned long _debounceDelay;
    unsigned long _lastDebounceTime;
    unsigned long _lastPressTime;
    bool _state;
    bool _lastState;
    bool _pressed;
    bool _released;
    bool _holdFlag;
};

#endif
