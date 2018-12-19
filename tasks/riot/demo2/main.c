#include <stdio.h>
#include <string.h>

#include "msg.h"
#include "shell.h"

#include "board.h"
#include "periph/gpio.h"
#include "xtimer.h"
#include "thread.h"
#include "bench_context_switching.h"

#define THREAD_IDLE 2
char thread_idle_stack[THREAD_STACKSIZE_MAIN];

#define MAIN_QUEUE_SIZE     (8)
static msg_t _main_msg_queue[MAIN_QUEUE_SIZE];

extern int udp_send(int argc, char **argv);
extern int udp_server(int argc, char **argv);

void *thread_idle(void *arg)
{
    (void) arg;

    while(1){
        bench_ping(THREAD_IDLE);
        // Do nothing
    }
    return NULL;
}

static void cb(void *arg)
{
    (void) arg;
    puts("Pressed BTN");

    int argc = 4;
    char * argv[4];
    argv[0] = NULL;
    //argv[1] = "udp";
    argv[1] = "ff02::1";//multicast on link-local all nodes
    argv[2] = "8808";
    argv[3] = "Hello";
    udp_send(argc, argv);
}

static const shell_command_t shell_commands[] = {
    { "udp", "send udp packets", udp_send },
    { "udps", "start udp server", udp_server },
    { NULL, NULL, NULL }
};

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

    /**
     * Fake idle thread with prio 14
     **/
    thread_create(thread_idle_stack, sizeof(thread_idle_stack),
                14, THREAD_CREATE_WOUT_YIELD,
                thread_idle, NULL, "thread_idle");

    msg_init_queue(_main_msg_queue, MAIN_QUEUE_SIZE);

    char line_buf[SHELL_DEFAULT_BUFSIZE];
    shell_run(shell_commands, line_buf, SHELL_DEFAULT_BUFSIZE);

    return 0;
}
