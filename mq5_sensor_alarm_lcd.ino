#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int mq5Pin = A0;       // Pin sensor MQ5 terhubung ke A0
const int piezoPin = 8;      // Pin piezo speaker terhubung ke pin digital 8
const int threshold = 300;   // Ambang batas untuk mendeteksi gas berbahaya

void setup() {
  pinMode(mq5Pin, INPUT);
  pinMode(piezoPin, OUTPUT);
  
  lcd.begin(16, 2);
  lcd.print("Gas Detector");
  delay(2000);
  lcd.clear();
}

void loop() {
  int mq5Value = analogRead(mq5Pin); // Membaca nilai dari sensor MQ5

  if (mq5Value > threshold) {
    // Jika nilai sensor melebihi, nanti alarm bunyi dan ada pesan di lcd nya
    digitalWrite(piezoPin, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("MAYDAY! BAHAYA! GAS!");
    lcd.setCursor(0, 1);
    lcd.print("Terdeteksi");
  } else {
    // Jika nilai sensor di bawah batasnya, alarm mati dan pesan lcd ilang
    digitalWrite(piezoPin, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Aman ess!");
  }

  delay(1000); 
}
