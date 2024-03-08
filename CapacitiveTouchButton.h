#ifndef CAPACITIVETOUCHBUTTON_H
#define CAPACITIVETOUCHBUTTON_H

#include "Arduino.h"

class CapacitiveTouchButton {
public:
    CapacitiveTouchButton(uint8_t touchPin, uint16_t sensitivity = 40);
    void update();
    bool isTouched();
    bool wasTouched();
    bool wasReleased();

private:
    uint8_t _touchPin;
    uint16_t _sensitivity;
    bool _touchState;
    bool _lastTouchState;
    bool _touched;
    bool _released;
};

#endif
