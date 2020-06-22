#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

void setup()
{
    lcd.begin(16,2);
    Serial.begin(9600);
}

int i,num;
void loop()
{
    lcd.setCursor(0,0);
    if(Serial.available()>0){
        delay(1000);
        num=Serial.available();
        Serial.print(num);
    }
    if(num<=16){
    	if(Serial.available()){
            delay(100);
            lcd.clear();
            while(Serial.available()>0){
                lcd.print(Serial.readString());
            }
        }
	}
	if(num>16 && num<=32){
		if(Serial.available()){
            delay(100);
            lcd.clear();
            while(Serial.available()>0){
            	for(i=0;i<16;i++){
                    if(Serial.available()<=0){
                        break;
                    }
            		lcd.print(Serial.read()-'0');
            		if(i==15){
            			lcd.setCursor(0,1);
					}
				}
            }
        }
	}
}
