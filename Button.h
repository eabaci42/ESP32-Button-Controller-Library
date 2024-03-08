#ifndef BUTTON_H
#define BUTTON_H

#include "Arduino.h"

// Temel buton sınıfı tanımı
class Button {
public:
    // Sanal destructor, türetilmiş sınıflar düzgün bir şekilde yok edilebilir
    virtual ~Button() {}

    // Butona basılma olayı
    virtual void press() = 0;

    // Butonun bırakılma olayı
    virtual void release() = 0;

    // Butonun basılı olup olmadığını kontrol etme
    virtual bool isPressed() const = 0;
};

#endif
