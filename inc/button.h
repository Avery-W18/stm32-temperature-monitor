#ifndef BUTTON_H_
#define BUTTON_H_

#include "stm32l476xx.h"
#define SWITCH_PIN 2
extern volatile uint32_t counter;

void configure_switch_pin(void);
// Modular function to initialize PC2 as an input pin, interfacing with On-Board Push Button.
void EXTI2_IRQHandler(void);

#endif /* BUTTON_H_ */
