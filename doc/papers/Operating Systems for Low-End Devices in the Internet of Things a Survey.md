# Operating Systems for Low-End Devices in the Internet of Things: a Survey

> Oliver Hahm, Emmanuel Baccelli, Hauke Petersen, Nicolas Tsiftes

> 17 Dec 2015

## Low-End IoT Devices

Devices can be divided into three subcategories:

- **Class 0**: smallest resources (under 10kB of RAM and under 100kB of ROM)
- **Class 1**: medium-level resources (~10kB of RAM and ~100kB of ROM)
- **Class 2**: More resources but still constrained

This paper focus on Class 1 and Class 2 as Class 0 does not have enough resources to run a RTOS.
In the future the Class 1 and Class 2 devices will be more predominant in the IoT.

## Requirements for an IoT Operating System

- Small Memory Footprints
- Support for Heterogeneous Hardware
- Network Connectivity
- Energy Efficiency
- Real-Time Capabilities
- Security

## Key Design Choices

### General Architecture and Modularity

- Exokernel
    - Few abstractions between applications and the hardware.
    - Focus on resources conflicts.
- Microkernel
    - More functionalities.
    - Very little memory.
    - Robustness.
- Monolithic kernel
    - All components are developed together.
    - More efficient design.
- Hybrid kernel

One has to choose between the more robust and more flexible microkernel or a less complex an more efficient monolithic kernel - or go for a hybrid approach.

### Scheduling Model

- Preemptive scheduler
    - Assigns CPU time to each task.
- Cooperative model
    - Tasks have to yield themselves.

### Memory Allocation

- Static memory
    - Memory overhead due to over-provisioning.
- Dynamic memory
    - Complex systems.
    - Conflict with real-time requirements.

### Programming Model

- Event-driven
    - Memory-efficient.
- Mutli-threading
    - More like a real application.
    - Ease the application design.

### Driver Model and Hardware Abstraction Layer

A well-defined hardware abstraction layer and driver model can significantly improve the system design, but introduces a certain amount of overhead.

### Other choices

- Programming languages
- Debugging tools
- Feature set
- Testing

## OS for the IoT

- Contiki
- RIOT
- FreeRTOS
- TinyOS
- OpenWSN
- nuttX
- eCos
- mbedOS
- L4 microkernel family
- uClinux
- Android and Brillo

Those OS can be categorized:

- Event-driven OSs
- Multi-Threading OSs
- Pure RTOSs

## Case Studies

### Contiki

### RIOT

### FreeRTOS
