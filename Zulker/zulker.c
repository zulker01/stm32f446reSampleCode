#include "stm32f4xx.h"

int main()
{
	RCC->AHB1ENR |= 0x2;
	GPIOB->MODER |= 0x40000;
	
}