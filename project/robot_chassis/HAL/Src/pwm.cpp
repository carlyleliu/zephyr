/*
 * @Autor: carlyleliu
 * @Version: 1.0
 * @Date: 2022-06-26 15:06:19
 * @LastEditors: carlyleliu
 * @LastEditTime: 2022-07-02 17:14:05
 * @Description:
 * Copyright (C) 2022 carlyleliu. All rights reserved.
 */

#include <pwm.hpp>

#define PWM_INSTANCE_NUM    2
#define PWM_CHANNEL_NUM     4

// #define DT_NODE_PWM1 DT_NODELABEL(pwm1)
// #define DT_NODE_PWM8 DT_NODELABEL(pwm8)
// const struct device *kPwm1Device = DEVICE_DT_GET(DT_NODE_PWM1);
// const struct device *kPwm8Device = DEVICE_DT_GET(DT_NODE_PWM8);

LOG_MODULE_REGISTER(HalPwm, LOG_LEVEL_DBG);

static struct pwm_dt_spec kPwmChannelSpec[PWM_INSTANCE_NUM][PWM_CHANNEL_NUM] =
{
    {
        PWM_DT_SPEC_GET_BY_NAME(DT_NODELABEL(pwm_spec), pwm1_ch1),
        PWM_DT_SPEC_GET_BY_NAME(DT_NODELABEL(pwm_spec), pwm1_ch2),
        PWM_DT_SPEC_GET_BY_NAME(DT_NODELABEL(pwm_spec), pwm1_ch3),
        PWM_DT_SPEC_GET_BY_NAME(DT_NODELABEL(pwm_spec), pwm1_ch4),
    },
    {
        PWM_DT_SPEC_GET_BY_NAME(DT_NODELABEL(pwm_spec), pwm8_ch1),
        PWM_DT_SPEC_GET_BY_NAME(DT_NODELABEL(pwm_spec), pwm8_ch2),
        PWM_DT_SPEC_GET_BY_NAME(DT_NODELABEL(pwm_spec), pwm8_ch3),
        PWM_DT_SPEC_GET_BY_NAME(DT_NODELABEL(pwm_spec), pwm8_ch4),
    }

};

PWM::PWM(uint8_t pwm):
    mPwmNum(pwm),
    mInited(0)
{
    if (mPwmNum > PWM_INSTANCE_NUM)
    {
        LOG_ERR("Not Support pwm%d Instance\n", mPwmNum);
        return;
    }

    mSpecPtr = kPwmChannelSpec[mPwmNum];
    mNumChannel = sizeof(kPwmChannelSpec[mPwmNum]) / sizeof(struct pwm_dt_spec);

    LOG_DBG("Pwm %d support %d channels\n", mPwmNum, mNumChannel);

    if (!device_is_ready(mSpecPtr[mPwmNum].dev)) {
        LOG_ERR("Device not ready\n");
        return;
    }

    mInited = 1;
}

int PWM::initPwmDevice(void)
{
    if (!mInited) {
        return -ENODEV;
    }

    for (int i = 0; i < mNumChannel; i++) {
        // pwm_set_cycles(mSpecPtr[i].dev, mSpecPtr[i].channel, mSpecPtr[i].period,  mSpecPtr[i].period, mSpecPtr[i].flags);
        pwm_set_pulse_dt(&mSpecPtr[i], 0);
    }

    return errno;
}

int PWM::setDutyCycle(float duty_ratio, uint8_t channel)
{
    if (!mInited) {
        return -ENODEV;
    }

    if (duty_ratio >= 0 &&  duty_ratio <= 1 && channel <= mNumChannel) {
        int duty_cycle = (int)mSpecPtr[channel].period * duty_ratio;
        // pwm_set_cycles(mSpecPtr[channel].dev, mSpecPtr[channel].channel, mSpecPtr[channel].period, duty_cycle, mSpecPtr[channel].flags);
        pwm_set_pulse_dt(&mSpecPtr[channel], duty_cycle);
        return errno;
    } else {
        return -EINVAL;
    }
}

