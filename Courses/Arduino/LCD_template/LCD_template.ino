#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 16, 2); // Address: 0x20, 2 rows 16 columns

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 1);
  lcd.print("Arduino ");
}

void loop() {

}