#define BLYNK_TEMPLATE_ID "TMPL6W560igJt"
#define BLYNK_TEMPLATE_NAME "ESP32 DHT22"
#define BLYNK_AUTH_TOKEN "C4dTlr9_qdfBAefvws3TH9J7_5hcfhP5"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#define DHTPIN 15
#define DHTTYPE DHT22
DHT dht (DHTPIN, DHTTYPE);

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

BlynkTimer timer;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("SISTEM MONITORING SUHU");
  dht.begin();
  Blynk.begin(auth, ssid,pass);
}

void loop() {
  // put your main code here, to run repeatedly:
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  delay (1000);

  Blynk.virtualWrite(V0,t);
  Blynk.virtualWrite(V1,h);

  Serial.println("suhu = ");
  Serial.print(t);
  Serial.println("kelembapan = ");
  Serial.print(h);
}