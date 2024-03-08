#include "MechanicalButton.h"

MechanicalButton::MechanicalButton(int pin, unsigned long debounceDelay) {
    _pin = pin;
    _debounceDelay = debounceDelay;
    _state = HIGH;
    _lastState = HIGH;
    _pressed = false;
    _released = false;
    _holdFlag = false;
    _lastDebounceTime = 0;
    _lastPressTime = 0;
    pinMode(_pin, INPUT_PULLUP);
}

void MechanicalButton::update() {
    bool reading = digitalRead(_pin);
    if (reading != _lastState) {
        _lastDebounceTime = millis();
    }
    if ((millis() - _lastDebounceTime) > _debounceDelay) {
        if (reading != _state) {
            _state = reading;
            if (_state == LOW) {
                _pressed = true;
                _lastPressTime = millis();
            } else {
                _released = true;
                _holdFlag = false;
            }
        }
    }
    _lastState = reading;
}

bool MechanicalButton::isPressed() {
    if (_pressed) {
        _pressed = false;
        return true;
    }
    return false;
}

bool MechanicalButton::wasPressed() {
    return _state == LOW;
}

bool MechanicalButton::wasReleased() {
    if (_released) {
        _released = false;
        return true;
    }
    return false;
}

bool MechanicalButton::isHeld(unsigned long holdTime) {
    if (_state == LOW && !_holdFlag && (millis() - _lastPressTime >= holdTime)) {
        _holdFlag = true;
        return true;
    }
    return false;
}
