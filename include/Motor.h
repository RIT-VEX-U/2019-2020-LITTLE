#ifndef MOTOR_H_
#define MOTOR_H_


#define REVERSED true
#define NOT_REVERSED false
#define SLEW_ON true
#define SLEW_OFF false
#define DEFAULT_SLEW_RATE 15
#define SLEW_DELAY 25

typedef struct {
  int portNum;
  int speed;
  int requestedSpeed;
  bool reversed;
  bool slewOn;
  int slewRate;
} Motor;

Motor* motors[10];

void initMotor(Motor* motor, int port, bool reversed, bool slewOn);

Motor* getMotor(int portNum);

void setMotor(Motor* motor, int speed);

void changeMotor(Motor* motor);

void motorSlewTask(void *parameter);

#endif
