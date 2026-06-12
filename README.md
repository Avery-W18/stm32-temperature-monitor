# Interrupt-Driven Temperature Monitoring System

## Overview

This project implements a real-time temperature monitoring system on the STM32L476RG microcontroller using Embedded C and a TMP36 temperature sensor.

The system uses an interrupt-driven architecture for temperature acquisition, processing, and communication while maintaining low CPU utilization and responsive operation.

## Features

* 12-bit ADC temperature acquisition
* EXTI interrupt handling
* SysTick-based button debouncing
* UART communication at 115200 bps
* 64-sample averaging for improved measurement stability
* Real-time CSV data streaming to a PC
* Event-driven firmware architecture

## Hardware

* STM32L476RG Nucleo Board
* TMP36 Temperature Sensor

## Software & Tools

* Embedded C
* STM32CubeIDE
* MATLAB
* AD2 Logic Analyzer

## Firmware Flowchart

<img width="761" height="447" alt="Picture1" src="https://github.com/user-attachments/assets/b04a6417-eaaa-4e02-8c09-ee2eec74dc25" />


## Circuit Diagram

<img width="628" height="386" alt="Picture2" src="https://github.com/user-attachments/assets/4fa9e3ba-1b86-4f81-a801-52bf247a0db8" />


## Demo Video

[YouTube Demo](https://youtube.com/shorts/VCGkpnGxSkg)

## Repository Structure

```text
src/  - Source files
inc/  - Header files
```

## Skills Demonstrated

Embedded Systems, Firmware Development, STM32, ARM Cortex-M4, ADC, UART, Interrupts, Real-Time Systems, Debugging, MATLAB
