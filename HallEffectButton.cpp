#include "HallEffectButton.h"

HallEffectButton::HallEffectButton(int threshold) {
    _threshold = threshold;
    _triggerState = false;
    _lastTriggerState = false;
    _triggered = false;
    _released = false;
}

void HallEffectButton::update() {
    // Hall etkisi sensör değerini oku
    int hallValue = hallRead();

    // Tetikleme durumunu güncelle
    bool currentTriggerState = hallValue < _threshold;

    if (currentTriggerState != _lastTriggerState) {
        if (currentTriggerState) {
            _triggered = true;
        } else {
            _released = true;
        }
    }

    _triggerState = currentTriggerState;
    _lastTriggerState = currentTriggerState;
}

bool HallEffectButton::isTriggered() {
    if (_triggered) {
        _triggered = false;
        return true;
    }
    return false;
}

bool HallEffectButton::wasTriggered() {
    return _triggerState;
}

bool HallEffectButton::wasReleased() {
    if (_released) {
        _released = false;
        return true;
    }
    return false;
}
