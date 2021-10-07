//driver.c 
#include "stm32f10x.h"
#include "Driver_GPIO.h"


void MyGPIO_Init ( MyGPIO_Struct_TypeDef * GPIOStructPtr) 
	{
		if ( GPIOStructPtr -> GPIO_Pin >= 7 ){
			GPIOStructPtr -> GPIO -> CRH = GPIOStructPtr -> GPIO ->CRH &~ (0xF<<GPIOStructPtr ->GPIO_Pin * 4);
			GPIOStructPtr -> GPIO -> CRH = GPIOStructPtr -> GPIO ->CRH |(GPIOStructPtr -> GPIO_Conf<<GPIOStructPtr ->GPIO_Pin * 4); 
		}else{
			GPIOStructPtr -> GPIO -> CRL = GPIOStructPtr -> GPIO ->CRL &~ (0xF<< GPIOStructPtr ->GPIO_Pin * 4);
			GPIOStructPtr -> GPIO -> CRL = GPIOStructPtr -> GPIO ->CRL |(GPIOStructPtr -> GPIO_Conf<<GPIOStructPtr ->GPIO_Pin * 4); 
		}
	}

int MyGPIO_Read ( GPIO_TypeDef * GPIO , char GPIO_Pin ) 
{
		return (GPIO -> IDR & (0x1<<GPIO_Pin));
	}

void MyGPIO_Set ( GPIO_TypeDef * GPIO , char GPIO_Pin ){
		GPIO->BSRR = (0x01<<GPIO_Pin);
}
void MyGPIO_Reset ( GPIO_TypeDef * GPIO , char GPIO_Pin ){
		GPIO->BRR = (0x01<<GPIO_Pin);
}

void MyGPIO_Toggle ( GPIO_TypeDef * GPIO , char GPIO_Pin ){
		if(MyGPIO_Read(GPIO , GPIO_Pin))
			MyGPIO_Reset(GPIO , GPIO_Pin );
		else {
			MyGPIO_Set(GPIO , GPIO_Pin );
	}
		
}

