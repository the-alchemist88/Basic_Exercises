#include "stm32f3xx.h"

//PB13
//AHB - 18. bit
//RCC->AHBENR
//GPIOx_MODER (Mode 13)
//GPIOx_ODR   (ODR13)

#define GPIOB_EN (1<<18) //enable GPIOB clock bus (0b 0000 0000 0000 0100 0000 0000 0000 0000)

#define MODER_13_OUT (1<<26) // 01-->output mode for 13. pin of B port(0b 0000 0100 0000 0000 0000 0000 0000 0000)

#define ODR_13_SET (1<<13) // PA13 output set to high (0b 0000 0000 0000 0000 0010 0000 0000 0000)

#define ODR_13_RESET (0<<13) //PA13 output set to low


int main(void){

	RCC->AHBENR |= GPIOB_EN;
	GPIOB->MODER |= MODER_13_OUT;


	while(1){
		GPIOB->ODR |= ODR_13_SET;
		for(int i=0;i<100000;i++){}
		GPIOB->ODR &= ODR_13_RESET;
		for(int i=0;i<100000;i++){}



	}


}
