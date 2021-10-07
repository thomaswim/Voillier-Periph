#include "stm32f10x.h"
#include "Driver_GPIO.h"

	


int main ( void )
{
		MyGPIO_Struct_TypeDef PC13 ;
		MyGPIO_Struct_TypeDef PA5 ;
	
		RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4) ;
	
		PC13.GPIO = GPIOC ;
		PC13.GPIO_Pin = 13 ;
		PC13.GPIO_Conf = In_Floating ;
	


		PA5.GPIO = GPIOA ;
		PA5.GPIO_Pin = 5 ;
		PA5.GPIO_Conf = Out_Ppull ;
	
	MyGPIO_Init ( &PC13 );
	MyGPIO_Init ( &PA5 );
	



	

//// GPIOC_CRL => faut le passer en 01 pour passer en Floating input PC 13 
//	GPIOC -> CRH = GPIOC->CRH &~(0xF<<20);
//	GPIOC -> CRH = GPIOC->CRH |(0x04<<20);
//	
//	
//	// LED en output push pull (GPIOA_CRL => en mode output 00) 
//	GPIOA -> CRL = GPIOA-> CRL &~(0xF<<20);
//	GPIOA -> CRL = GPIOA-> CRL |(0x01<<20);
	
	
	
	do
{
	
	
	// Quand GPIOC PC13==1 alors GPIOA PA5=1 
	if(MyGPIO_Read(GPIOC , 13))
		MyGPIO_Reset(GPIOA , 5 );
	else {
		MyGPIO_Set(GPIOA , 5 );
	}
	
		
		
	

	
	
}while(1) ;
}
