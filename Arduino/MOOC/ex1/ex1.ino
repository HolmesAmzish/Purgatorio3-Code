#define LED 13

void setup() {
  pinMode(LED, OUTPUT);
  for (int i = 0; i < 2; ++i) {
    digitalWrite(LED, HIGHT);
    delay(200);
    digitalWrite(LED, LOW);
    delay(200);
  }
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(2000);
}
