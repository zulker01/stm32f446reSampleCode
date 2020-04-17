#include "stm32f446xx.h"
#include <time.h> 
  
void delay(int number_of_milliseconds) 
{ 
    // Converting time into milli_seconds 
    //int milli_seconds = 1000 * number_of_seconds; 
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + number_of_milliseconds) 
        ; 
} 

int main()
{

    RCC->AHB1ENR|=0x1;

    GPIOA->MODER|=0x100000;

    while(1){

        GPIOA->BSRR|=0x400;

        for(int i=0;i<100000;i++){};

					//delay(10);
        GPIOA->BSRR|=0x4000000;

			//delay(1);
        for(int i=0;i<1000000;i++){};

    }
		
}
