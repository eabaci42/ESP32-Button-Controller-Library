#include "MechanicalButton.h"

MechanicalButton UPButton(32, 'a'); // Analog okuma için 'a' modunu belirttik.

void setup() {
  Serial.begin(9600); // Seri portu başlatıyoruz.
}

void loop() {
  UPButton.update(); // Butonun durumunu güncelliyoruz.

  if (UPButton.isPressed()) {
    Serial.println("Butona Basıldı!"); // Eğer butona basıldıysa, bunu seri monitöre yazdır.
    // Analog değeri görüntüle
    Serial.print("Analog Değer: ");
    Serial.println(UPButton.getAnalogValue());
  }

  // Burada diğer kodlarınızı ekleyebilirsiniz.
  delay(100); // Okumalar arasında kısa bir gecikme
}
