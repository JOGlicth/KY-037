void intOled() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("OLED Initialized"));
  display.display();
  delay(1000);
}

void tampilWaktu() {
  DateTime now = rtc.now() + TimeSpan(0, 0, 0, 20);  // Ambil waktu saat ini dari RTC
  // Bersihkan buffer tampilan
  display.clearDisplay();

  // Atur ukuran teks dan warna
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  sprintf(tanggal, "%02d/%02d/%04d %02d:%02d:%02d",
          now.day(), now.month(), now.year(),
          now.hour(), now.minute(), now.second());
  display.setCursor(10, 0);  // Atur posisi kursor
  display.println(tanggal);
  // Tampilkan semua di layar
  display.display();
}

void tampilkanSuara() {
  int soundValue = analogRead(soundSensorPin);  // Membaca nilai dari sensor suara
  display.setTextSize(1, 2);                    // Ukuran teks
  display.setTextColor(SSD1306_WHITE);          // Warna teks
  display.setCursor(20, 20);                    // Posisi awal teks
  display.print("Sound Level: ");
  display.println(soundValue);

  if (soundValue > noiseThreshold) {
    Serial.println("Berisik!");
    display.setTextSize(1, 2);            // Ukuran teks
    display.setTextColor(SSD1306_WHITE);  // Warna teks
    display.setCursor(20, 40);            // Posisi awal teks
    display.print("Berisik! ");

  } else if (soundValue > mediumThreshold) {
    Serial.println("Medium...");
    display.setTextSize(1, 2);            // Ukuran teks
    display.setTextColor(SSD1306_WHITE);  // Warna teks
    display.setCursor(20, 40);            // Posisi awal teks
    display.print("Medium... ");

  } else {
    Serial.println("Senyap...");
    display.setTextSize(1, 2);            // Ukuran teks
    display.setTextColor(SSD1306_WHITE);  // Warna teks
    display.setCursor(20, 40);            // Posisi awal teks
    display.print("Senyap... ");
  }
  display.display();  // Tampilkan di OLED
  delay(1000);        // Delay untuk stabilitas pembacaan sensor
}

void myTeam() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);  //                                                         //
  display.setCursor(0, 0);
  display.println(F("Jonathan C Daniel"));
  display.setCursor(0, 15);  //
  display.println(F("Said Muhammad Irham"));
  display.setCursor(0, 30);
  display.println(F("Elyas Mahardika Putra"));  //
  display.display();                            //
  delay(2500);
}

void logo() {
 display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.drawBitmap(0, 0, myBitmap, 128, 64, 1);
  display.display();
  delay(2000);
  display.clearDisplay();
  display.setTextSize(2);               //
  display.setTextColor(SSD1306_WHITE);  //
  display.setCursor( 25, 0);             //
  display.println(F("DLOGGER"));
  display.setCursor(25, 20);
  display.println(F("OCHOBOT"));  //
  display.display();              //
  delay(2000);                    //
}