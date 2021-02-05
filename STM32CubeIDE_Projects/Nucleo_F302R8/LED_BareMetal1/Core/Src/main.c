
#include <stdint.h>
#include <stdbool.h>

#define RCC_BASE_ADDR 0x40021000ul

#define RCC_AHB2_EN_OFFSET 0x14ul

#define RCC_AHB2_EN_ADDR (RCC_BASE_ADDR+RCC_AHB2_EN_OFFSET)


#define GPIOB_BASE_ADDR 0x48000400ul

#define GPIOB_MODER_OFFSET 0x00ul

#define GPIOB_MODER_REG_ADDR (GPIOB_BASE_ADDR+GPIOB_MODER_OFFSET)


#define GPIOB_ODR_OFFSET  0x14ul

#define GPIOB_ODR_REG_ADDR (GPIOB_BASE_ADDR+GPIOB_ODR_OFFSET)


int main(void){

	bool LED_STATE=false;

	uint32_t *p1= (uint32_t*) RCC_AHB2_EN_ADDR;

	uint32_t *p2= (uint32_t*) GPIOB_MODER_REG_ADDR;

	uint32_t *p3= (uint32_t*) GPIOB_ODR_REG_ADDR;


	*p1 |=(1<<18); //enable GPIOB clock bus (AHB)
	*p2 |=(1<<26); //output mode for 13. pin of B port(mode register)

	while(1){
		*p3^=(1<<13);// PA13 pin output set to high
		LED_STATE ^= true;
		for(int i=0;i<1000000;i++){};
	}
}


