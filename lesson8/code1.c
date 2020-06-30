const int ledPin =  LED_BUILTIN;          //��ʼ�����
int ledState = LOW;          //��ʼ������
unsigned long previousMillis = 0;          //���岢��ʼ��ԭʼʱ��
const long interval = 1000;          //�趨��˸�ȴ�ʱ��

/*�趨*/
void setup() {
    pinMode(ledPin, OUTPUT);          //�趨������
}

/*ѭ������*/
void loop() {
    unsigned long currentMillis = millis();          //���岢��ȡĿǰʱ��
    
    /*ʵ����˸����*/
    /*�ж��Ƿ�������˸����*/
    if (currentMillis - previousMillis >= interval) {
    	
        previousMillis = currentMillis;          //����ǰʱ����Ϊ��һ���ж���ԭʼʱ��
        
        /*�ж���ǰLED״̬*/
        if (ledState == LOW) {
            ledState = HIGH;          //�ɰ�����
        }
        else {
            ledState = LOW;          //�����䰵
        }
        
        digitalWrite(ledPin, ledState);          //����LED״̬
    }
}
