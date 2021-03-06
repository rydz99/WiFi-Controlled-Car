/*****

created 1 Aug 2021
modified 3 Aug 2021
by rydz99

program requires Blynk and ESP8266 libraries

*****/
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
//motor A
#define enA D1 
#define IN1 D2 
#define IN2 D3 
//motor B
#define IN3 D8
#define IN4 D5 
#define enB D6
char auth[] = "-------";  //Blynk Token
char ssid[] = "-------";           //WiFi Name
char pass[] = "-------";           //WiFi Password
BlynkTimer timer;

void motorSpeed(int speedA, int in1, int in2, int speedB, int in3, int in4) {
 analogWrite(enA,speedA);
 digitalWrite(IN1,in1);
 digitalWrite(IN2,in2);
 analogWrite(enB,speedB);
 digitalWrite(IN3,in3);
 digitalWrite(IN4,in4);
}
BLYNK_WRITE(V1) {
 int x = param[0].asInt();
 int y = param[1].asInt();

//stop
if ((x==0) && (y==0)) {
  motorSpeed(0,LOW,LOW,0,LOW,LOW); 
}
//forward
else if (((x>=-2) && (x<=2)) && (y>0)) {
 if (y==1){ motorSpeed(60,HIGH,LOW,60,HIGH,LOW); }
 else if (y==2){ motorSpeed(75,HIGH,LOW,75,HIGH,LOW); }
 else if (y==3){ motorSpeed(100,HIGH,LOW,100,HIGH,LOW); }
 else if (y==4){ motorSpeed(125,HIGH,LOW,125,HIGH,LOW); }
 else if (y==5){ motorSpeed(160,HIGH,LOW,160,HIGH,LOW); }
}
//backward
else if (((x>=-2) && (x<=2)) && (y<0)) {
 if (y==-1){ motorSpeed(60,LOW,HIGH,60,LOW,HIGH); }
 else if (y==-2){ motorSpeed(75,LOW,HIGH,75,LOW,HIGH); }
 else if (y==-3){ motorSpeed(100,LOW,HIGH,100,LOW,HIGH); }
 else if (y==-4){ motorSpeed(125,LOW,HIGH,125,LOW,HIGH); }
 else if (y==-5){ motorSpeed(160,LOW,HIGH,160,LOW,HIGH); }
}
//left
else if (((y<=2) && (y>=-2)) && (x<0)) {
 if (x==-1){ motorSpeed(0,HIGH,LOW,50,HIGH,LOW); }
 else if (x==-2){ motorSpeed(0,HIGH,LOW,75,HIGH,LOW); }
 else if (x==-3){ motorSpeed(0,HIGH,LOW,100,HIGH,LOW); }
 else if (x==-4){ motorSpeed(0,HIGH,LOW,125,HIGH,LOW); }
 else if (x==-5){ motorSpeed(0,HIGH,LOW,160,HIGH,LOW); }
}
//right
else if (((y<=2) && (y>=-2 )) && (x>0)) {
 if (x==1){motorSpeed(50,HIGH,LOW,0,HIGH,LOW); }
 else if (x==2){ motorSpeed(75,HIGH,LOW,0,HIGH,LOW); }
 else if (x==3){ motorSpeed(100,HIGH,LOW,0,HIGH,LOW); }
 else if (x==4){ motorSpeed(125,HIGH,LOW,0,HIGH,LOW); }
 else if (x==5){ motorSpeed(160,HIGH,LOW,0,HIGH,LOW); } 
}
}
void setup() {
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  Blynk.begin(auth, ssid, pass);
}
void loop() {
  Blynk.run();
  timer.run();
}
