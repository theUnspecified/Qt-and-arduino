byte sig;
void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    sig = Serial.read();
    if(sig == 'O') {
      digitalWrite(13, HIGH);
    }
    if(sig == 'N')
    {
      digitalWrite(13, LOW);
    }
  }

}
