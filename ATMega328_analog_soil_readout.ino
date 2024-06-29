const int soilRead = A0;
void setup() {
  Serial.begin(115200);
  delay(100);
}

void loop() {
  Serial.print(analogRead(soilRead));
  Serial.print('\n');
  Serial.flush();
  delay(1500);
}
