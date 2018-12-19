#include <stdio.h>
#include <string.h>

#include "msg.h"
#include "shell.h"

#include "board.h"
#include "periph/gpio.h"
#include "xtimer.h"
#include "thread.h"
#include "bench_context_switching.h"

#define THREAD_IDLE 2 // TODO Use PID

#define MAIN_QUEUE_SIZE     (8)
static msg_t _main_msg_queue[MAIN_QUEUE_SIZE];

extern int udp_send(char* addr, char* port, char* payload);
extern int udp_server(char *port);

static void cb(void *arg)
{
    (void) arg;
    // Send Hello to broadcast
    udp_send("ff02::1", "8808", "Hello");
}

int main(void)
{
    /**
     * Init the buttons to trigger the framework
     **/
    if (gpio_init_int(BTN0_PIN, BTN0_MODE, GPIO_FALLING, cb, NULL) != 0) {
        puts("[FAILED] init BTN0!");
        return 1;
    }
    puts("[SUCCESS] Button initialized!");

    msg_init_queue(_main_msg_queue, MAIN_QUEUE_SIZE);

    udp_server("8808");

    while (1) {
        // Do nothing
        bench_ping(THREAD_IDLE);
    }

    return 0;
}
