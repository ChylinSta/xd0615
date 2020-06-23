#include <MsTimer2.h>     //��ʱ�����ͷ�ļ�

#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7
#define S1 10

#define LT 8
#define BT 9

int i=0; //ѭ����ʾ��ʹ�õ��ò��� 
byte income=0;
int tick = 0; //��ʱ���� 
/*�жϷ������*/
void onTimer()
{
    Serial.print("timer ");
    Serial.println(tick++);
    digitalWrite(10,LOW);
    income=i;
    digitalWrite(IN1,income&0x1);
    digitalWrite(IN2,(income>>1)&0x1);
    digitalWrite(IN3,(income>>2)&0x1);
    digitalWrite(IN4,(income>>3)&0x1);
    delay(10);
    digitalWrite(10,HIGH);
    i++;
    if(i==9){
        i=-1;
    }
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
  
    MsTimer2::set(1000, onTimer);
    MsTimer2::start();
}

void loop()
{
    
}
