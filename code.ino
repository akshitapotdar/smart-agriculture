include < 10Xhop_FirebaseESP32.h>
#include <Wire.h>
#include <LiquidCrystal_12C_Hangul.h>
LiquidCrystal_I2C_Hangul led(0x27, 16, 2);
#include "DHT.h"
const int DHTPIN = 14;
const int phpin = 33;
#define DHTTYPE DHT11
DHT dht (DHTPIN, DHTTYPE);
float t; int h;
float calibration value = 20.24 - 0.7;;
int phval = 0;
unsigned long int avgval; int buffer _arr[10], temp;
#define FIREBASE HOST "agriculture-800af-default-db.firebaseio.com"
// the project name address from firebase id
#define FIREBASE
#define WIFI SSID "VARSHITHA"
3_AUTH "F60qMU5081eadDxb9ZBMFolI4ViaR91kFvENXTX"
#define WIFI PASSWORD "1234567890"
void setup(void)
{
Serial.begin(115200);
Serial.printin("WELCOME");
WiFi.begin(WIFI_SSID, WIFI PASSWORD);
Serial. print("connecting");
while (WiFi.status |= WL_CONNECTED)
Serial. print(".");
delay(500);
delay (200);
Serial.printInO;
Serial print("connected: ");
Serial.printIn(WiFi.localIPO);
delay(500);
Firebase. begin(FIREBASE_ HOST, FIREBASE_AUTH);
delay(4000);
Icd.init;
Ied. begin(16, 2); lcd.backlightO;
Icd.setCursor(0, 0);
Ied. print(" WELCOME ");
dht. begin;
void dhtread
[11:31 PM, 6/9/2024] Akshita: {
h= dht.readHumidity0;
Serial.print("Humidity:");
Serial.printin(h);
Firebase.setFloat("Humidity", h);
delay(200);
if (h>85)
Serial.print("Humidity HIGH");
delay(200);
Firebase.setFloat("Humidityflag", 1);
delay(200);
Firebase.setFloat("Humidityflag", 0);
delay(200);
}
t = dht.readTemperature;
Serial. print("Temperature:");
Serial.printIn(t);
Firebase.setFloat("Temperature", t);
delay(200);
Icd.clear;
Icd.setCursor(0, 0);
lcd.print("T:");
Icd.setCursor(4, 0);
lcd.print(t);
Icd.setCursor(8, 0);
Icd. print("H;");
Icd. setCursor(12, 0);
led.print(t);
[11:32 PM, 6/9/2024] Akshita: void readph10
{
int pH_Value = analogRead(phpin);
float Voltage = pH_Value * (3.3 / 1023.0);
Serial.printIn(Voltage);
delay(100);
Icd.clear;
Icd.set Cursor(0, 1);
Icd.print("pH Val:");
Ied.set Cursor(8, 1); lcd.print(Voltage);
SeriaL.printIn("PH Value:");
Serial printin(Voltage);
Firebase.setFloat"PhVal", Voltage);
delay(500);
｝
void loop
{
dhtread®;
readph10;
}
