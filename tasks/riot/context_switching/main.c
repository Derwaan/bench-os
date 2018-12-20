#define INTERVAL (1U * US_PER_SEC)

#include <stdio.h>
#include <string.h>
#include "thread.h"
#include "xtimer.h"

// Include our benchmarking framework
#include "bench_context_switching.h"

#define THREAD_A 1
#define THREAD_B 2

// Thread stacks
char threadA_stack[THREAD_STACKSIZE_MAIN];
char threadB_stack[THREAD_STACKSIZE_MAIN];

void *threadA(void *arg)
{
    (void) arg;

    while(1) {
        bench_ping(THREAD_A);
        // Do nothing
        // Thread yield
        xtimer_sleep(1);
    }
    return NULL;
}

void *threadB(void *arg)
{
    (void) arg;

    while(1){
        bench_ping(THREAD_B);
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
    thread_create(threadB_stack, sizeof(threadB_stack),
               THREAD_PRIORITY_MAIN - 1, THREAD_CREATE_WOUT_YIELD,
               threadB, NULL, "threadB");
               
    return 0;
}