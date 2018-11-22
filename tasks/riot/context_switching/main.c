#define INTERVAL (1U * US_PER_SEC)

#include <stdio.h>
#include "msg.h"
#include "thread.h"
#include "xtimer.h"
#include "timex.h"


// Thread stacks
char threadA_stack[THREAD_STACKSIZE_MAIN];
char threadB_stack[THREAD_STACKSIZE_MAIN];
// PID of the threadB to send a message to
static kernel_pid_t rcv_pid;

void *threadA(void *arg)
{
    (void) arg;
    // The timer
    uint32_t time;8
    // The message with the timer
    msg_t msg;

    while(1) {
        // Measure the time
        time = xtimer_now_usec();
        // Fill the message
        msg.content.value = time;
        // Send the message
        msg_try_send(&msg, rcv_pid);
        // Thread yield
        xtimer_sleep(1);
    }
    return NULL;
}

void *threadB(void *arg)
{
    (void) arg;
    // The received message
    msg_t msg;
    while(1){
        // If we received a message
        if(msg_receive(&msg) == 1) {
            // Compute the context switching time
            uint32_t result = xtimer_now_usec() - msg.content.value;
            printf("##### From ThreadA to ThreadB: %"PRIu32" microseconds\n", result);
        }

        // Do nothing
    }
    return NULL;
}

int main(void)
{
    puts("Context Switching Task");

    // Create threadA with priority 5
    puts("Main: Creating threadA...");
    thread_create(threadA_stack, sizeof(threadA_stack),
                THREAD_PRIORITY_MAIN - 2, THREAD_CREATE_WOUT_YIELD,
                threadA, NULL, "threadA");

    // Create threadB with priority 6
    puts("Main: Creating threadB...");
    rcv_pid = thread_create(threadB_stack, sizeof(threadB_stack),
               THREAD_PRIORITY_MAIN - 1, THREAD_CREATE_WOUT_YIELD,
               threadB, NULL, "threadB");
               
    return 0;
}