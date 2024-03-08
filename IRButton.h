#ifndef IRBUTTON_H
#define IRBUTTON_H

#include "Arduino.h"
#include <IRremote.h>

class IRButton {
public:
    IRButton(int recvPin);
    void update();
    bool isPressed(unsigned long code);
    bool wasPressed();
    bool wasReleased();

private:
    int _recvPin;
    IRrecv _irrecv;
    decode_results _results;
    unsigned long _lastCode;
    bool _pressed;
    bool _released;
};

#endif
