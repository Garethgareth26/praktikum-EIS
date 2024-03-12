const int sensorPin = A1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);

  Serial.print("Nilai kelembaban tanah: ");
  Serial.println(sensorValue);

   if (sensorValue >= 1000) (Serial.print("SOIL IS TOO DRY!!!!!"));
     else if ((sensorValue <= 999) && (sensorValue >=901)) (Serial.print("SOIL IS PERFECT!!!!!"));
     else if (sensorValue <= 900) (Serial.print("SOIL IS TOO WET!!!!!"));
    else;

  delay(1000);
}