#include "SpecialFunctionButton.h"

SpecialFunctionButton::SpecialFunctionButton() : _triggerState(false), _lastTriggerState(false), _triggered(false), _released(false) {
}

void SpecialFunctionButton::update() {
    // Özel koşulu veya sensörü kontrol et
    // Bu, örneğin bir hareket sensöründen gelen bir değeri okumak olabilir
    bool currentTriggerState = /* Özel koşul veya sensör kontrolü */;

    if (currentTriggerState != _lastTriggerState) {
        if (currentTriggerState) {
            _triggered = true;
        } else {
            _released = true;
        }
    }

    _lastTriggerState = currentTriggerState;
}

bool SpecialFunctionButton::isTriggered() {
    if (_triggered) {
        _triggered = false;
        return true;
    }
    return false;
}

bool SpecialFunctionButton::wasTriggered() {
    return _triggerState;
}

bool SpecialFunctionButton::wasReleased() {
    if (_released) {
        _released = false;
        return true;
    }
    return false;
}
