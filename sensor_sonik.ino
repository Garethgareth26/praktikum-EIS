#include <NewPing.h> // Library untuk menggunakan sensor ultrasonik dengan Arduino

#define TRIGGER_PIN 11 // Mendefinisikan pin Arduino yang terhubung ke pin trigger sensor ultrasonik
#define ECHO_PIN 12    // Mendefinisikan pin Arduino yang terhubung ke pin echo sensor ultrasonik

#define MAX_DISTANCE 200 // Mendefinisikan jarak maksimum (dalam sentimeter) yang dapat diukur oleh sensor ultrasonik

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // Membuat sebuah instansi dari kelas NewPing untuk sensor ultrasonik
int previewDistance = 0; // Variabel untuk menyimpan jarak yang diukur sebelumnya

void setup() {
  // Fungsi setup dijalankan sekali ketika Arduino dihidupkan atau di-reset
  Serial.begin(9600); // Menginisialisasi komunikasi serial dengan kecepatan baud 9600 bit per detik
}

void loop() {
  // Fungsi loop dijalankan secara berulang selama Arduino dihidupkan atau di-reset
  delay(1000); // Memberi jeda eksekusi program selama 1000 milidetik (1 detik)

  unsigned int distance = sonar.ping_cm(); // Mengukur jarak dalam sentimeter menggunakan sensor ultrasonik

  // Membandingkan jarak saat ini dengan jarak sebelumnya untuk menentukan apakah objek mendekat atau menjauh
  if (distance < previewDistance) {
    Serial.print("Jarak = "); // Output string "Jarak = " ke monitor serial
    Serial.print(distance);   // Output jarak saat ini ke monitor serial
    Serial.println(" cm mendekat"); // Output string " cm mendekat" ke monitor serial diikuti dengan baris baru
  } else if (distance > previewDistance) {
    Serial.print("Jarak = "); // Output string "Jarak = " ke monitor serial
    Serial.print(distance);   // Output jarak saat ini ke monitor serial
    Serial.println(" cm menjauh"); // Output string " cm menjauh" ke monitor serial diikuti dengan baris baru
  }

  previewDistance = distance; // Memperbarui jarak sebelumnya dengan jarak saat ini untuk iterasi berikutnya
}
