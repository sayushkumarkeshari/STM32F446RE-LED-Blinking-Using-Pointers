#include<stdio.h>

	volatile unsigned int *rcc_cr=(unsigned int *)0x40023800;
	volatile unsigned int *rcc_AHB1ENR=(unsigned int *)0x40023830;
	volatile unsigned int *GPIOA_MODER=(unsigned int *)0x40020000;
	volatile unsigned int *GPIOA_OTYPER=(unsigned int *)0x40020004;
	volatile unsigned int *GPIOA_SPEEDR=(unsigned int *)0x40020008;
	volatile unsigned int *GPIOA_ODR=(unsigned int *)0x40020014;
	void delay(volatile long delay)
	{
		while(delay--);
	}
	int main()
	{
		*rcc_cr |= (1<<0);// 0x00000001;
		*rcc_AHB1ENR |=(1<<0); //0x00000001;
		*GPIOA_MODER &= ~(3<<10);
	  *GPIOA_MODER |=(1<<10); //0x00000400;
	  *GPIOA_OTYPER=0x0000;
	  *GPIOA_SPEEDR=0x00000000;
		
		while(1)
		{
	  *GPIOA_ODR |=(1<<5);
			delay(500000);delay(500000);
		*GPIOA_ODR &=~(1<<5);
			delay(500000);delay(500000);
		}
		
	return 0;
}
