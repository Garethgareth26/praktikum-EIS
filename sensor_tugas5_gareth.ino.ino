#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#define FIREBASE_HOST "yourfirebasehost.firebaseio.com" // Ganti dengan URL
Firebase Anda
#define FIREBASE_AUTH "yourfirebaseauth" // Ganti dengan token otentikasi
Firebase Anda
#define WIFI_SSID "yourwifissid"
#define WIFI_PASSWORD "yourwifipassword"
#define IR_SENSOR_PIN 2 // Pin sensor inframerah
#define CONVEYOR_SPEED 1000 // Kecepatan conveyor dalam milidetik
#define LCD_ADDRESS 0x27 // Alamat LCD I2C
LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);
int totalCount = 0;
FirebaseData firebaseData;
void setup() {
Serial.begin(9600);
pinMode(IR_SENSOR_PIN, INPUT);

WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println("WiFi connected");
Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
lcd.init();
lcd.backlight();
lcd.setCursor(0, 0);
lcd.print("Barang: ");
}
void loop() {
int sensorValue = digitalRead(IR_SENSOR_PIN);
if (sensorValue == HIGH) {
delay(CONVEYOR_SPEED); // Menghindari bounce pada sensor
// Jika sensor mendeteksi objek
totalCount++;
updateDisplay();
updateFirebase();
}
}
void updateDisplay() {
lcd.setCursor(8, 0);
lcd.print(" "); // Membersihkan tampilan sebelumnya
lcd.setCursor(8, 0);
lcd.print(totalCount);
}
void updateFirebase() {
Firebase.setInt(firebaseData, "/total_count", totalCount);
if (Firebase.failed()) {
Serial.print("Gagal mengirim data ke Firebase: ");
Serial.println(firebaseData.errorReason());
}
}