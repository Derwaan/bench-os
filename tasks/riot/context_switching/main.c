#define INTERVAL (1U * US_PER_SEC)

#include <stdio.h>
#include "thread.h"
#include "xtimer.h"
#include "timex.h"

char threadA_stack[THREAD_STACKSIZE_MAIN];
char threadB_stack[THREAD_STACKSIZE_MAIN];

void *threadA(void *arg)
{
    (void) arg;
    xtimer_ticks32_t last_wakeup = xtimer_now();

    while(1) {
        xtimer_periodic_wakeup(&last_wakeup, INTERVAL);
        puts("Thread A: echo");
    }
    return NULL;
}

void *threadB(void *arg)
{
    (void) arg;
    xtimer_ticks32_t last_wakeup = xtimer_now();

    while(1){
        xtimer_periodic_wakeup(&last_wakeup, INTERVAL);
        puts("Thread B: echo");
    }
    return NULL;
}

int main(void)
{
    puts("Context Switching Task");

    puts("Main: Creating threadA...");
    thread_create(threadA_stack, sizeof(threadA_stack),
                THREAD_PRIORITY_MAIN - 2, THREAD_CREATE_STACKTEST,
                threadA, NULL, "threadA");

    puts("Main: Creating threadB...");
   thread_create(threadB_stack, sizeof(threadB_stack),
               THREAD_PRIORITY_MAIN - 1, THREAD_CREATE_STACKTEST,
               threadB, NULL, "threadB");
    return 0;
}