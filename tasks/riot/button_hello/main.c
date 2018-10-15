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
#include "interrupt_latency.h"

static void hello(void* arg)
{
    puts(arg);
}

int main(void)
{

    /* Create the handler
     * - The callback function
     * - The arguments of the callback
     * - The input PIN
     * - The output PIN
     */
    interrupt_latency_t* handler = create_handler(hello, "Hello, World!", GPIO_PIN(PORT_C, 3), GPIO_PIN(PORT_C, 2));

    // Init the GPIO IRQ
    // Who should init this ?
    if (gpio_init_int(GPIO_PIN(PORT_C, 3), GPIO_IN_PD, GPIO_BOTH, handle, (void*) handler) != 0) {
        puts("[FAILED] init IRQ");
        return 1;
    }

    // Init the output pin
    // Who should init this ?
    if (gpio_init(GPIO_PIN(PORT_C, 2), GPIO_OUT) != 0) {
        puts("[FAILED] init A0");
        return 1;
    }
}
