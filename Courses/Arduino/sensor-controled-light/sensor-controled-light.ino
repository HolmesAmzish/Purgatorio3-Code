const int ledPin = 10;
const int sensorPin = 11;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int sensor_value = analogRead(sensorPin);
  int brightness = map(sensor_value, 1023, 0, 0, 255); // 反向控制强度
  analogWrite(ledPin, brightness);
}