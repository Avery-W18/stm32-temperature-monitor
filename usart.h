/*
 * usart.h
 *
 *  Created on: May 8, 2026
 *      Author: vigil
 */

#ifndef USART_H_
#define USART_H_
#include "stm32l476xx.h"

void USART2_Init(void);
int __io_putchar(int ch);

#endif /* USART_H_ */
