// MechanicalButton.cpp
#include "MechanicalButton.h"

MechanicalButton::MechanicalButton(int pin, int mode, unsigned long debounceDelay) {
    _pin = pin;
    _mode = mode; // Save the mode (0 for pull-up, 1 for pull-down)
    _debounceDelay = debounceDelay;
    _pressed = false;
    _released = false;
    _holdFlag = false;
    _lastDebounceTime = 0;
    _lastPressTime = 0;
    pinMode(_pin, INPUT); // Always set to INPUT mode

    _state = (_mode == 0) ? HIGH : LOW; // Initialize based on mode
    _lastState = _state;
}

void MechanicalButton::update() {
    bool reading = digitalRead(_pin);
    if (reading != _lastState) {
        _lastDebounceTime = millis();
    }
    if ((millis() - _lastDebounceTime) > _debounceDelay) {
        if (reading != _state) {
            _state = reading;
            // Adjust logic based on the mode
            if ((_mode == 0 && _state == LOW) || (_mode == 1 && _state == HIGH)) {
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
    // Adjust logic based on the mode
    return (_mode == 0) ? _state == LOW : _state == HIGH;
}

bool MechanicalButton::wasReleased() {
    if (_released) {
        _released = false;
        return true;
    }
    return false;
}

bool MechanicalButton::isHeld(unsigned long holdTime) {
    bool condition = (_mode == 0) ? _state == LOW : _state == HIGH;
    if (condition && !_holdFlag && (millis() - _lastPressTime >= holdTime)) {
        _holdFlag = true;
        return true;
    }
    return false;
}
