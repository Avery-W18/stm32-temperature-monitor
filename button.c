#include "button.h"
#include "Systick_timer.h"
#include "stm32l476xx.h"
#include "temperature.h"

// Counts how many times the button has been pressed
volatile uint32_t counter = 0;

// Stores the time (in ms) of the last valid button press
volatile uint32_t lastButtonPress = 0;

// Flag used to tell the main loop to read temperature
extern volatile uint8_t temp_request;

#define DEBOUNCE_MS 50 									// 50ms Debounce

// Function to configure pushbutton on PC2 as falling-edge
// PC2 internal pull-up
void configure_switch_pin(){

	// 1. Enable the clock to GPIO Port C
	RCC -> AHB2ENR |= RCC_AHB2ENR_GPIOCEN;

	// 2. Configure GPIO Mode to 'Input'
	GPIOC -> MODER &= ~(3UL << (2 * SWITCH_PIN));		// PC2 input

	// 3. Configure Pull-Up/Pull-Down
	GPIOC -> PUPDR &= ~(3UL << (2 * SWITCH_PIN));		// clear PC2 bits
	GPIOC -> PUPDR |=  (1UL << (2 * SWITCH_PIN));		// pull-up

	// 4. Enable SYSCFG clock
	RCC -> APB2ENR |= RCC_APB2ENR_SYSCFGEN;

	// 5. Connect PC2 to EXTI2
	SYSCFG -> EXTICR[0] &= ~(0xF << 8);   				// clear EXTI2 bits
	SYSCFG -> EXTICR[0] |=  (0x2 << 8);   				// port C

	// 6. Unmask EXTI2
	EXTI -> IMR1 |= (1U << SWITCH_PIN);

	// 7. Trigger on falling edge only (button press on PC2)
	EXTI -> FTSR1 |= (1U << SWITCH_PIN);
	EXTI -> RTSR1 &= ~(1U << SWITCH_PIN);

	// 8. Clear any pending interrupts
	EXTI -> PR1 = (1U << SWITCH_PIN);

	// 9. Enable interrupt in NVIC
	NVIC_EnableIRQ(EXTI2_IRQn);

}

// Interrupt handler for push button (PC2)
// Uses SysTick for software debouncing (50 ms)
// Sets a flag to request temperature reading in main loop
void EXTI2_IRQHandler(void)
{
		// Check if EXTI line for PC2 caused the interrupt
    if (EXTI -> PR1 & (1U << SWITCH_PIN)) {

    	// Clear the interrupt flag
        EXTI -> PR1 = (1U << SWITCH_PIN);



        // Only accept if button press is LOW
        if ((GPIOC -> IDR & (1U << SWITCH_PIN)) == 0) {

        	// Only if enough time passed since last valid press
        	if ((msTicks - lastButtonPress) >= DEBOUNCE_MS) {

            lastButtonPress = msTicks; 					// store time of button press

            counter++;									// count how many times button was pressed

            temp_request = 1;							// notify main loop to read the temperature of TMP36
        	}
        }
    }
}
