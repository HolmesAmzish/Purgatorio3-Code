#include <dht11.h>
#define DHT11_PIN A4

dht11 DHT;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int chk;
  chk = DHT.read(DHT11_PIN);
  if (chk == DHTLIB_OK) {
    Serial.print(DHT.humidity, 1);
    Serial.print(",\t");
    Serial.println(DHT.temperature, 1);
  }
  delay(100);
}