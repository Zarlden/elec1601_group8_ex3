// C++ code
#define READ_PIN A0

void setup()
{
  pinMode(READ_PIN, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int val = analogRead(READ_PIN);
  Serial.println(val);
  delay(100);
}