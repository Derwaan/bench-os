#include "contiki.h"
#include "bench-context-switching.h"

#include <stdio.h>

#define THREAD_1 1
#define THREAD_2 2

PROCESS(task_1, "First task");
PROCESS(task_2, "Second task");
AUTOSTART_PROCESSES(&task_1, &task_2);

static struct etimer timer;

PROCESS_THREAD(task_1, ev, data)
{
    PROCESS_BEGIN();

    while (1) {
        etimer_set(&timer, CLOCK_SECOND);
        PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer));
        
        bench_ping(THREAD_1);
        printf("Hello\n");
    }

    PROCESS_END();
}


PROCESS_THREAD(task_2, ev, data)
{
    PROCESS_BEGIN();

    while (1) {
        bench_ping(THREAD_2);
        // Do nothing
        PROCESS_PAUSE();
    }

    PROCESS_END();
}
