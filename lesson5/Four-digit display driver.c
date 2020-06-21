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
  pinMode(IN1, OUTPUT);//输入1
  pinMode(IN2, OUTPUT);//输入2
  pinMode(IN3, OUTPUT);//输入3
  pinMode(IN4, OUTPUT);//输入4
  pinMode(S1, OUTPUT);//片选1
  pinMode(S2, OUTPUT);//片选2
  pinMode(S3, OUTPUT);//片选3
  pinMode(S4, OUTPUT);//片选4
  pinMode(LT,OUTPUT);//测试 
  pinMode(BT,OUTPUT);//显隐 
  Serial.begin(9600);//串口初始化 
  
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
	/*获取输入数字字符串长度*/ 
    if(Serial.available()>0){
        delay(1000);
        num=Serial.available();
        Serial.print(num);
    }
    /*数字显示程序主体*/
    while(Serial.available()>0){
    	/*数显归零*/
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
        /*超长数字显示*/
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
        
        /*四位及以内数字的显示*/
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
    
    while(Serial.read()>=0){}//清除串口缓存 
}
