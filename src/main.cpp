int addiere(int a, int b) {
  return a + b;
}

int subtrahiere(int a, int b) {
  return a - b;
}

int multipliziere(int a, int b) {
  return a * b;
}

float dividiere(int a, int b) {
  return (float)a / b;
}

void setup() {
  Serial.begin(9600);
  Serial.println(addiere(10, 5));
  Serial.println(subtrahiere(10, 5));
  Serial.println(multipliziere(10, 5));
  Serial.println(dividiere(10, 5));
}

void loop() {
}
