const int TRIG = 9;
const int ECHO = 10;

float getDisctanceCm() {
  long total = 0;
  int goodReads = 0;

  for (int i = 0; i < 5; i++) {
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);

    long t = pulseIn(ECHO, HIGH, 30000);

    if (t > 0) {
      float cm = t * 0.0343 / 2.0;
      if (cm >= 2 && cm <= 300) {
        total += cm;
        goodReads++;
      }
    }
    delay(10);
  }

  if (goodReads == 0) return -1;
  return total / goodReads;
}


void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(9600);
}

void loop() {
  float d = getDisctanceCm();

  if (d < 0) {
    Serial.println("Nothing detected");
  } else {
    Serial.print("Distance ");
    Serial.print(d);
    Serial.println(" cm");
  }
  
  delay(150);
}
