#ifndef DEFINES_H
#define DEFINES_H   

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define SERVO_MIN 125 // this is the 'minimum' pulse length count (out of 4096)
#define SERVO_MAX 575 // this is the 'maximum' pulse length count (out of 4096)
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

class Servo {
  public:
    Servo(int servoNumber);
    void setAngle(int angle);
    void setAngleSlow(int angle, int delayTime);
  private:
    int _servoNum;
    int _currentAngle;
};

extern Adafruit_PWMServoDriver pwm;
extern Servo servo1;
extern Servo servo2;  
extern Servo servo3;
extern Servo servo4;
extern Servo servoList[4];
#endif