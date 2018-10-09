# A Survey on Resource Management in IoT Operating Systems

This articles talks about Contiki, TinyOS and FreeRTOS.

Organisations attempting to standardize IoT communications:
- IETF
- ITU-T
- IEEE
- ETSI
- ISO
- IEC
- M2M
- 3GPP

Resource management includes:
- Process management
- Memory management
- Energy management
- Communication management
- File management

### Process management
The kernel manages processes and threads to share information, protect process resources and assign resources.

Contiki and TinyOS are event-driven to provide memory efficiency.
Event-handlers wait for internal or external events such as interrupts.
The kernel then allocates memory to the process.
Efficient way to manage memory since there's a single stack.
Events are queued in a FIFO.
Tasks cannot be blocked during runtime.
Poor real-time performance.

The threaded approach generates unused memory.
Each thread requires its own stack even if it is not running.

Contiki makes use of both approaches with its protothreads
(a somehow modified event-driven model).
Protothreads use a multi-threaded model without increasing multiple-stack overhead.
It includes a conditional wait statement between the beginning and the end of each protothread.
Providing process synchronisation is still impossible.

TinyOs includes TOSThread which is an implementation of a preemptive application-level thread library to achieve maximum concurrency.
Application-level threads execute only if Kernel-level threads are not active.
Thread scheduler  provides concurrency between application-level threads.
It provides threads but increases computional complexity.
TOS-PRO is another solution for TinyOS

FreeRTOS uses a round-robin priority based scheduler.
see task.c, list.c queue.c and croutine.c in the source code.

### Memory management
2 common methods for memory management:
- static allocation
- dynamic allocation
In static allocation, the OS allocates memory to the system and cannot be modified during run-time.
It cannot predict the amount of memory needed for an application. 
Over-provisioning can happen.


Dynamic allocation provides flexibility in allocating memory during run-time.
If the memory is not freed correctly, it can cause memory leaks.

### Energy management

Mainly network protocols and scheduling optimization.

Contiki kernel doesn't offer any explicit energy saving mechanism.
Applications can put the CPU in sleep mode using an event queue (sleep mode when it's empty).

TinyOS uses STI (software thread integration) for energy conservation.
It also makes use of AEON of energy prediction and an energy consumption tracker (EATT).
This is interesting from an energy saving point of view but it creates computational overhead.

In FreeRTOS, waiting tasks are in a blocked state. 
If every task is blocked, FreeRTOS runs an idle task an goes into power-saving mode.
If the tickrate is too high, this mechanism can waste energy by entering and exiting idle mode.
FreeRTOS then includes a tickless idle mode


### Communication management

TODO

### File management

TODO