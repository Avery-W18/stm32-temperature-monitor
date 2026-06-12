#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <stdint.h>

extern volatile uint32_t adc_result;

// modular function to initialize the ADC
void ADC_Init(void);

// modular function to initialize analog pin (PA0)
void ADC_Pin_Init(void);

// modular function to configure the ADC common registers
void ADC_Common_Configuration(void);

// modular function to wake up ADC1 from deep-power-down mode
void ADC1_Wakeup(void);


#endif
