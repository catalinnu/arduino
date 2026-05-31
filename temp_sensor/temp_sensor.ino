#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int sensorPin = A0;

const float VCC = 4.6;          // measured Arduino voltage
const float R_FIXED = 10000.0;  // 10k resistor

const float R0 = 10000.0;       // thermistor resistance at 25C
const float T0 = 298.15;        // 25C in Kelvin
const float BETA = 3950.0;      // common value, hope it's good 

void setup() {
  Serial.begin(9600);
}

void loop() {
  int adc = analogRead(sensorPin);

  float vout = adc * VCC / 1023.0;

  // Layout: VCC --- thermistor --- A0 --- 10k --- GND
  float rThermistor = R_FIXED * (VCC / vout - 1.0);

  float tempK = 1.0 / ((1.0 / T0) + (1.0 / BETA) * log(rThermistor / R0));
  float tempC = tempK - 273.15;
  float tempF = tempC * 9.0 / 5.0 + 32.0;

  Serial.print("ADC=");
  Serial.print(adc);

  Serial.print("  Vout=");
  Serial.print(vout);

  Serial.print("V  R=");
  Serial.print(rThermistor);

  Serial.print(" ohms  Temp=");
  Serial.print(tempC);

  Serial.println(" C ");

  delay(500);
}
