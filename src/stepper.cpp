#include <defines.h>

StepperManager::StepperManager() {
  steppers[0] = new AccelStepper(1, X_STEP, X_DIR);
  steppers[1] = new AccelStepper(1, Y_STEP, Y_DIR);
  steppers[2] = new AccelStepper(1, Z_STEP, Z_DIR);
  steppers[3] = new AccelStepper(1, A_STEP, A_DIR);
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

void StepperManager::moveStepper(int stepperNum, long steps) {
  int index = stepperNum - 1; // Convert to 0-based index

  if (index >= 0 && index < 4) {
    steppers[index]->move(steps);
  }
}

void StepperManager::update() {
  for (int i = 0; i < 4; i++) {
    steppers[i]->run();
  }
}