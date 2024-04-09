#include <LiquidCrystal_I2C.h>

String name[2] = {"WANG DAWEI ", "SHENG ZIHAN"};
String id[2] = {"No.3230611080", "No.3230611081"};

LiquidCrystal_I2C lcd(0x20, 16, 2); // Address: 0x20, 2 rows 16 columns

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  for(int i = 0; i < 2; ++i) {
    lcd.setCursor(0, 0);
    lcd.print(name[i]);
    lcd.setCursor(0, 1);
    lcd.print(id[i]);
    delay(3000);
  }
}
