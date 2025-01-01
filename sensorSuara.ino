void sensorSuara(){
 int soundValue = analogRead(soundSensorPin);  // Membaca nilai dari sensor suara

  // Menampilkan nilai suara di Serial Monitor
  Serial.print("Sound Level: ");
  Serial.println(soundValue);

  // Mengecek tingkat suara
  if (soundValue >= noiseThreshold) {
    Serial.println("Berisik!");
  } else if (soundValue > mediumThreshold) {
    Serial.println("Medium...");
  } else {
    Serial.println("Senyap...");
  }

  delay(1000);  // Delay untuk stabilisasi pembacaan
}