const int windPin = 0;
const int rstartPin = 2;
const int rendPin = 5;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.write(255);
  forceData();
  windData();
  delay(5);
}

void forceData() {
  for (int i = rstartPin; i <= rendPin; i++) {
    int s = analogRead(i);
    Serial.write(s >> 3);
    Serial.write(s & 7);
  }
}

void windData() {
  int s = analogRead(windPin);
  Serial.write(s >> 3);
  Serial.write(s & 7);
}

void test() {
  int s = analogRead(4);
  Serial.println(s);
}
