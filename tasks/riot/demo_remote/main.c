#include <stdio.h>
#include <inttypes.h>

#include "net/gnrc.h"
#include "net/gnrc/ipv6.h"
#include "net/gnrc/netif.h"
#include "net/gnrc/netif/hdr.h"
#include "net/gnrc/udp.h"
#include "net/gnrc/pktdump.h"
#include "board.h"
#include "periph/gpio.h"
#include "xtimer.h"
#include "thread.h"
#include "bench_context_switching.h"

#define THREAD_IDLE 2
#define THREAD_RCV 3

char thread_idle_stack[THREAD_STACKSIZE_MAIN];
char thread_rcv_stack[THREAD_STACKSIZE_MAIN];

extern void send(char *addr_str, char *port_str, char *data, unsigned int num,
                 unsigned int delay);
extern void start_server(char *port_str, kernel_pid_t pid);
extern void stop_server(void);

void *thread_idle(void *arg)
{
    (void) arg;

    while(1){
        bench_ping(THREAD_IDLE);
        // Do nothing
    }
    return NULL;
}

void *thread_rcv(void *arg)
{
    (void) arg;

    msg_t msg;
    msg_t msg_queue[GNRC_PKTDUMP_MSG_QUEUE_SIZE];


    /* setup the message queue */
    msg_init_queue(msg_queue, GNRC_PKTDUMP_MSG_QUEUE_SIZE);

    /* Start the server */
    start_server("8808", thread_getpid());

    while(1) {
        bench_ping(THREAD_RCV);
        msg_receive(&msg);
        puts("Message received");
    }
    
    return NULL;
}

static void button_cb(void *arg)
{
    (void) arg;
    // Send to multicast
    send("ff02::1", "8808", "Hello", 1, 1000000);
}

int main(void)
{
    /**
     * Init the buttons to trigger the framework
     **/
    if (gpio_init_int(BTN0_PIN, BTN0_MODE, GPIO_FALLING, button_cb, NULL) != 0) {
        puts("[FAILED] init BTN0!");
        return 1;
    }
    puts("[SUCCESS] Button initialized!");

    /* Threads creation */
    thread_create(thread_idle_stack, sizeof(thread_idle_stack),
                14, THREAD_CREATE_WOUT_YIELD,
                thread_idle, NULL, "thread_idle");

    thread_create(thread_rcv_stack, sizeof(thread_rcv_stack),
                13, THREAD_CREATE_WOUT_YIELD,
                thread_rcv, NULL, "thread_rcv");



    while(1) {
        // Do nothing
    }

    /* should be never reached */
    stop_server();
    return 0;
}
