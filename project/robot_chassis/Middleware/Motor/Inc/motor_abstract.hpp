/*
 * @Autor: carlyleliu
 * @Version: 1.0
 * @Date: 2022-06-25 18:05:04
 * @LastEditors: carlyleliu
 * @LastEditTime: 2022-06-26 15:07:29
 * @Description:
 * Copyright (C) 2022 carlyleliu. All rights reserved.
 */

#ifndef __MIDDLEWARE_MOTOR_MOTOR_ABSTRACR_HPP__
#define __MIDDLEWARE_MOTOR_MOTOR_ABSTRACR_HPP__

class MotorAbstract
{
  public:
    MotorAbstract();
    ~MotorAbstract();
    const double* getMotorCurrent(void) { return current; };
    uint32_t& getMotorFaultCode(void) { return mFaultCode; };
    double& getMotorAngle(void) { return mAngle; };
    double& getMotorSpeed(void) { return mSpeed; };
    double& getMotorPosition(void) { return mPosition; };
    uint32_t& getMotorStatus(void) { return mStatus; };
    double& getMotorTorque(void) { return mTorque; };
    uint8_t& getMotorType(void) { return mMotorType; };
    uint8_t& getMotorContrilType(void) { return mMotorControlType; };

    int32_t setMotorAngle(double angle)
    {
        mAngle = angle;
        this->motorParameterUpdate();
    };
    int32_t setMotorSpeed(double speed)
    {
        if (speed > mMaxSpeed)
            mSpeed = mMaxSpeed;
        else if (speed < -mMaxSpeed)
            mSpeed = -mMaxSpeed;
        else
           mSpeed = speed;
        this->motorParameterUpdate();
    };
    int32_t setMotorPosition(double position)
    {
        if (position > mMaxPosition)
            mPosition = mMaxPosition;
        else if (position < -mMaxPosition)
            mPosition = -mMaxPosition;
        else
           mPosition = position;
        this->motorParameterUpdate();
    }
    int32_t setMotorStatus(int32_t status)
    {
        mStatus = status;
        this->motorParameterUpdate();
    }
    int32_t setMotorTorque(double torque)
    {
        if (torque > mMaxTorque)
            mTorque = mMaxTorque;
        else if (torque < -mMaxTorque)
            mTorque = -mMaxTorque;
        else
           mTorque = torque;
        this->motorParameterUpdate();
    }

    virtual int32_t motorInit(void) = 0;
    virtual int32_t motorReset(void) = 0;
    virtual int32_t motorStart(void) = 0;
    virtual int32_t motorStop(void) = 0;
    virtual void motorParameterUpdate(void) = 0;
    virtual void motorEventUpdate(void) = 0;
  private:
    uint8_t mMotorType;
    uint8_t mMotorControlType;
    uint32_t mFaultCode;
    uint32_t mStatus;
    double current[3];
    double mAngle;
    double mSpeed;
    double mPosition;
    double mTorque;
    double mMaxSpeed;
    double mMaxPosition;
    double mMaxTorque;
    //class MotorControlAbstractAlgorithm* mMotorControlAlgorithmPtr;
};


#endif // !__MIDDLEWARE_MOTOR_MOTOR_ABSTRACR_HPP__
