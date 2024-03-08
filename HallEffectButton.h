#ifndef HALLEFFECTBUTTON_H
#define HALLEFFECTBUTTON_H

#include "Arduino.h"

class HallEffectButton {
public:
    HallEffectButton(int threshold = 50);
    void update();
    bool isTriggered();
    bool wasTriggered();
    bool wasReleased();

private:
    int _threshold;
    bool _triggerState;
    bool _lastTriggerState;
    bool _triggered;
    bool _released;
};

#endif
