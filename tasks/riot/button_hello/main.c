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
#include "periph_conf.h"

static void hello(void *arg)
{
    (void) arg;
    puts("Hello World!");

    printf("You are running RIOT on a(n) %s board.\n", RIOT_BOARD);
    printf("This board features a(n) %s MCU.\n", RIOT_MCU);
}

int main(void)
{
    if (gpio_init_int(BTN0_PIN, BTN0_MODE, GPIO_FALLING, hello, NULL) != 0) {
        puts("[FAILED] init BTN0!");
        return 1;
    }

    puts("On-board button test\n");
    puts(" -- Try pressing button to test.\n");
}
