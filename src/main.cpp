#include <Arduino.h>
#include "defines.h"
// put function declarations here:

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
Servo servo1(4);
Servo servo2(5);  
Servo servo3(6);
Servo servo4(7);
Servo servoList[4] = {servo1, servo2, servo3, servo4};


void setup() {
  // put your setup code here, to run once:
  

  pwm.begin();
  pwm.setPWMFreq(SERVO_FREQ); // Analog servos run at ~50 Hz
}

void loop() {
  // put your main code here, to run repeatedly:
  servo2.setAngleSlow(0, 20);
  delay(1000);
  servo2.setAngleSlow(90, 20);
  delay(1000);
  //servo2.setAngleSlow(0, 20);
  //delay(1000);
  //servo2.setAngleSlow(180, 20);
  //delay(1000);
}

// put function definitions here:
