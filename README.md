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

## Demo Video

[YouTube Demo](https://youtube.com/shorts/VCGkpnGxSkg)

## Repository Structure

```text
src/  - Source files
inc/  - Header files
```

## Skills Demonstrated

Embedded Systems, Firmware Development, STM32, ARM Cortex-M4, ADC, UART, Interrupts, Real-Time Systems, Debugging, MATLAB
