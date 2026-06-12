#include "temperature.h"
#include <stdint.h>
#include "stm32l476xx.h"


void ADC_Pin_Init(void){
	// 1. Clock for GPIOA
	RCC -> AHB2ENR |= RCC_AHB2ENR_GPIOAEN;

	// 2. Initialize PA0
	GPIOA -> MODER |= 0b11UL << (2 * 0);

	// 3. Connect PA0 to analog switch; ASCR = Analog Switch Control Register
	GPIOA -> ASCR |= (1UL << 0);
}


void ADC_Common_Configuration(void) {
    // ADC clock = system clock / 1
    ADC123_COMMON -> CCR &= ~ADC_CCR_CKMODE;
    ADC123_COMMON -> CCR |= ADC_CCR_CKMODE_0;

    // Independent mode
    ADC123_COMMON -> CCR &= ~ADC_CCR_DUAL;
}


void ADC1_Wakeup(void) {
    volatile int wait_time;										// Ensure compiler doesn't optimize

    ADC1 -> CR &= ~ADC_CR_DEEPPWD;   							// Exit deep power-down
    ADC1 -> CR |= ADC_CR_ADVREGEN;   							// Enable ADC voltage regulator

    // delay for wake-up
    wait_time = 20 * (4000000 / 1000000);						// 20 microsecond ADC wake-up
    while (wait_time != 0) {
        wait_time--;
    }
}


// 10-Step initialization/configuration
void ADC_Init(void) {
	// 1. Disable ADC1
	ADC1 -> CR &= ~ADC_CR_ADEN;

	// 2. Enable ADC clock
	RCC -> AHB2ENR |= RCC_AHB2ENR_ADCEN;

	// 3. Configure PA0 as analog input
	ADC_Pin_Init();

	// 4. Configure ADC common settings
	ADC_Common_Configuration();

	// 5. Wake ADC from deep-power-down mode
	ADC1_Wakeup();

	// 6. Single-ended mode for PA0 = ADC1 Channel 5
	ADC1 -> DIFSEL &= ~ADC_DIFSEL_DIFSEL_5;

	// 7. Calibrate ADC
	ADC1 -> CR |= ADC_CR_ADCAL;
	while ((ADC1 -> CR & ADC_CR_ADCAL) == ADC_CR_ADCAL);		//wait until bit clears

	// 8. 12-bit resolution, right alignment
	ADC1 -> CFGR &= ~ADC_CFGR_RES;
	ADC1 -> CFGR &= ~ADC_CFGR_ALIGN;

	// 9. Regular sequence: 1 conversion, channel 5 (PA0)
	ADC1 -> SQR1 &= ~ADC_SQR1_L;
	ADC1 -> SQR1 &= ~ADC_SQR1_SQ1;
	ADC1 -> SQR1 |= (5U << 6);

	// increase sample time; helpful for accuracy
	ADC1 -> SMPR1 &= ~ADC_SMPR1_SMP5;
	ADC1 -> SMPR1 |=  ADC_SMPR1_SMP5;   						// longest sample time

	// 10. Enable ADC
	ADC1 -> ISR |= ADC_ISR_ADRDY;
	ADC1 -> CR |= ADC_CR_ADEN;
	while ((ADC1 -> ISR & ADC_ISR_ADRDY) == 0);
}
