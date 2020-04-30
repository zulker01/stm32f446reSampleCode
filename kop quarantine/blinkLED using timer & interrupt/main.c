#include "stm32f446xx.h"
#include "stdio.h"

int testLED=0;

void TIM7_IRQHandler(void){
//	TIM7->CR1&=0x0; //disable counter
	TIM7->SR &=0x0;
	//TIM7->SR &= -TIM_SR_UIF; // reset update flag
	TIM7->CNT &=0x0; // reset counting
	if(!testLED)
					{
						testLED = 1;
						GPIOA->BSRR |= GPIO_BSRR_BS5; // set PA 5
					}
	else
					{
						testLED = 0;
						GPIOA->BSRR |= GPIO_BSRR_BR5; // reset PA 5
					}
				}
 int main(){
		
		// activate GPIOA bus
		RCC->AHB1ENR |= 0x1;// or with
		// activate TIM7 bus
		RCC->APB1ENR |=0x20;
	
		GPIOA->MODER |= 0x400; // set the pin PA 5 as output mode
		
		TIM7->PSC = 0x3E80 ; // hex of dec 18000,clkspeed/psc
		int preScalar = TIM7->PSC;
		TIM7->ARR = 0x3E8 ; //hex of 10,000,counts upto arr
		int testTimer = 0,timerCounter=0;
		//if(TIM7->SR &1==1) then light up led
		TIM7->SR &=0x0000; //timer status resgister
		TIM7->DIER |=0x1; // update interrupt enable
		//TIM7->EGR |=0x1; // re initialize counter,generates an UE when setted to 1
//udis bit must be 0
	 TIM7->CNT&=0x0;
	 
	  TIM7->CR1 |= 0x4; // URS bit only counter overflow or underflow generates an update
	 TIM7->CR1 |= 0x1;     // counter enable
	NVIC_EnableIRQ(TIM7_IRQn);
		/*while(1){
				testTimer = 0;
				testTimer = TIM7->SR ;
				testTimer &=0x1; // get the update flag
				timerCounter = TIM7->CNT;
				//testLED  = GPIOA->BSRR; // check if led it set to 1
				//testLED &= 0x20;
				printf("preScalar %d , timer %d , counter %d, led %d\n",preScalar,testTimer,timerCounter,testLED);
				if(testTimer){
					if(!testLED)
					{
						testLED = 1;
						GPIOA->BSRR |= GPIO_BSRR_BS5; // set PA 5
					}
					else
					{
						testLED = 0;
						GPIOA->BSRR |= GPIO_BSRR_BR5; // reset PA 5
					}
					
					TIM7->SR =0x0000; // reset the update flag
				}
				//for(int i=0; i<1000000; i++) {}
					
					
					//for(int i=0; i<1000000; i++)

				
		}*/
}
 /*
while(1){
				testTimer = 0;
				testTimer = TIM7->SR ;
				testTimer &=0x1; // get the update flag
				timerCounter = TIM7->CNT;
				//testLED  = GPIOA->BSRR; // check if led it set to 1
				//testLED &= 0x20;
				printf("preScalar %d , timer %d , counter %d, led %d\n",preScalar,testTimer,timerCounter,testLED);
				if(testTimer){
					if(!testLED)
					{
						testLED = 1;
						GPIOA->BSRR |= GPIO_BSRR_BS5; // set PA 5
					}
					else
					{
						testLED = 0;
						GPIOA->BSRR |= GPIO_BSRR_BR5; // reset PA 5
					}
					
					TIM7->SR =0x0000; // reset the update flag
				}
				//for(int i=0; i<1000000; i++) {}
					
					
					//for(int i=0; i<1000000; i++)

				
		}*/
/*
int main(){
		RCC->AHB1ENR |= 0x1;// or with 
		GPIOA->MODER |= 0x400;
		while(1){
				GPIOA->BSRR |= GPIO_BSRR_BS5;
				for(int i=0; i<1000000; i++) {}
					GPIOA->BSRR |= GPIO_BSRR_BR5;
					
					for(int i=0; i<1000000; i++)
{
}	
				
		}
}
*/
