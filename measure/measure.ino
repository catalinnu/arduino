
  const int sensorPin = A0;

  void setup() {
    Serial.begin(9600);
  }

  void loop() {
    Serial.print("A0=");
    Serial.println(analogRead(sensorPin));

    delay(500);
  }
