/*
 * @Autor: carlyleliu
 * @Version: 1.0
 * @Date: 2022-06-26 15:06:11
 * @LastEditors: carlyleliu
 * @LastEditTime: 2022-07-02 00:06:57
 * @Description:
 * Copyright (C) 2022 carlyleliu. All rights reserved.
 */

#ifndef __HAL_PWM_HPP__
#define __HAL_PWM_HPP__

#include <vector>

#include <zephyr/zephyr.h>
#include <zephyr/sys/printk.h>
#include <zephyr/device.h>
#include <zephyr/drivers/pwm.h>
#include <shell/shell.h>
#include <logging/log.h>

class PWM
{
public:
    PWM() {};
    ~PWM() {};
    PWM(uint8_t pwm);

    int initPwmDevice(void);
    int setDutyCycle(float duty_cycle, uint8_t channel);

private:
    uint8_t mPwmNum;
    uint8_t mNumChannel;
    uint8_t mInited;
    struct pwm_dt_spec* mSpecPtr;
};

#endif // !__HAL_PWM_HPP__
