#include "MechanicalButton.h"

// Define the GPIO pins for the buttons
//const int buttonPins[] = {36, 39, 34, 35, 32};

// Create an array to hold the button objects
MechanicalButton up_button(32, 1);
MechanicalButton down_button(35, 1);
MechanicalButton stop_button(34, 1);
MechanicalButton left_button(39, 1);
MechanicalButton right_button(36, 1);

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Update and check each button's state
    up_button.update();
    if(up_button.isPressed()) {
      Serial.print("Button ");
      Serial.print("UP");
      Serial.println(" pressed.");
    }
    delay(50); // Small delay to avoid flooding the serial output

    down_button.update();
    if(down_button.isPressed()) {
      Serial.print("Button ");
      Serial.print("DOWN");
      Serial.println(" pressed.");
    }
    delay(50); // Small delay to avoid flooding the serial output

    stop_button.update();
    if(stop_button.isPressed()) {
      Serial.print("Button ");
      Serial.print("STOP");
      Serial.println(" pressed.");
    }
    delay(50); // Small delay to avoid flooding the serial output

    left_button.update();
    if(left_button.isPressed()) {
      Serial.print("Button ");
      Serial.print("LEFT");
      Serial.println(" pressed.");
    }
    delay(50); // Small delay to avoid flooding the serial output

    right_button.update();
    if(right_button.isPressed()) {
      Serial.print("Button ");
      Serial.print("RIGHT");
      Serial.println(" pressed.");
    }
  delay(50); // Small delay to avoid flooding the serial output
}