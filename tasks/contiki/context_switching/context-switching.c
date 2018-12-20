#include "contiki.h"
#include "bench-context-switching.h"

#include <stdio.h>

#define THREAD_1 1
#define THREAD_2 2

PROCESS(task_1, "First task");
PROCESS(task_2, "Second task");
AUTOSTART_PROCESSES(&task_1, &task_2);

static struct etimer timer_1;
static struct etimer timer_2;

PROCESS_THREAD(task_1, ev, data)
{
    PROCESS_BEGIN();

    while (1) {
        etimer_set(&timer_1, CLOCK_SECOND);
        PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer_1));

        bench_ping(THREAD_1);
        printf("Hello from task 1\n");
    }

    PROCESS_END();
}


PROCESS_THREAD(task_2, ev, data)
{
    PROCESS_BEGIN();

    while (1) {
        etimer_set(&timer_2, CLOCK_SECOND);
        PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer_2));

        bench_ping(THREAD_2);
        printf("Hello from task 2\n");
    }

    PROCESS_END();
}
