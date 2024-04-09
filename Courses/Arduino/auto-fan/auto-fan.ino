#include <dht11.h>
#define DHT11_PIN A4
#define LED 13
#define FAN 11

dht11 DHT;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(FAN, OUTPUT);
}

void loop() {
  int chk;
  chk = DHT.read(DHT11_PIN);
  if (chk == DHTLIB_OK) {
    float humidity = DHT.humidity;
    float temperature = DHT.temperature;
    if (humidity > 95 || temperature > 32) {
      digitalWrite(LED, HIGH);
      analogWrite(FAN, 255);
    } else {
      digitalWrite(LED, LOW);
      analogWrite(FAN, 0);
    }
    Serial.print(humidity, 1);
    Serial.print('\t');
    Serial.println(temperature, 1);
  }
  delay(10);
}
