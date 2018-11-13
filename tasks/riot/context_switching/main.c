
#include <stdio.h>
#include "thread.h"
#include "xtimer.h"
#include "timex.h"

#define INTERVAL (1U * US_PER_SEC)

char thread1_stack[THREAD_STACKSIZE_MAIN];
char thread2_stack[THREAD_STACKSIZE_MAIN];

void *thread1(void *arg)
{
    (void) arg;
    xtimer_ticks32_t last_wakeup = xtimer_now();

    while(1) {
        xtimer_periodic_wakeup(&last_wakeup, INTERVAL);
        puts("Thread 1");
    }
    return NULL;
}

void *thread2(void *arg)
{
    (void) arg;
    while(1){}
    return NULL;
}

int main(void)
{
    puts("Hello World!");
    puts("Context Switching Task");

    thread_create(thread1_stack, sizeof(thread1_stack),
                THREAD_PRIORITY_MAIN - 2, THREAD_CREATE_STACKTEST,
                thread1, NULL, "thread1");

   thread_create(thread2_stack, sizeof(thread2_stack),
               THREAD_PRIORITY_MAIN - 1, THREAD_CREATE_STACKTEST,
               thread2, NULL, "thread2");
    return 0;
}