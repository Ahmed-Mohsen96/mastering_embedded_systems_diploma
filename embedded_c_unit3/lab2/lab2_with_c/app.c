typedef volatile unsigned int vuint32_t;

#include<stdint.h>

#define RCC_BASE     0x40021000
#define GPIOA_BASE   0x40010800

#define RCC_APB2ENR 	*(volatile uint32_t *) (RCC_BASE + 0x18)
#define GPIOA_CRH 		*(volatile uint32_t *) (GPIOA_BASE + 0x04)
#define GPIOA_ODR 		*(volatile uint32_t *) (GPIOA_BASE + 0x0c)
////////
#define RCC_IOPAEN  (1<<2)

typedef union {
	vuint32_t 		all_field;
	struct{
		vuint32_t	reserved:13;
		vuint32_t 	p_13:1;
	}Spin;
} U_R_ODR_t ;

volatile U_R_ODR_t*  R_ODR=  (volatile U_R_ODR_t*)(GPIOA_BASE+0x0c);

int main(void)
{
	int i;
	RCC_APB2ENR |= RCC_IOPAEN;
	GPIOA_CRH   &= 0xFF0FFFFF;
	GPIOA_CRH   |= 0x00200000;
	while(1){
		R_ODR->Spin.p_13=1;
		for(i=0;i<5000;i++);
		R_ODR->Spin.p_13=0;
		for(i=0;i<5000;i++);
	}
	return 0;
}