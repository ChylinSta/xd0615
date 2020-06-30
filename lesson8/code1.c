const int ledPin =  LED_BUILTIN;          //初始化针脚
int ledState = LOW;          //初始化数据
unsigned long previousMillis = 0;          //定义并初始化原始时间
const long interval = 1000;          //设定闪烁等待时长

/*设定*/
void setup() {
    pinMode(ledPin, OUTPUT);          //设定输出针脚
}

/*循环函数*/
void loop() {
    unsigned long currentMillis = millis();          //定义并获取目前时间
    
    /*实现闪烁功能*/
    /*判定是否满足闪烁条件*/
    if (currentMillis - previousMillis >= interval) {
    	
        previousMillis = currentMillis;          //将当前时间设为下一次判定的原始时间
        
        /*判定当前LED状态*/
        if (ledState == LOW) {
            ledState = HIGH;          //由暗变亮
        }
        else {
            ledState = LOW;          //由亮变暗
        }
        
        digitalWrite(ledPin, ledState);          //更新LED状态
    }
}
