#include "stm32f10x.h"


int main ( void )
{
RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4) ;
// GPIOC_CRL => faut le passer en 01 pour passer en Floating input PC 13 
	GPIOC -> CRH = GPIOC->CRH &~(0xF<<20);
	GPIOC -> CRH = GPIOC->CRH |(0x04<<20);
	
	
	// LED en output push pull (GPIOA_CRL => en mode output 00) 
	GPIOA -> CRL = GPIOA-> CRL &~(0xF<<20);
	GPIOA -> CRL = GPIOA-> CRL |(0x01<<20);
	do
{
	
	
	// Quand GPIOC PC13==1 alors GPIOA PA5=1 
	if(GPIOC -> IDR & (0x1<<13))
		
		GPIOA->BRR = (0x01<<5);
	else {
		GPIOA->BSRR = (0x01<<5);
	}
	
		
		
	

	
	
}while(1) ;
}
