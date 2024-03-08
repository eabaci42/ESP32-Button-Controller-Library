#include "CapacitiveTouchButton.h"

CapacitiveTouchButton::CapacitiveTouchButton(uint8_t touchPin, uint16_t sensitivity) {
    _touchPin = touchPin;
    _sensitivity = sensitivity;
    _touchState = false;
    _lastTouchState = false;
    _touched = false;
    _released = false;
}

void CapacitiveTouchButton::update() {
    // Kapasitif dokunma değerini oku
    uint16_t touchValue = touchRead(_touchPin);

    // Dokunma durumunu güncelle
    bool currentTouchState = touchValue < _sensitivity;

    if (currentTouchState != _lastTouchState) {
        if (currentTouchState) {
            _touched = true;
        } else {
            _released = true;
        }
    }

    _touchState = currentTouchState;
    _lastTouchState = currentTouchState;
}

bool CapacitiveTouchButton::isTouched() {
    if (_touched) {
        _touched = false;
        return true;
    }
    return false;
}

bool CapacitiveTouchButton::wasTouched() {
    return _touchState;
}

bool CapacitiveTouchButton::wasReleased() {
    if (_released) {
        _released = false;
        return true;
    }
    return false;
}
