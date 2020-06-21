char ch=' ';
void setup()
{
    Serial.begin(9600);
    pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);
    pinMode(8,OUTPUT);
    pinMode(9,OUTPUT);
    Serial.println("ok!");
}

void loop()
{
    if(Serial.available()>0){
  	    ch=Serial.read();
  	    if(ch=='f'){
  	    	digitalWrite(6,HIGH);
            digitalWrite(7,LOW);
            digitalWrite(8,LOW);
            digitalWrite(9,HIGH);
		}
		else if(ch=='b'){
			digitalWrite(7,HIGH);
            digitalWrite(6,LOW);
            digitalWrite(9,LOW);
            digitalWrite(8,HIGH);
		}
		else if(ch=='r'){
			digitalWrite(7,HIGH);
            digitalWrite(6,LOW);
            digitalWrite(8,LOW);
            digitalWrite(9,HIGH);
		}
		else if(ch=='l'){
			digitalWrite(6,HIGH);
            digitalWrite(7,LOW);
            digitalWrite(9,LOW);
            digitalWrite(8,HIGH);
		}
		else if(ch=='s'){
			digitalWrite(6,LOW);
            digitalWrite(7,LOW);
            digitalWrite(8,LOW);
            digitalWrite(9,LOW);
		}
	}
}
