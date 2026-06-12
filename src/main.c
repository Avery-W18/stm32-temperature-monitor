/*
  @file    main.c
  @author  Avery Whann
  	  	   Yosias Samuel
  	  	   Shahroz Rizwan
  @date    Spring-2026
*/

#include "stm32l476xx.h"
#include "Systick_timer.h"
#include "button.h"
#include "temperature.h"
#include "usart.h"
#include <stdio.h>


// variables for Temperature conversion
volatile uint32_t adc_result = 0;
volatile int32_t currentTempC_int = 0;
volatile uint32_t voltage_mV = 0;
volatile int32_t currentTempF_int = 0;
volatile uint8_t temp_request = 0;

int main(void)
{
	// 1. Initialize SysTick
    SysTick_Init(4000);        										// 1ms tick (for debounce logic)

    // 2. Configure push button to PC2
    configure_switch_pin();    										// EXTI button on PC2

    // 3. Initialize ADC and PA0 for TMP36
    ADC_Init();                										// ADC on PA0 (TMP36)

    // 4. Initialize USART2
    USART2_Init();

    // 5. While loop to get temperature values
    while (1)
    {
        if (temp_request != 0)										// makes system event-driven
        {
        	temp_request = 0;										// software interrupt flag reset

        	uint32_t sum = 0;

        	// takes multiple ADC samples and averages them
        	for (int i = 0; i < 64; i++)
        	{
        	    ADC1 -> ISR |= ADC_ISR_EOC; 						// clears EOC flag
        	    ADC1 -> CR |= ADC_CR_ADSTART;						// start ADC conversion
        	    while ((ADC1 -> ISR & ADC_ISR_EOC) == 0);			// wait until ADC is done converting
        	    sum += ADC1 -> DR;									// adds latest ADC value to sum
        	}

        	// average of 64 samples to reduce noise
        	adc_result = sum / 64;

            // variables and formula
            // converts ADC value to voltage (in mV) for 12-bit ADC
            voltage_mV = (adc_result * 3300U) / 4095U;

            // converts TMP36 millivots reading to °C with 500mV offset
            // Temperature (°C) = (Vout_mV - 500) / 10
            // fixed-point integer math
            // Scaling example: 26.70°C is stored as 2670
            currentTempC_int = ((int32_t)voltage_mV - 500) * 10;

            // prints Temperature to COM Port
            // prints CSV-formatted data for graphing via fixed-point integer math
            printf("%lu, %lu, %ld.%02ld\r\n", adc_result, voltage_mV, currentTempC_int / 100, currentTempC_int % 100);
        }
    }
}
