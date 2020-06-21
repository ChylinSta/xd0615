#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

#define S1 8
#define S2 9
#define S3 10
#define S4 11

#define LT 6
#define BT 7

void setup()
{
  pinMode(IN1, OUTPUT);//����1
  pinMode(IN2, OUTPUT);//����2
  pinMode(IN3, OUTPUT);//����3
  pinMode(IN4, OUTPUT);//����4
  pinMode(S1, OUTPUT);//Ƭѡ1
  pinMode(S2, OUTPUT);//Ƭѡ2
  pinMode(S3, OUTPUT);//Ƭѡ3
  pinMode(S4, OUTPUT);//Ƭѡ4
  pinMode(LT,OUTPUT);//���� 
  pinMode(BT,OUTPUT);//���� 
  Serial.begin(9600);//���ڳ�ʼ�� 
  
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);

  digitalWrite(S1,HIGH);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  digitalWrite(S4,HIGH);
}

int i,num;
byte income=0;
void loop()
{
	/*��ȡ���������ַ�������*/ 
    if(Serial.available()>0){
        delay(1000);
        num=Serial.available();
        Serial.print(num);
    }
    /*������ʾ��������*/
    while(Serial.available()>0){
    	/*���Թ���*/
        for(i=8;i<12;i++){
            digitalWrite(i,LOW);
            digitalWrite(IN1,LOW);
            digitalWrite(IN2,LOW);
            digitalWrite(IN3,LOW);
            digitalWrite(IN4,LOW);
            digitalWrite(i,HIGH);
        }
        i=0;
        if(num==1){
            i=11;
        }
        else if(num==2){
            i=10;
        }
        else if(num==3){
            i=9;
        }
        /*����������ʾ*/
        else if(num>4){
            i=8;
            for(;i<12;i++){
                digitalWrite(i,LOW);
                income=Serial.read();
                income=income-'0';
                digitalWrite(IN1,income&0x1);
                digitalWrite(IN2,(income>>1)&0x1);
                digitalWrite(IN3,(income>>2)&0x1);
                digitalWrite(IN4,(income>>3)&0x1);
                delay(10);
                digitalWrite(i,HIGH);
            }
            i=8;
            delay(2000);
            continue;
        }
        
        else{
            i=8;
        }
        
        /*��λ���������ֵ���ʾ*/
        for(;i<12;i++){
            digitalWrite(i,LOW);
            income=Serial.read();
            income=income-'0';
            digitalWrite(IN1,income&0x1);
            digitalWrite(IN2,(income>>1)&0x1);
            digitalWrite(IN3,(income>>2)&0x1);
            digitalWrite(IN4,(income>>3)&0x1);
            delay(10);
            digitalWrite(i,HIGH);
        }
    }
    
    while(Serial.read()>=0){}//������ڻ��� 
}
