#include "SoftwareButton.h"

SoftwareButton::SoftwareButton() {
    _pressedState = false;
    _lastPressedState = false;
    _triggered = false;
    _released = false;
}

void SoftwareButton::trigger() {
    _pressedState = true;
    _triggered = true;
}

void SoftwareButton::update() {
    if (_pressedState && !_lastPressedState) {
        _released = true;
    }

    _lastPressedState = _pressedState;

    // Basma durumunu resetle
    if (_triggered) {
        _pressedState = false;
        _triggered = false;
    }
}

bool SoftwareButton::isPressed() {
    if (_triggered) {
        _triggered = false;
        return true;
    }
    return false;
}

bool SoftwareButton::wasPressed() {
    return _pressedState;
}

bool SoftwareButton::wasReleased() {
    if (_released) {
        _released = false;
        return true;
    }
    return false;
}
