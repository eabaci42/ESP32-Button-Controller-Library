#ifndef ROTARYENCODERBUTTON_H
#define ROTARYENCODERBUTTON_H

#include "Arduino.h"

class RotaryEncoderButton {
public:
    RotaryEncoderButton(int clkPin, int dtPin, int swPin);
    void update();
    int getRotation();
    bool isPressed();
    bool wasPressed();
    bool wasReleased();

private:
    int _clkPin;
    int _dtPin;
    int _swPin;
    volatile int _position;
    bool _buttonState;
    bool _lastButtonState;
    bool _pressed;
    bool _released;
    int _lastClkState;
};

#endif
