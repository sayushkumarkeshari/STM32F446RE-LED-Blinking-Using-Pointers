#include<stdio.h>

	unsigned int *rcc_cr=(unsigned int *)0x40023800;
	unsigned int *rcc_AHB1ENR=(unsigned int *)0x40023830;
	unsigned int *GPIOA_MODER=(unsigned int *)0x40020000;
	unsigned int *GPIOA_OTYPER=(unsigned int *)0x40020004;
	unsigned int *GPIOA_SPEEDR=(unsigned int *)0x40020008;
	unsigned int *GPIOA_ODR=(unsigned int *)0x40020014;
	void delay(long delay)
	{
		while(delay--);
	}
	int main()
	{
		*rcc_cr=0x00000001;
		*rcc_AHB1ENR=0x00000001;
	  *GPIOA_MODER=0x00000400;
	  *GPIOA_OTYPER=0x0000;
	  *GPIOA_SPEEDR=0x00000000;
		
		while(1)
		{
	  *GPIOA_ODR=0x0020;
			delay(500000);delay(500000);
		*GPIOA_ODR=0x0000;
			delay(500000);delay(500000);
		}
		
	return 0;
}