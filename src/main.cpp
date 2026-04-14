#include <Arduino.h>
#include "defines.h"
// put function declarations here:

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
Servo servoBase(4);
Servo servoShoulder(5);  
Servo servo3(6);
Servo servo4(7);
Servo servoList[4] = {servoBase, servoShoulder, servo3, servo4};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(SERVO_FREQ); // Analog servos run at ~50 Hz
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 4; i++){
    switch (i){
      case 0:
      Serial.print("Current base angle: ");
      Serial.print(servoList[i].getAngle());
      Serial.println();
      Serial.println("Set base angle (no change: -1): ");
      break;
      case 1:
      Serial.print("Current shoulder angle: ");
      Serial.print(servoList[i].getAngle());
      Serial.println();
      Serial.println("Set shoulder angle (no change: -1): ");
      break;
      default:
      Serial.print("Servo ");
      Serial.print(i);
      Serial.print(" is not used yet.");
      Serial.println();
    }
    if(i == 0 || i == 1){
      while(Serial.available() == 0){
      }
      int angle_to_set = Serial.parseInt();
      if(angle_to_set >= 0){
        servoList[i].setAngleSlow(angle_to_set, 15);
    }
    }
  }
  delay(500);
  //servo2.setAngleSlow(0, 20);
  //delay(1000);
  //servo2.setAngleSlow(180, 20);
  //delay(1000);
}

// put function definitions here:
