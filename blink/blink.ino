void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("LED on");
  delay(1000);

  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("LED off");
  delay(1000);
}
