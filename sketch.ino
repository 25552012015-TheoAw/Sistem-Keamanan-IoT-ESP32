#define BLYNK_TEMPLATE_ID "TMPL6FFEHrdCt"
#define BLYNK_TEMPLATE_NAME "Sistem Keamanan"
#define BLYNK_AUTH_TOKEN "YOUR_TOKEN_HERE"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Wokwi-GUEST"; 
char pass[] = "";

const int pirPin = 13;
const int ledPin = 2;
const int buzzerPin = 15;

void setup() {
  Serial.begin(115200); // Tambahkan Serial agar bisa memantau status koneksi
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Perbaikan di sini: Gunakan BLYNK_AUTH_TOKEN
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();
  
  int pirStatus = digitalRead(pirPin);
  
  if (pirStatus == HIGH) {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000); 
    
    // Pastikan Event Code di Blynk Console adalah "alarm_keamanan"
    Blynk.logEvent("alarm_keamanan", "PERINGATAN: Ada gerakan terdeteksi di rumah!");
    Blynk.virtualWrite(V1, 1); 
    
    delay(3000); 
  } else {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
    Blynk.virtualWrite(V1, 0);
  }
}