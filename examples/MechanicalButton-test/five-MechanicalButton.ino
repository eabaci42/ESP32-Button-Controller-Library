#include "MechanicalButton.h"

// Define the GPIO pins for the buttons
const int buttonPins[] = {36, 39, 34, 35, 32};
const int numberOfButtons = 5;

// Create an array to hold the button objects
MechanicalButton buttons[numberOfButtons];

void setup() {
  Serial.begin(115200);
  // Initialize each button object
  for(int i = 0; i < numberOfButtons; ++i) {
    buttons[i] = MechanicalButton(buttonPins[i]);
  }
}

void loop() {
  // Update and check each button's state
  for(int i = 0; i < numberOfButtons; ++i) {
    buttons[i].update();
    if(buttons[i].isPressed()) {
      Serial.print("Button ");
      Serial.print(i + 1);
      Serial.println(" pressed.");
    }
  }
  delay(100); // Small delay to avoid flooding the serial output
}