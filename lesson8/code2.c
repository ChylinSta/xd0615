/*�趨*/
void setup() {
    Serial.begin(9600);          //��ʼ���������� 
    pinMode(2, INPUT_PULLUP);          //����2�����Ϊ���룬�������ڲ��������� 
    pinMode(13, OUTPUT);           //����13�����Ϊ��������������ϵ�LED 
}

/*ѭ������*/
void loop() {
    int sensorVal = digitalRead(2);         //����sensorVal������������ť״̬����sensorVal���� 
    Serial.println(sensorVal);          //ͨ�����ڽ���ť״̬��ӡ�����м������� 
    /*���°�ťʱ���"0"��δ����ʱ���"1"*/
    
    /*�ж���ť״̬*/
    if (sensorVal == HIGH) {
        digitalWrite(13, LOW);          //δ����ʱLED����Ϩ��״̬ 
    }
	else {
        digitalWrite(13, HIGH);          //����ʱ����LED 
    }
}
