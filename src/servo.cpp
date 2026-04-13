#include "defines.h"



Servo::Servo(int servoNum){
    this->_servoNum = servoNum;
}
void Servo::setAngle(int angle){
    int pulseLength = map(angle, 0, 180, SERVO_MIN, SERVO_MAX);
    pwm.setPWM(_servoNum, 0, pulseLength);
    this->_currentAngle = angle;
}

int Servo::getAngle(){
    return this->_currentAngle;
}

void Servo::setAngleSlow(int angle, int delayTime){
    int currentAngle = _currentAngle;
    int step;
    if (angle > currentAngle) {
        step = 1; // Move up
    } else {
        step = -1; // Move down
    }
    for (int a = currentAngle; a != angle; a += step) {
        setAngle(a);
        delay(delayTime);
    }
    setAngle(angle); // Ensure final position is set
    _currentAngle = angle; // Update current angle
}