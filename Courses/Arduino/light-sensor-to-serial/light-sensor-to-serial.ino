#define LightSensor A4

void setup() {
  Serial.begin(9600);
  pinMode(LightSensor, INPUT);
}

void loop() {
  int sensor_value = analogRead(LightSensor);
  if (sensor_value > 250) {
    Serial.println("Light intensity value is large!");
  } else if (sensor_value < 50) {
    Serial.println("Light intensity value is small!");
  }
  delay(500);
}