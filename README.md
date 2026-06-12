# Interrupt-Driven Temperature Monitoring System

## Overview

This project implements a real-time temperature monitoring system on the STM32L476RG microcontroller using Embedded C and a TMP36 temperature sensor.

The system uses an interrupt-driven architecture for temperature acquisition, processing, and communication while maintaining low CPU utilization and responsive operation.

## Physical Implementation
<p align="center">
  <img width="800" height="447" alt="Picture1" src="https://github.com/user-attachments/assets/fb431790-148f-4944-a4be-cec66fc39959" />
</p>
*STM32L476RG Nucleo board interfaced with a TMP36 temperature sensor and pushbutton input used for interrupt-driven temperature acquisition.*

## Watch the Project Demo on YouTube:

[YouTube Link](https://youtube.com/shorts/VCGkpnGxSkg?si=lCWobiPJN4j2y3_K)


## Firmware Flowchart

<p align="center">
  <img width="800" height="447" alt="Picture1" src="https://github.com/user-attachments/assets/b04a6417-eaaa-4e02-8c09-ee2eec74dc25" />
</p>

## Circuit Diagram

<p align="center">
  <img width="800" height="447" alt="Picture2" src="https://github.com/user-attachments/assets/4fa9e3ba-1b86-4f81-a801-52bf247a0db8" />
</p>


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

## Results

* Implemented an interrupt-driven temperature monitoring system on the STM32L476RG using Embedded C.
* Acquired temperature measurements through the STM32's 12-bit ADC and TMP36 sensor interface.
* Improved measurement stability using 64-sample ADC averaging.
* Streamed real-time temperature data to a PC via USART2 at 115200 bps in CSV format.
* Validated system timing using a logic analyzer and verified thermal response through MATLAB analysis.

## Documentation

- 📄 [Technical Report](<img width="1252" height="958" alt="Picture1" src="https://github.com/user-attachments/assets/ed1096d2-7be3-4348-aed2-5cef4b07dc08" />)
- 📄 [Project Summary]([STM32_Temperature_Monitoring_Project_Summary.pdf](https://github.com/user-attachments/files/28901816/STM32_Temperature_Monitoring_Project_Summary.pdf))

## Skills Demonstrated
*Embedded Systems
* Embedded C
* STM32L476RG
* ARM Cortex-M4
* Firmware Development
* ADC
* UART / USART
* Interrupt-Driven Programming
* MATLAB
* Hardware Debugging
