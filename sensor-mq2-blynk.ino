#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#define BLYNK_PRINT Serial    

char auth[] = "IMUhET3vjIHx0zl88waqs-30Uoxb2xXI"; 

char ssid[] = "TDN200"; 
char pass[] = "isptdn200@@"; 

WidgetLED led1(V1);
BlynkTimer timer;
 
int mq2 = A0; 
int data = 0; 
int lamp = D0;
const int fan = D1;

void setup(){
  Serial.begin(115200);
  pinMode(lamp, OUTPUT);
  pinMode(fan, OUTPUT);
  Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8080);
  timer.setInterval(1000L, getSendData);
  Blynk.syncAll();
}
 
void loop(){
  Blynk.run();
  timer.run(); 
}
 
void getSendData(){
data = analogRead(mq2); 
  Blynk.virtualWrite(V2, data);
  Blynk.virtualWrite(V1, data);
  if (data > 700 ){
    Blynk.notify("Smoke Detected!"); 
  }
}
