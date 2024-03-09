
#ifndef UNPROTECTEDMECHANICALBUTTON_H
#define UNPROTECTEDMECHANICALBUTTON_H

#include "Button.h"

class UnprotectedMechanicalButton : public Button {
public:
    UnprotectedMechanicalButton(int pin);
    virtual ~UnprotectedMechanicalButton() {}

    void press() override;
    void release() override;
    bool isPressed() const override;

private:
    int _pin;
    bool _isPressed;
};

#endif // UNPROTECTEDMECHANICALBUTTON_H
