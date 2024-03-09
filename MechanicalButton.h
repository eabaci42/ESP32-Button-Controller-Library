#ifndef MECHANICALBUTTON_H
#define MECHANICALBUTTON_H

#include "Arduino.h"

class MechanicalButton {
public:
    // Kurucu fonksiyonu güncellendi: okuma modu ('a' için analog, 'd' için dijital) ve eşik değeri parametreleri eklendi.
    MechanicalButton(int pin, char readType = 'a', int mode = 1, unsigned long debounceDelay = 50, int threshold = 512); // Analog okuma için varsayılan eşik değeri 512 olarak ayarlandı.
    void update();
    bool isPressed();
    bool wasPressed();
    bool wasReleased();
    bool isHeld(unsigned long holdTime = 1000);
    int getAnalogValue(); // Son okunan analog değeri döndüren yeni metod eklendi.

private:
    int _pin;
    char _readType; // 'a' için analog, 'd' için dijital
    int _mode; // 0 for pull-up, 1 for pull-down
    unsigned long _debounceDelay;
    unsigned long _lastDebounceTime;
    unsigned long _lastPressTime;
    bool _state;
    bool _lastState;
    bool _pressed;
    bool _released;
    bool _holdFlag;
    int _threshold; // Analog okuma için eşik değeri
    int _lastAnalogValue; // Son okunan analog değeri saklar
};

#endif
