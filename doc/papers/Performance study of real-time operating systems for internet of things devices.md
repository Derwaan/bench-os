# Performance study of real-time operating systems for internet of things devices
This article presents a set of micro-benchmarks (tasks switching, semaphores, etc.) on open-source and proprietary RTOSs.


## Introduction
RFC7228: Standardisation of devices (see Comparison of IoT constrained devices operating systems : A Survey)

From Hahm, O., Baccelli, E., Petersen, H., et al.: ‘Operating systems for low-end devices in the internet of things: a survey’, IEEE Internet Things J., 2016, 3, (5), pp. 720–734

Open-Source OS's:
- Contiki,
- RIOT,
- FreeRTOS, 
- TinyOS, 
- OpenWSN, 
- eCOS, 
- mbedOS, 
- L4 family,
- uClinux, 
- Android, 
- Brillo.

Proprietary:
- ThreadX,
- QNX, 
- VxWorks, 
- Wind River Rocket, 
- PikeOS, embOS, 
- Nucleus,
- Sciopta, 
- μC/OS-II and μC/OS-III,
- μ-velOSity, 
- Windows CE,
- Huawei LiteOS.

## Related works
Inter process communication (IPC) performance is one of the most important criteria to be taken into account for the system to meet its timing constraints and desired performance. IPC performance can be benchmarked by measuring semaphores metrics.

see: 
- Bertolotti, I.C., Kashani, G.G.Z.: ‘On the performance of open-source RTOS synchronization primitives’. 2015 IEEE 1st Int. Forum on Research and Technologies for Society and Industry Leveraging a better tomorrow (RTSI), 2015, pp. 398–402
- Tan, S.L., Nguyen, B.A.T.: ‘Survey and performance evaluation of real-time operating systems (RTOS) for small microcontrollers’, IEEE Micro, 2009, PP, (99), pp. 1–1
- Garcia-Martinez, A., Conde, J.F., Vina, A.: ‘A comprehensive approach in performance evaluation for modern real-time operating systems’. Proc. EUROMICRO 96. 22nd Euromicro Conf. on Beyond 2000: Hardware and Software Design Strategies, 1996, pp. 61–68
The second article also provides a performance and memory footprint benchmark.

Dong, W., Chen, C., Liu, X., et al.: ‘Senspire OS: a predictable, flexible, and efficient operating system for wireless sensor networks’, IEEE TransComput., 2011, 60, (12), pp. 1788–1801 presents an OS with an hybrid system model combining event-driven and multi-threading programming.

## Study methodology
In this article, they measured performances on :
- FreeRTOS, 
- RIOT,
- μC/OS-III,
- Zephyr,
- μC/OS-II.

Criterias:
- Task switching time,
- Getting and releasing a semaphore time,
- Semaphore passing time,
- Pass and receive a message time,
- Inter-task message passing time,
- Fixed memory size acquire and release time,
- Task activation from within an interrupt service routine,
- Task activation jitter induced by priority inversion.
(see article for detailed explanations)

Results are also shown in the article.







