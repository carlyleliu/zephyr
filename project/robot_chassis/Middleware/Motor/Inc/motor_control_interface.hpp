/*
 * @Autor: carlyleliu
 * @Version: 1.0
 * @Date: 2022-06-26 10:25:08
 * @LastEditors: carlyleliu
 * @LastEditTime: 2022-06-26 15:07:35
 * @Description:
 * Copyright (C) 2022 carlyleliu. All rights reserved.
 */

#ifndef __MIDDLEWARE_MOTOR_MOTOR_CONTROL_INTERFACE__
#define __MIDDLEWARE_MOTOR_MOTOR_CONTROL_INTERFACE__

class MotorAbstract;

class MotorControlInterface
{
  public:
    MotorControlInterface();
    ~MotorControlInterface();

  private:
  class MotorAbstract* mMotorPtr;
};


#endif // !__MIDDLEWARE_MOTOR_MOTOR_CONTROL_INTERFACE__
