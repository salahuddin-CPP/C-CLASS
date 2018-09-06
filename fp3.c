#include <stdio.h>

void add(void)
{
	printf("add");
}



void sub(void)
{
	printf("sub");
}

void mul(void)
{
	printf("mul");
}

void div(void)
{
	printf("div");
}



int main()
{
	int i=0,no1=45;
	int no2=5,sum=0;
	void (*fp[4])(void);
	
	fp[0]=add; fp[1]=sub; fp[2]=mul; fp[3]=div;
	

	for(i=0;i<4;i++)
	printf("\n\n",(*fp[i])());

	
}








