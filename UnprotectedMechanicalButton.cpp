
#include "UnprotectedMechanicalButton.h"
#include "Arduino.h"

UnprotectedMechanicalButton::UnprotectedMechanicalButton(int pin) : _pin(pin), _isPressed(false) {
    pinMode(_pin, INPUT); // Initialize the pin as an input
}

void UnprotectedMechanicalButton::press() {
    if (digitalRead(_pin) == HIGH) { // Assuming a pull-down resistor is used
        _isPressed = true;
    }
}

void UnprotectedMechanicalButton::release() {
    if (digitalRead(_pin) == LOW) {
        _isPressed = false;
    }
}

bool UnprotectedMechanicalButton::isPressed() const {
    return _isPressed;
}
