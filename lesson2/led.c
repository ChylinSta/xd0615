void setup()
{
  int i;
  for(i=0;i<8;i++){
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  int i;
  for(i=0;i<8;i++){
    if(i==0){
      digitalWrite(i, HIGH);
    }
    if(i>0&&i<7){
      digitalWrite(i, HIGH);
      delay(100);
      digitalWrite(i-1, LOW);
    }
    if(i==7){
      digitalWrite(i, HIGH);
      delay(100);
      digitalWrite(i-1, LOW);
      delay(100);
      digitalWrite(i, LOW);
    }
  }
}
