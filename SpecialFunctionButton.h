#ifndef SPECIALFUNCTIONBUTTON_H
#define SPECIALFUNCTIONBUTTON_H

#include "Arduino.h"

class SpecialFunctionButton {
public:
    SpecialFunctionButton();
    void update();
    bool isTriggered();
    bool wasTriggered();
    bool wasReleased();

private:
    bool _triggerState;
    bool _lastTriggerState;
    bool _triggered;
    bool _released;
};

#endif
