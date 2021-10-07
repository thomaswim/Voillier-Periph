#ifndef MYTIMER_H
#define MYTIMER_H

#include "stm32f10x.h"

typedef struct
{
			TIM_TypeDef * Timer ; // TIM1 à TIM4
			unsigned short ARR ;
			unsigned short PSC ;
}MyTimer_Struct_TypeDef ;

/*
*****************************************************************************************
* @brie f
* @param -> Paramè t r e sous forme d ’ une s t r u c t u r e ( son a d re s se ) con ten an t l e s
i n f o rm a ti o n s de base
* @Note -> F onc ti on à l a n c e r s y s t ématiquement avan t d ’ a l l e r pl u s en dé t a i l dans l e s
con f pl u s f i n e s (PWM, codeur i n c . . . )
*************************************************************************************************
*/

void MyTimer_Base_Init ( MyTimer_Struct_TypeDef * Timer ) ;

#define MyTimer_Base_Start(Timer)  (Timer->CR1 |= Timer->CR1|(0x01<<0)) ;

#define MyTimer_Base_Stop(Timer) (Timer->CR1 |= Timer->CR1|(0x0<<0)) ;





/*
**************************************************************************************************
* @brie f
* @param : - TIM_TypeDef * Timer : Timer concerne
- cha r P ri o : de 0 a 15
* @Note : La f o n c ti o n MyTime r_Base_ Ini t d oi t a v oi r e te l a n cee au p r e al a bl e
**************************************************************************************************
*/

void MyTimer_ActiveIT ( TIM_TypeDef * Timer , char Prio, void (*IT_function ) (void) ) ;

void TIM2_IRQHandler ( void ); 
#endif

/*
**************************************************************************************************
* @brief
* @param . . . .
* @Note Active le channel spécifié su Timerr le timer spécifié
* la gestion de la configuration I/O n’est pas faite dans cette fonction
* ni le réglage de la période de la PWM (ARR, PSC)
**************************************************************************************************
*/
void MyTimer_PWM( TIM_TypeDef * Timer , char Channel ) ;

void Start_MyTimer_PWM( TIM_TypeDef * Timer , char Channel , int voltage ) ;



