#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7
#define S1 10

#define LT 8
#define BT 9

int i; //ѭ����ʾ��ʹ�õ��ò��� 
int pinInterrupt = 2; //���ж��źŵĽ�

void onChange()
{
    if ( digitalRead(pinInterrupt) == LOW )
        Serial.println("Key Down");
    else
        Serial.println("Key UP");
    i=-1;
}

void setup()
{
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(S1, OUTPUT);
  
    digitalWrite(S1,HIGH);
    digitalWrite(LT,HIGH);
    digitalWrite(BT,HIGH);
    Serial.begin(9600); //��ʼ������
  
    pinMode( pinInterrupt, INPUT);
    attachInterrupt( digitalPinToInterrupt(pinInterrupt), onChange, CHANGE);
}

byte income=0;
void loop()
{
    for(;i<10;i++){
        delay(1000);
        digitalWrite(10,LOW);
        income=i;
        digitalWrite(IN1,income&0x1);
        digitalWrite(IN2,(income>>1)&0x1);
        digitalWrite(IN3,(income>>2)&0x1);
        digitalWrite(IN4,(income>>3)&0x1);
        delay(10);
        digitalWrite(10,HIGH);
        if(i==9){
            i=-1;
        }
    }
}
