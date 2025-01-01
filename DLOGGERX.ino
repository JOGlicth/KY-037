#include <SD.h>                //Library Micro SD
#include <FS.h>                //Library Micro SD
#include <Wire.h>              //Library komunikasi I2C
#include "variabel.h"          // variabel data tanggal
#include <RTClib.h>
#include <Adafruit_GFX.h>      //Library mengelolah tampilan Oled
#include <Adafruit_SSD1306.h>  //Library mengelolah tampilan Oled

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
#define LOGO_HEIGHT   128
#define LOGO_WIDTH    64
RTC_DS3231 rtc;  //Objek RTC
File myFile;     //Objek MICRO SD

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
const int soundSensorPin = 39;  // VP (A0) pada ESP32
 int soundValue = analogRead(soundSensorPin);  // Membaca nilai dari sensor suara

// Batasan nilai volume untuk menentukan tingkat suara
const int mediumThreshold = 125; // Batas untuk suara tingkat "Medium"
const int noiseThreshold = 130;  // Batas untuk suara tingkat "Berisik"


void setup() {
  Serial.begin(115200);
 intOled();
  logo();
  intRtc();
  myTeam();
 intMicroSD();
  ambilWaktu();
   tampilWaktu();
 // simpanDatawaktu();
  //ambilDatawaktu();
  //sensorSuara();
 
 
  //tampilkanSuara();
}

void loop() {
 // ambilWaktu();
  simpanDatawaktu();
 //ambilDatawaktu();
 // sensorSuara();
  tampilWaktu();
  tampilkanSuara();
  delay(500);
}