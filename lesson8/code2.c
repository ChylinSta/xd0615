/*设定*/
void setup() {
    Serial.begin(9600);          //初始化串口输入 
    pinMode(2, INPUT_PULLUP);          //设置2号针脚为输入，并启用内部上拉电阻 
    pinMode(13, OUTPUT);           //设置13号针脚为输出，启用主板上的LED 
}

/*循环函数*/
void loop() {
    int sensorVal = digitalRead(2);         //引入sensorVal变量，并将按钮状态读入sensorVal变量 
    Serial.println(sensorVal);          //通过串口将按钮状态打印到串行监视器上 
    /*按下按钮时输出"0"，未按下时输出"1"*/
    
    /*判定按钮状态*/
    if (sensorVal == HIGH) {
        digitalWrite(13, LOW);          //未按下时LED处于熄灭状态 
    }
	else {
        digitalWrite(13, HIGH);          //按下时点亮LED 
    }
}
