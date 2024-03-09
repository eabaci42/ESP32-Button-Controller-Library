#include "MechanicalButton.h"

MechanicalButton::MechanicalButton(int pin, Mode mode, unsigned long debounceDelay) {
    _pin = pin;
    _mode = mode;
    _debounceDelay = debounceDelay;
    _pressed = false;
    _released = false;
    _holdFlag = false;
    _lastDebounceTime = 0;
    _lastPressTime = 0;

    if (_mode == PULLUP) {
        pinMode(_pin, INPUT_PULLUP);
        _state = HIGH;
        _lastState = HIGH;
    } else { // PULLDOWN
        pinMode(_pin, INPUT_PULLDOWN);
        _state = LOW;
        _lastState = LOW;
    }
}

void MechanicalButton::update() {
    bool reading = digitalRead(_pin);
    if (reading != _lastState) {
        _lastDebounceTime = millis();
    }
    if ((millis() - _lastDebounceTime) > _debounceDelay) {
        if (reading != _state) {
            _state = reading;
            if ((_state == LOW && _mode == PULLUP) || (_state == HIGH && _mode == PULLDOWN)) {
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
    return (_mode == PULLUP) ? _state == LOW : _state == HIGH;
}

bool MechanicalButton::wasReleased() {
    if (_released) {
        _released = false;
        return true;
    }
    return false;
}

bool MechanicalButton::isHeld(unsigned long holdTime) {
    bool condition = (_mode == PULLUP) ? _state == LOW : _state == HIGH;
    if (condition && !_holdFlag && (millis() - _lastPressTime >= holdTime)) {
        _holdFlag = true;
        return true;
    }
    return false;
}
