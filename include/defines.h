#ifndef DEFINES_H
#define DEFINES_H   

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <AccelStepper.h>

#define SERVO_MIN 125 // this is the 'minimum' pulse length count (out of 4096)
#define SERVO_MAX 575 // this is the 'maximum' pulse length count (out of 4096)
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

class Servo {
  public:
    Servo(int servoNumber);
    void setAngle(int angle);
    int getAngle();
    void setAngleSlow(int angle, int delayTime);
  private:
    int _servoNum;
    int _currentAngle;
};

class StepperManager {
  public:
    StepperManager();
    ~StepperManager();

    void begin(float maxSpeed = 1000.0, float acceleration = 500.0);
    void configureStepper(int stepperNum, float gearRatio = 1.0, float stepsPerRevolution = 3200.0);
    void setAngle(int stepperNum, float angleDegrees);
    void moveAngle(int stepperNum, float angleDegrees);
    float getAngle(int stepperNum);
    void update();
  private:
    static const int ENALE_PIN = 8;
    static const int X_STEP = 2; static const int X_DIR = 5;
    static const int Y_STEP = 3; static const int Y_DIR = 6;
    static const int Z_STEP = 4; static const int Z_DIR = 7;
    static const int A_STEP = 12; static const int A_DIR = 13;

    AccelStepper* steppers[4];
    float gearRatios[4];
    float stepsPerRev[4];

    long degreesToSteps(int index, float degrees);
    float stepsToDegrees(int index, long steps);
};

extern Adafruit_PWMServoDriver pwm;
extern Servo servo1;
extern Servo servo2;  
extern Servo servo3;
extern Servo servo4;
extern Servo servoList[4];
#endif