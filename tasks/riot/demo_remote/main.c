#include <stdio.h>

#include "shell.h"
#include "msg.h"

#include "board.h"
#include "periph/gpio.h"
#include "xtimer.h"

#define MAIN_QUEUE_SIZE     (8)
static msg_t _main_msg_queue[MAIN_QUEUE_SIZE];

extern int udp_cmd(int argc, char **argv);

static const shell_command_t shell_commands[] = {
    { "udp", "send data over UDP and listen on UDP ports", udp_cmd },
    { NULL, NULL, NULL }
};

static void cb(void *arg)
{
    (void) arg;
    puts("Pressed BTN");

    int argc = 5;
    char * argv[5];
    argv[0] = NULL;
    argv[1] = "send";
    argv[2] = "ff02::1";//multicast on link-local all nodes
    argv[3] = "8808";
    argv[4] = "Hello";
    udp_cmd(argc, argv);
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

    /* we need a message queue for the thread running the shell in order to
     * receive potentially fast incoming networking packets */
    msg_init_queue(_main_msg_queue, MAIN_QUEUE_SIZE);
    puts("RIOT network stack example application");

    /* start shell */
    puts("All up, running the shell now");
    char line_buf[SHELL_DEFAULT_BUFSIZE];
    shell_run(shell_commands, line_buf, SHELL_DEFAULT_BUFSIZE);

    /* should be never reached */
    return 0;
}
