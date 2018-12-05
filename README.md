# Benchmark of Operating Systems on Internet of Things devices
Master thesis, Gomez Julien & Tran Trong-Vu, 2018-2019.

julien.gomez@student.uclouvain.be

trong-vu.tran@student.uclouvain.be

Promoter: [Prof. Ramin Sadre](https://uclouvain.be/fr/repertoires/ramin.sadre)

École polytechnique de Louvain at Université catholique de Louvain, Belgium.

## Introduction
It comes as a fact that embedded devices are more and more present in our everyday life.
It is believed that the current market will reach tens of billions of devices by 2020[<sup>1</sup>](https://spectrum.ieee.org/tech-talk/telecom/internet/popular-internet-of-things-forecast-of-50-billion-devices-by-2020-is-outdated).

To run those devices, a wide and exotic range of operating systems are developed by the industry. As the computational power of such devices is limited, their operating systems are designed with high constraints in mind (compared to general purpose operating systems).

## Objectives
Our thesis aims to analyse and benchmark operating systems for embedded devices.
We especially target open-source real-time operating systems.

The main goal is double:
- Assess the performances of different operating systems.
- Develop a framework to benchmark the applications running over them.

We defined several metrics to assess and picked a set of operating systems to compare.

## What is a RTOS?
A real-time operating system is an operating system designed for real-time applications. It aims to perform computational tasks within a strict time constraint. Processes in a real-time application need to meet their deadline or the system may fail. Such operating systems need to have a minimal interrupt latency or context-switching latency.

The operating systems we're currently working on:
- RIOT OS [Website](https://www.riot-os.org/) [Github](https://github.com/RIOT-OS/RIOT)
- Contiki  [Website](http://www.contiki-os.org/) [Github](https://github.com/contiki-os/contiki)
- FreeRTOS [Website](https://www.freertos.org/) [Github](https://github.com/aws/amazon-freertos)
- Apache MyNewt [Website](https://mynewt.apache.org/) [Github](https://github.com/apache/mynewt-core)
- Mbed [Website](https://www.mbed.com/en/) [Github](https://github.com/ARMmbed/mbed-os)

The metrics we are mesuring:
- Interrupt latency
- Context-switching latency
- Energy consumption
- Memory usage
- Scheduling policy

## Bibliography
