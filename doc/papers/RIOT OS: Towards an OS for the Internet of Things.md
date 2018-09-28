# RIOT OS: Towards an OS for the Internet of Things
The dominant WSN OS, Contiki and TinyOS, follow an event driven design, which is useful for typical WSN scenarios, but exhibit drawbacks for efficient and functional networking implementations.
Design Aspects for an IoT OS: Fundamentally, an OS is characterized by the following key design aspects: the structure of the kernel, the scheduler, and the programming model.

Design objectives:
- energy-efficiency
- small memory footprint
- Modularity
- Uniform API access, independant of the HW

Riot uses a modular achitecture from FireKernel supporting multi-threading.
Its advantages are that it is highly reliable (robust against component failure) and developer friendly (API).
Guarantee runtimes of O(1) by the use of static memory allocation in the kernel.
Dynamic memory allocation is only provided to applications.

Scheduler works without periodic events.
When there is no task, idle task is running.
It only can be waken up by interrupts.
This mechanism allows RIOT to chose a sleep mode depending on the use and stay in this state without any timer tick.

RIOT context switching is performed in two cases: 
- a kernel operation e.g., a mutex locking or creation of a new thread 
- an interrupt causes a thread switch. 
The first case will occur rarely. For example, every thread is usually created once.
Hence, it is important to reduce the processing time in case of a thread switch.
Therefore, RIOT’s kernel provides a minimized scheduler, when it gets called out of an interrupt service routine.
In that case, saving the old thread’s context is not required and thus a task switch can be performed in very few clock cycles.




