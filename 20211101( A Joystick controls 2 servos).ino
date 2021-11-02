#include <Servo.h>
Servo 你的班級學號_Servo1;
Servo 你的班級學號_Servo2;
int angle1 = 0;
int angle2 = 0;

void setup() {
  Serial.begin(9600);
  delay(1000);
  pinMode(A2, INPUT_PULLUP);
  你的班級學號_Servo1.attach(A4); //check the pin if u use wokwi
  你的班級學號_Servo2.attach(A3); //check the pin if u use wokwi
}

void loop() {
  Serial.print("x-axis: "); Serial.print(analogRead(A0)); Serial.print(" ");
  Serial.print("y-axis: "); Serial.print(analogRead(A1)); Serial.print(" ");
  Serial.print("Switch: "); Serial.print(digitalRead(A2)); Serial.print(" ");
  Serial.println();
  if (digitalRead(A2) == 0) {
    angle1 = 90; 你的班級學號_Servo1.write(angle1);
    angle2 = 90; 你的班級學號_Servo2.write(angle2);
  }
  else {
    if (analogRead(A0) > 551) {
      angle1 = angle1 + 10 ; 
      你的班級學號_Servo1.write(angle1);
    }
    if (analogRead(A0) < 491) {
      angle1 = angle1 - 10; 
      你的班級學號_Servo1.write(angle1);
    }
    if (analogRead(A1) > 551) {
      angle2 = angle2 + 10 ; 
      你的班級學號_Servo2.write(angle2);
    }
    if (analogRead(A1) < 491) {
      angle2 = angle2 - 10; 
      你的班級學號_Servo2.write(angle2);
    }
  }
  delay(100);
}
