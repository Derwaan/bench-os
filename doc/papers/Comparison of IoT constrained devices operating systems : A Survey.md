# Comparison of IoT constrained devices operating systems : A Survey
FreeRTOS, Mbed, Contiki, TinyOS and RIOT

Discussion on:
1. Kernel Architecture
2. Scheduling and Real-Time Capabilities
3. Programming Model
4. Memory Footprint
5. Network Connectivity & Protocol Support
6. HW support
7. Energy efficiency

## 1. Kernel Architecture

Monolithic vs micro-kernel

With monolithic, the cost of interaction is low but it is hard to ensure reliability and maintenance -> poor design for IoT.

With micro-kernel we get overhead of memory performance but small kernel size and fewer context switching. The whole system does not crash unlike monolithic.

FreeRTOS, Mbed and RIOT have microkernel architecture and they are all full Real-Time OSs unlike Tiny and Contiki.


## 2. Scheduling

preemptive vs cooperative

A preemptive scheduler such as RTOS one assigns CPU time to each task, while the different tasks have to yield themselves in the cooperative model.

For real-time capabilities, the scheduler should respect strict time constraints.
This kind of scheduling should reach the processes deadlines so that tasks are completed within given time limits.
Moreover, the schedulers should be energy efficient and multitasking in IoT systems.

Preemptive schedulers are preferred due to the real-time and multitasking nature of RTOS's.

TinyOS is cooperative and does not support real-time.

Contiki is cooperative and partially supports real-time.

Others are preemptive and support real-time.

## 3. Programming model

event-driven vs multi-threaded

In an event-driven system, every task has to be triggered
y an external event, such as an interrupt. 

Multi-threading gives the opportunity to run each task in its own thread context, and communicate between the tasks by using an Inter Process Communication (IPC) APIs

Multi-threaded can have simpler code, and be optimized at compilation.
It is better suited for IoT.

TinyOS and Contiki are Event-driven so they can be more memory efficient.

FreeRTOS, Mbed and RIOT OSs are multi-threading systems so more suitable in
IoT application design.

## 4. Memory Footprint

Memory footprint depends on:
- architecture of hardware platform, 
- compiler settings
- OS configurations which include kernel size and size of run-time libraries

IETF standardized in the RFC-7228 a classification of IoT devices in three subcategories based on memory capacity

| Name     | Data (RAM) |Code(Flash)|
|----------|------------|-----------|
| Classe 0 | << 10 Kib  | << 100Kib |
| Classe 1 |   ~10 Kib  |  ~100 Kib |
| Classe 2 |   ~50 Kib  |  ~250 Kib |


See graph in article for comparison

## 5. Network Connectivity & Protocol Support

TODO

## 6. HW support

IoT low-end devices are based on various microcontroller architectures and families:
- 8-bit processor architecture like Intel 8051 and Atmel AVR 
- 16-bit architecture like TI MSP430, 
- 32-bit architecture like ARM Cortex-M and MIPS32

64-bit architectures might also appear in the future.


## 7. Energy efficiency

In low-power wireless systems, the radio transceiver is typically the most power-consuming component, so power-efficiency translates into keeping the radio off as much as possible by using low power protocols like 6lowpan, RPL, LoRaWan, etc.

For the microcontroller side, we need to minimize power consumption when possible. We can do that by implementing an idle mode often consuming less than 10 microA.

Clock frequency can also vary and certain processors can also switch off clocks in Sleep Mode.

#### FreeRTOS
FreeRTOS uses an Idle Task to place the device in low power mode when no task is running.

#### Mbed OS
Mbed power management API's use ARM Cortex-M power saving capabilities.
In addition to Sleep mode, there is also a DeepSleep mode, a PowerDown mode, and a DeepPowerDown mode.

#### Contiki
Contiki scheduler exposes the size of the event queue so that applications can put the microcontroller or peripheral hardware in sleep modes. 
Therefore power saving process could put the CPU in sleep mode when the event queue is empty.

For the radio, it uses ContikiMAC for power management.

#### TinyOS
Sleep mode when no task.

#### RIOT OS
Tickless scheduler to achieve maximum energy efficiency.

Most schedulers use timer ticks to wake up periodically and check if something needs to be done. 
However, if the processor is in the idle state, it has to wake up from its power-saving sleep state every timer tick, even when there is nothing to do which is not desirable for energy constrained systems.
Morever, only interrupts can wake up the processor from deep sleep. Timer ticks prevent using deep sleep mode.

Some methods for reducing power consumption are slow down the clocks, especially the main clock for the core of the device, reduce the supply voltage to the core of the device, stop the main clock, turn off power to the core and turn off power to the clock generator(s).











