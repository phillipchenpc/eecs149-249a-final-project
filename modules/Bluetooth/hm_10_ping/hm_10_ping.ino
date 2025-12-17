#include <SoftwareSerial.h>
SoftwareSerial hm10(2, 3); // RX, TX

void setup() {
  Serial.begin(9600);
  hm10.begin(9600);

  Serial.println("Type AT commands. No line endings.");
}

void loop() {
  // PC -> HM-10
  while (Serial.available()) {
    hm10.write(Serial.read());
  }

  // HM-10 -> PC
  while (hm10.available()) {
    Serial.print("<< ");
    Serial.write(hm10.read());
    Serial.println("");
  }
}
