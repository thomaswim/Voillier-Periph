//driver.c 
#include "stm32f10x.h"


int main ( void )
{
RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4) ;
}
