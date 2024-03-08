#include "RotaryEncoderButton.h"

RotaryEncoderButton::RotaryEncoderButton(int clkPin, int dtPin, int swPin)
    : _clkPin(clkPin), _dtPin(dtPin), _swPin(swPin), _position(0), _buttonState(HIGH), _lastButtonState(HIGH), _pressed(false), _released(false) {
    pinMode(_clkPin, INPUT);
    pinMode(_dtPin, INPUT);
    pinMode(_swPin, INPUT_PULLUP);
    _lastClkState = digitalRead(_clkPin);
}

void RotaryEncoderButton::update() {
    int clkState = digitalRead(_clkPin);
    if (clkState != _lastClkState) {
        if (digitalRead(_dtPin) != clkState) {
            _position++;
        } else {
            _position--;
        }
    }
    _lastClkState = clkState;

    bool currentButtonState = !digitalRead(_swPin);
    if (currentButtonState != _lastButtonState) {
        if (currentButtonState) {
            _pressed = true;
        } else {
            _released = true;
        }
    }
    _lastButtonState = currentButtonState;
}

int RotaryEncoderButton::getRotation() {
    int rotation = _position;
    _position = 0; // Pozisyonu sıfırla
    return rotation;
}

bool RotaryEncoderButton::isPressed() {
    if (_pressed) {
        _pressed = false;
        return true;
    }
    return false;
}

bool RotaryEncoderButton::wasPressed() {
    return _buttonState;
}

bool RotaryEncoderButton::wasReleased() {
    if (_released) {
        _released = false;
        return true;
    }
    return false;
}
