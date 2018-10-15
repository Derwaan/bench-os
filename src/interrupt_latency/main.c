/*
 * Copyright (C) 2014 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

#include <stdio.h>
#include <stdint.h>

#include "board.h"
#include "xtimer.h"
#include "periph/gpio.h"

xtimer_ticks32_t timer;

static void launch(void *arg)
{
    (void) arg;
    puts("Launched!");
    // Start the timer
    timer = xtimer_now();

    // Output the pin C0
    gpio_set(GPIO_PIN(PORT_C, 0));
    
}

static void fired(void *arg)
{
    (void) arg;
    if (gpio_read(GPIO_PIN(PORT_C, 3)) == 0) return;

    puts("Fired!");
    // Clear the pin C0
    gpio_clear(GPIO_PIN(PORT_C, 0));
    // Compute the difference
    xtimer_ticks32_t diff = xtimer_diff(xtimer_now(), timer);
    printf("%lu\n", xtimer_usec_from_ticks(diff));
}

int main(void)
{
    if (gpio_init_int(BTN0_PIN, BTN0_MODE, GPIO_FALLING, launch, NULL) != 0) {
        puts("[FAILED] init IRQ for BTN0");
        return 1;
    }

    if (gpio_init_int(GPIO_PIN(PORT_C, 3), GPIO_IN_PD, GPIO_RISING, fired, NULL) != 0) {
        puts("[FAILED] init IRQ for C3");
        return 1;
    }

    if (gpio_init(GPIO_PIN(PORT_C, 0), GPIO_OUT) != 0) {
        puts("[FAILED] init C0");
        return 1;
    }

    puts("On-board benchmarking\n");
    puts(" -- Press the button to start.\n");
}
