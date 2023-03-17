void setup() {
  Serial.begin(115200);
}

void loop() {
  int vol = analogRead(A0);
  int data = map(vol,0,1023,0,255);
  Serial.write(data);
  delay(10);
}

