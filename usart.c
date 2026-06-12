#include "usart.h"

// USART Initialization function
void USART2_Init(void)
{
	// Enables clocks for GPIOA and USART2
    RCC -> AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    RCC -> APB1ENR1 |= RCC_APB1ENR1_USART2EN;

    // PA2 mapped to USART2_TX
    GPIOA -> MODER &= ~(3U << (2 * 2));
    GPIOA -> MODER |=  (2U << (2 * 2));

    // Map PA2 to USART2 Alternate Transmit Function register using AF7
    GPIOA -> AFR[0] &= ~(0xFU << (4 * 2));
    GPIOA -> AFR[0] |=  (7U << (4 * 2));

    USART2 -> CR1 = 0;												// clears settings in Control Register
    USART2 -> BRR = 4000000 / 115200;     							// 4 MHz clock and 115200 baud rate in terminal
    USART2 -> CR1 |= USART_CR1_TE;									// allows USART to send data
    USART2 -> CR1 |= USART_CR1_UE;									// turns USART peripheral ON
}

// Function to transmit a character over USART2 (printf)
int __io_putchar(int ch)
{
    // Wait until USART is ready
    while (!(USART2 -> ISR & USART_ISR_TXE));

    // Sends one character
    USART2 -> TDR = (uint8_t)ch;

    return ch;														// required for printf
}
