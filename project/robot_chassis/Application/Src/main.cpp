/*
 * Copyright (c) 2016 Intel Corporation
 * Copyright (c) 2020 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file Sample app to demonstrate PWM.
 */

#include <zephyr/zephyr.h>
#include <zephyr/sys/printk.h>
#include <zephyr/device.h>

#include <pwm.hpp>

/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */

void main(void)
{
	printk("system start...\n");

    class PWM pwm0(0);
    pwm0.setDutyCycle(0.5, 0);
    pwm0.setDutyCycle(0.5, 1);
    pwm0.setDutyCycle(0.5, 2);
    pwm0.setDutyCycle(0.5, 3);


	while (1) {
		k_msleep(1);
	}
}
