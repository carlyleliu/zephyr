/*
 * @Autor: carlyleliu
 * @Version: 1.0
 * @Date: 2022-06-26 15:06:19
 * @LastEditors: carlyleliu
 * @LastEditTime: 2022-07-01 23:09:47
 * @Description:
 * Copyright (C) 2022 carlyleliu. All rights reserved.
 */

#include <pwm.hpp>

#define PWM_INSTANCE_NUM    2
#define PWM_CHANNEL_NUM     4

#define DT_NODE_PWM1 DT_NODELABEL(pwm1)
#define DT_NODE_PWM8 DT_NODELABEL(pwm8)

const struct device *kPwm1Device = DEVICE_DT_GET(DT_NODE_PWM1);
const struct device *kPwm8Device = DEVICE_DT_GET(DT_NODE_PWM8);

/* pwm device map */

static struct pwm_dt_spec kPwmChannelSpec[PWM_INSTANCE_NUM][PWM_CHANNEL_NUM] =
{
    {
        PWM_DT_SPEC_GET_BY_NAME(DT_NODELABEL(pwm1_spec), channel_1),
        PWM_DT_SPEC_GET_BY_NAME(DT_NODELABEL(pwm1_spec), channel_2),
        PWM_DT_SPEC_GET_BY_NAME(DT_NODELABEL(pwm1_spec), channel_3),
        PWM_DT_SPEC_GET_BY_NAME(DT_NODELABEL(pwm1_spec), channel_4),
    },
    {
        PWM_DT_SPEC_GET_BY_NAME(DT_NODELABEL(pwm8_spec), channel_1),
        PWM_DT_SPEC_GET_BY_NAME(DT_NODELABEL(pwm8_spec), channel_2),
        PWM_DT_SPEC_GET_BY_NAME(DT_NODELABEL(pwm8_spec), channel_3),
        PWM_DT_SPEC_GET_BY_NAME(DT_NODELABEL(pwm8_spec), channel_4),
    }

};


PWM::PWM()
{

}

PWM::~PWM()
{

}

PWM::PWM(uint8_t pwm):
    mPwmNum(pwm),
    mInited(0)
{
    if (mPwmNum > PWM_INSTANCE_NUM)
    {
        printk("Not support pwm instance %d\n", mPwmNum);
        return;
    }

    mSpecPtr = kPwmChannelSpec[mPwmNum];
    mNumChannel = sizeof(kPwmChannelSpec[mPwmNum]) / sizeof(struct pwm_dt_spec);

    printk("pwm %d have %d channel\n", mPwmNum, mNumChannel);

    if (!device_is_ready(mSpecPtr[0].dev)) {
        printk("Device not ready\n");
        return;
    }
    mInited = 1;
}

int PWM::init(void)
{
    if (!mInited) {
        return -1;
    }

    for (int i = 0; i < mNumChannel; i++) {
        pwm_set_cycles(mSpecPtr[i].dev, mSpecPtr[i].channel, mSpecPtr[i].period,  mSpecPtr[i].period, mSpecPtr[i].flags);
    }

    return 0;
}

int PWM::setDutyCycle(float duty_cycle, uint8_t channel)
{
    if (duty_cycle >= 0 &&  duty_cycle <= 1 && channel < mNumChannel) {
        pwm_set_cycles(mSpecPtr[channel].dev, mSpecPtr[channel].channel, mSpecPtr[channel].period,  (int)mSpecPtr[channel].period * duty_cycle, mSpecPtr[channel].flags);
        return 0;
    } else {
        return -1;
    }
}
