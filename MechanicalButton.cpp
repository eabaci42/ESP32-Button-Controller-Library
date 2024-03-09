#include "MechanicalButton.h"

// Analog okumalar için 1V eşik değeri ESP32 üzerindeki maksimum 3.3V referansına göre hesaplanır
// 1V eşik değeri için analog değer: 1V / 3.3V * 4095 ≈ 1241
// Bu değer kurucu fonksiyon üzerinden alınacaktır, dolayısıyla burada tanımlamaya gerek yoktur.

MechanicalButton::MechanicalButton(int pin, char readType, int mode, unsigned long debounceDelay, int threshold) : _pin(pin),
                                                                                                                   _readType(readType),
                                                                                                                   _mode(mode),
                                                                                                                   _debounceDelay(debounceDelay),
                                                                                                                   _threshold(threshold), // Eşik değeri kurucu fonksiyonda ayarlanır.
                                                                                                                   _pressed(false),
                                                                                                                   _released(false),
                                                                                                                   _holdFlag(false),
                                                                                                                   _lastDebounceTime(0),
                                                                                                                   _lastPressTime(0),
                                                                                                                   _state(false),
                                                                                                                   _lastState(false)
{
    pinMode(_pin, INPUT); // ESP32 için, analog ve dijital pin modunu ayarla
}
/*
void MechanicalButton::update()
{
    bool reading = false;
    if (_readType == 'a')
    { // Analog okuma modu
        int analogValue = analogRead(_pin);
        reading = analogValue > _threshold; // Eşik değeri üzeri okumaları kabul et
    }
    else
    { // Dijital okuma modu
        reading = digitalRead(_pin) == HIGH;
    }

    // Debounce mantığı
    if (reading != _lastState)
    {
        _lastDebounceTime = millis();
    }
    if ((millis() - _lastDebounceTime) > _debounceDelay)
    {
        if (reading != _state)
        {
            _state = reading;
            if (reading)
            {
                _pressed = true;
                _lastPressTime = millis();
            }
            else
            {
                _released = true;
                _holdFlag = false;
            }
        }
    }
    _lastState = reading;
}
*/



void MechanicalButton::update() {
    bool reading = false;
    
    // Analog veya dijital okuma moduna göre okuma yap
    if (_readType == 'a') {
        // Analog okuma yap ve son değeri _lastAnalogValue'de sakla
        _lastAnalogValue = analogRead(_pin);
        // Eşik değerin üzerindeyse, reading'i true olarak ayarla
        reading = _lastAnalogValue > _threshold;
    } else {
        // Dijital okuma yap
        reading = digitalRead(_pin) == HIGH;
    }

    // Debounce mantığı
    if (reading != _lastState) {
        _lastDebounceTime = millis();
    }
    if ((millis() - _lastDebounceTime) > _debounceDelay) {
        if (reading != _state) {
            _state = reading;
            if (reading) {
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

bool MechanicalButton::isPressed()
{
    if (_pressed)
    {
        _pressed = false;
        return true;
    }
    return false;
}

bool MechanicalButton::wasPressed()
{
    // Moda bağlı mantık
    return (_mode == 0) ? !_state : _state;
}

bool MechanicalButton::wasReleased()
{
    if (_released)
    {
        _released = false;
        return true;
    }
    return false;
}

bool MechanicalButton::isHeld(unsigned long holdTime)
{
    bool condition = (_mode == 0) ? !_state : _state;
    if (condition && !_holdFlag && (millis() - _lastPressTime >= holdTime))
    {
        _holdFlag = true;
        return true;
    }
    return false;
}


int MechanicalButton::getAnalogValue() {
    if (_readType == 'a') {
        return _lastAnalogValue; // Analog moddaysa, son okunan analog değeri döndür
    } else {
        return -1; // Dijital moddaysa, mantıklı bir değer döndürme
    }
}