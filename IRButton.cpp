#include "IRButton.h"

IRButton::IRButton(int recvPin) : _recvPin(recvPin), _irrecv(recvPin), _lastCode(0), _pressed(false), _released(false) {
    _irrecv.enableIRIn(); // IR alıcısını başlat
}

void IRButton::update() {
    if (_irrecv.decode(&_results)) {
        if (_results.value != _lastCode) {
            _lastCode = _results.value;
            _pressed = true;
        } else {
            _released = true;
        }
        _irrecv.resume(); // Sonraki değeri almak için alıcıyı hazırla
    }
}

bool IRButton::isPressed(unsigned long code) {
    if (_pressed && _lastCode == code) {
        _pressed = false;
        return true;
    }
    return false;
}

bool IRButton::wasPressed() {
    return _pressed;
}

bool IRButton::wasReleased() {
    if (_released) {
        _released = false;
        return true;
    }
    return false;
}
