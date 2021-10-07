#include "stm32f10x.h"
#include "MyTimer.h"
#include "Driver_GPIO.h"


void (* pTim1Fun) (void) ; /* déclaration d’un pointeur de fonction */
void (* pTim2Fun) (void) ; /* déclaration d’un pointeur de fonction */
void (* pTim3Fun) (void) ; /* déclaration d’un pointeur de fonction */
void (* pTim4Fun) (void) ; /* déclaration d’un pointeur de fonction */


	void TIM1_IRQHandler ( void )
	{
		if (pTim1Fun != 0)
			(*pTim1Fun) (); /* appel indirect de la fonction */
	}
	void TIM2_IRQHandler ( void )
	{
		if (pTim2Fun != 0)
			(*pTim2Fun) (); /* appel indirect de la fonction */
	}
		void TIM3_IRQHandler ( void )
	{
		if (pTim3Fun != 0)
			(*pTim3Fun) (); /* appel indirect de la fonction */
	}
		void TIM4_IRQHandler ( void )
	{
		if (pTim4Fun != 0)
			(*pTim4Fun) (); /* appel indirect de la fonction */
	}

	


void MyTimer_Base_Init ( MyTimer_Struct_TypeDef * Timer )
{
	Timer->Timer->ARR=Timer->ARR;
	Timer->Timer->PSC=Timer->PSC;
}


void MyTimer_ActiveIT(TIM_TypeDef * Timer , char Prio, void (*IT_function ) (void) )
{
	int bit ;
	if (Timer == TIM2 ){
		bit = 28;
		pTim2Fun = IT_function; // le pointeur de fonction devient IT_function qui est la routine que l'on veut
	}else if (Timer == TIM3){
		bit = 29;
		pTim3Fun = IT_function;
	}
	else if (Timer == TIM4){
		bit = 30;
		pTim4Fun = IT_function;
	}
	else if (Timer == TIM1){
		bit = 24;
		pTim1Fun = IT_function;
	}
	
	Timer->DIER |= (0x01<<0); // autorisation timer en local
	NVIC->ISER[0] |= (0x01<<bit); // autorisation NVIC 
	NVIC->IP[bit] = (Prio<<4); 
	
	
}
	
void MyTimer_PWM( TIM_TypeDef * Timer , char Channel ) 
{
	Timer->CCMR1 &= ~ TIM_CCMR1_OC1M_0;
	Timer->CCMR1 |=  TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2;
	

		if (Channel == 1 ){
			Timer->CCER |= TIM_CCER_CC1E;
		}else if( Channel == 2 ){
			Timer->CCER |= TIM_CCER_CC2E;
		}else if( Channel == 3 ){
			Timer->CCER |= TIM_CCER_CC3E;
		}else if( Channel == 4 ){
			Timer->CCER |= TIM_CCER_CC4E;
		}
}

void Start_MyTimer_PWM( TIM_TypeDef * Timer , char Channel ,int voltage ){
	Timer->CR1 |= TIM_CR1_CEN;
	Timer->CCR1 |= voltage;
}

	





