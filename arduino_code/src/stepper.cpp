#include <defines.h>

StepperManager::StepperManager() {
  steppers[0] = new AccelStepper(1, X_STEP, X_DIR);
  steppers[1] = new AccelStepper(1, Y_STEP, Y_DIR);
  steppers[2] = new AccelStepper(1, Z_STEP, Z_DIR);
  steppers[3] = new AccelStepper(1, A_STEP, A_DIR);

  for (int i = 0; i < 4; i++) {
    gearRatios[i] = 1.0f;
    stepsPerRev[i] = 3200.0f;
  }
}

StepperManager::~StepperManager() {
  for (int i = 0; i < 4; i++) {
    delete steppers[i];
  }
}

void StepperManager::begin(float maxSpeed, float acceleration) {
  pinMode(ENALE_PIN, OUTPUT);
  digitalWrite(ENALE_PIN, LOW); // Enable the stepper drivers
  for (int i = 0; i < 4; i++) {
    steppers[i]->setMaxSpeed(maxSpeed);
    steppers[i]->setAcceleration(acceleration);
  }
}

void StepperManager::configureStepper(int stepperNum, float gearRatio, float stepsPerRevolution){
  int index = stepperNum - 1;
  if (index >= 0 && index < 4){
    gearRatios[index] = gearRatio;
    stepsPerRev[index] = stepsPerRevolution;
  }
}

long StepperManager::degreesToSteps(int index, float degrees){
  return round((degrees / 360.0f) * stepsPerRev[index] * gearRatios[index]);
}

float StepperManager::stepsToDegrees(int index, long steps){
  if (stepsPerRev[index] == 0.0f || gearRatios[index] == 0.0f) return 0.0f;
  return((float)steps / (stepsPerRev[index] * gearRatios[index])) * 360.0f;
}

void StepperManager::setAngle(int stepperNum, float angleDegrees){
  int index = stepperNum - 1;
  if (index >= 0 && index < 4){
    long targetSteps = degreesToSteps(index, angleDegrees);
    steppers[index]->moveTo(targetSteps);
  }
}

void StepperManager::moveAngle(int stepperNum, float angleDegrees){
  int index = stepperNum - 1;
  if (index >= 0 && index < 4){
    long relativeSteps = degreesToSteps(index, angleDegrees);
    steppers[index]->move(relativeSteps);
  }
}

float StepperManager::getAngle(int stepperNum){
  int index = stepperNum - 1;
  if (index >= 0 && index < 4){
    return stepsToDegrees(index, steppers[index]->currentPosition());
  }
}

void StepperManager::update() {
  for (int i = 0; i < 4; i++) {
    steppers[i]->run();
  }
}