#include "contiki.h"

#include <stdio.h>

PROCESS(task_1, "First task");
PROCESS(task_2, "Second task");
AUTOSTART_PROCESSES(&task_1, &task_2);

PROCESS_THREAD(task_1, ev, data)
{
    PROCESS_BEGIN();

    while (1) {
        PROCESS_PAUSE();
        printf("Hello from task 1\n");
    }

    PROCESS_END();
}


PROCESS_THREAD(task_2, ev, data)
{
    PROCESS_BEGIN();

    while (1) {
        PROCESS_PAUSE();
        printf("Hello from task 2\n");
    }

    PROCESS_END();
}
