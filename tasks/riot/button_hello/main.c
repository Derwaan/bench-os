/*
 * Copyright (C) 2014 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

#include <stdio.h>

#include "board.h"
#include "periph/gpio.h"

static void handler(void *arg)
{
    (void) arg;
    if (gpio_read(GPIO_PIN(PORT_C, 3)) > 0) {
        gpio_set(GPIO_PIN(PORT_C, 2));
        puts("Hello World!");
    }
    else {
        gpio_clear(GPIO_PIN(PORT_C, 2));
        puts("Cleared!");
    }
}

int main(void)
{
    if (gpio_init_int(GPIO_PIN(PORT_C, 3), GPIO_IN_PD, GPIO_BOTH, handler, NULL) != 0) {
        puts("[FAILED] init IRQ");
        return 1;
    }

    if (gpio_init(GPIO_PIN(PORT_C, 2), GPIO_OUT) != 0) {
        puts("[FAILED] init A0");
        return 1;
    }
}
