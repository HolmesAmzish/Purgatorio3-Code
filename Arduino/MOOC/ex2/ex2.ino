const int ledPin = 13;

bool ledState = LOW;

unsigned long previousMillis = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis < 200) {
    digitalWrite(ledPin, HIGH);
    ledState = HIGH;
  } else if (currentMillis - previousMillis < 200 * 2) {
    digitalWrite(ledPin, LOW);
    ledState = LOW;
  }
  else if (currentMillis - previousMillis < 200 * 4) {
    if (currentMillis - previousMillis < 200 * 4 + 1000) {
      digitalWrite(ledPin, HIGH);
      ledState = HIGH;
    } else if (currentMillis - previousMillis < 200 * 4 + 1000 + 2000) {
      digitalWrite(ledPin, LOW);
      ledState = LOW;
    }
  }

  if (currentMillis - previousMillis >= 200 * 4 + 1000 + 2000) {
    previousMillis = currentMillis;
  }
}
