#include <Servo.h>
#define BUTTON 10
#define SOUND_SENSOR A4
#define LED 13

Servo myservo;

void setup() {
  myservo.attach(9);
  pinMode(BUTTON, INPUT);
  pinMode(SOUND_SENSOR, INPUT);
  pinMode(LED, OUTPUT);
}

int position = 0;
bool button_state = false;
void loop() {
  if (digitalRead(BUTTON) == HIGH) {
    button_state = !button_state;
  }

  if (button_state) {
    int temp = map(analogRead(SOUND_SENSOR), 0, 1023, 0, 255);
    if (temp > position) {
      position = temp;
    }
    myservo.write(position);
    digitalWrite(LED, HIGH);
  } else {
    position = 0;
    myservo.write(position);
    digitalWrite(LED, LOW);
  }
}
