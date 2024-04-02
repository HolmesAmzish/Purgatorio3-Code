#define LED 13
#define LIGHT_SENSOR 10
#define SOUND_SENSOR 11

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(LIGHT_SENSOR, INPUT);
  pinMode(SOUND_SENSOR, INPUT);
}

void loop() {
  if(analogRead(LIGHT_SENSOR) <= 50) {
    if(analogRead(SOUND_SENSOR) >= 250) {
      digitalWrite(LED, HIGH);
      delay(3000);
      digitalWrite(LED, LOW);
    }
  }
}