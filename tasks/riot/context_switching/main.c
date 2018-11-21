#define INTERVAL (1U * US_PER_SEC)

#include <stdio.h>
#include "thread.h"
#include "xtimer.h"
#include "timex.h"


char threadA_stack[THREAD_STACKSIZE_MAIN];
char threadB_stack[THREAD_STACKSIZE_MAIN];

uint32_t time;

void *threadA(void *arg)
{
    (void) arg;

    while(1) {
        time = xtimer_now_usec();
        xtimer_sleep(1);
    }
    return NULL;
}

void *threadB(void *arg)
{
    (void) arg;

    while(1){
        if(time) {
            uint32_t result = xtimer_now_usec() - time;
            time = 0;
            printf("##### From ThreadA to ThreadB: %"PRIu32"", result);
        }
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