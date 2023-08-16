#include <MakerKit.h>
#include <ESP32Servo.h>

#define BLYNK_TEMPLATE_ID           "TMPL6_an-BYPo"
#define BLYNK_DEVICE_NAME           "IoT"
#define BLYNK_AUTH_TOKEN            "64BoDZugkqZ_wvyaMYcQRQKX1mzXjJKU"


#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "Deeba iPhone";
char pass[] = "dee100884";
#include <Adafruit_NeoPixel.h>
 Adafruit_NeoPixel pixels = Adafruit_NeoPixel(5, 4, NEO_GRB + NEO_KHZ800);

BLYNK_WRITE(V2)
{
int pinValue = param.asInt();
  if (pinValue == 1) {

    pixels.setPixelColor(1, 0xcc0000);
    pixels.setPixelColor(2, 0xcc0000);
    pixels.setPixelColor(3, 0xcc0000);
    pixels.setPixelColor(4, 0xcc0000);
    servo1();
    servo2();

  }
}

BLYNK_WRITE(V1)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    pixels.setPixelColor(0, 0x000099);
    pixels.setPixelColor(1, 0x000099);
    pixels.setPixelColor(2, 0x000099);
    pixels.setPixelColor(3, 0x000099);
    pixels.setPixelColor(4, 0x000099);
    pixels.show();
    pixels.show();

  }
}

BlynkTimer Timer1;

void Timer1_TimerEvent()
{
  Blynk.virtualWrite(V2, analogRead(39));
  Blynk.virtualWrite(V3, ultrasonic(12,27));
}

BLYNK_WRITE(V4)
{
servo;
     digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
    analogWrite(25,250);
    digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    analogWrite(15,250);

  } else {
    digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
    analogWrite(25,0);
    digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    analogWrite(15,0);

  }
}

BLYNK_WRITE(V5)
{
int pinValue = param.asInt();
  if (pinValue == 1) {

  } else {
    digitalWrite(13,LOW);
    digitalWrite(14,HIGH);
    analogWrite(25,0);
    digitalWrite(18,LOW);
    digitalWrite(19,HIGH);
    analogWrite(15,0);
    digitalWrite(13,LOW);
    digitalWrite(14,HIGH);
    analogWrite(25,250);
    digitalWrite(18,LOW);
    digitalWrite(19,HIGH);
    analogWrite(15,250);

  }
}

BLYNK_WRITE(V6)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    digitalWrite(13,LOW);
    digitalWrite(14,HIGH);
    analogWrite(25,250);
    digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    analogWrite(15,250);

  } else {
    digitalWrite(13,LOW);
    analogWrite(25,0);
    digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    analogWrite(15,0);

  }
}

BLYNK_WRITE(V7)
{
  if (pinValue == 1) {
    digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
    analogWrite(25,250);

  } else {
    digitalWrite(18,LOW);
    digitalWrite(19,HIGH);
    analogWrite(15,250);
    digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
    analogWrite(25,0);
    digitalWrite(18,LOW);
    digitalWrite(19,HIGH);
    ;

  }
}

Servo servo_23;
BLYNK_WRITE(V8)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    servo_23.write(90);

  } else {

  }
}

BLYNK_WRITE(V9)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    servo_23.write(0);

  } else {

  }
}


void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
 
  pinMode(39, INPUT);
  Timer1.setInterval(300, Timer1_TimerEvent);

  pinMode(13,OUTPUT);
 pinMode(18,OUTPUT);
 pinMode(25,OUTPUT);
  pinMode(18,OUTPUT);
 pinMode(19,OUTPUT);
 pinMode(15,OUTPUT);
  servo_25.attach(25);
}

void loop() {
  Blynk.run();
  Timer1.run();
}