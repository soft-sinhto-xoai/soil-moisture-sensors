#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int airValue = 600;
const int waterValue = 350;
int soilMoistureValue = 0;
int soilMoisturePercent = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  soilMoistureValue = analogRead(A0);
  Serial.println(soilMoistureValue);
  soilMoisturePercent = map(soilMoistureValue, airValue, waterValue, 0, 100);
  if(soilMoisturePercent >= 100){
    Serial.println("100%");
    lcd.setCursor(0,0);
    lcd.print("Soil Moisture");
    lcd.setCursor(0,1);
    lcd.print("100%");
    delay(250);
    lcd.clear();
  }
  else if(soilMoisturePercent <= 0){
    Serial.println("0%");
    lcd.setCursor(0,0);
    lcd.print("Soil Moisture");
    lcd.setCursor(0,1);
    lcd.print("0%");
    delay(250);
    lcd.clear();
  }
  else if(soilMoisturePercent > 0 && soilMoisturePercent < 100){
    Serial.print(soilMoisturePercent);
    Serial.println("%");
    lcd.setCursor(0,0);
    lcd.print("Soil Moisture");
    lcd.setCursor(0,1);
    lcd.print(soilMoisturePercent);
    lcd.print("%");
    delay(250);
    lcd.clear();
  }
}
