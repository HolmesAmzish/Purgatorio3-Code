#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20,16,2); // address:0x20,2 rows 16 columns
  void setup(){
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Time");
}

int hour = 0, min = 0, sec = 0;

void loop(){
  lcd.setCursor(0, 1);
  lcd.print(hour < 10 ? "0" : "");
  lcd.print(hour);
  lcd.print(':');
  lcd.print(min < 10 ? "0" : "");
  lcd.print(min);
  lcd.print(':');
  lcd.print(sec < 10 ? "0" : "");
  lcd.print(sec++);
  if (sec == 60) {
    ++min;
    sec = 0;
  }
  if (min == 60) {
    ++hour;
    min = 0;
  }
  delay(1000);
}