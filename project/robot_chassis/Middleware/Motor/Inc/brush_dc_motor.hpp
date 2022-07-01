/*
 * @Autor: carlyleliu
 * @Version: 1.0
 * @Date: 2022-06-26 12:46:49
 * @LastEditors: carlyleliu
 * @LastEditTime: 2022-06-26 15:06:59
 * @Description:
 * Copyright (C) 2022 carlyleliu. All rights reserved.
 */

#ifndef __MIDDLEWARE_MOTOR_BRUSH_DC_MOTOR_HPP__
#define __MIDDLEWARE_MOTOR_BRUSH_DC_MOTOR_HPP__

class MotorAbstract;

class BrushDCMotor : public MotorAbstract
{
  public:
    BrushDCMotor();
    ~BrushDCMotor();
    int32_t motorInit(void);
    int32_t motorReset(void);
    int32_t motorStart(void);
    int32_t motorStop(void);
    void motorParameterUpdate(void);
    void motorEventUpdate(void);
};



#endif // !__MIDDLEWARE_MOTOR_BRUSH_DC_MOTOR_HPP__
