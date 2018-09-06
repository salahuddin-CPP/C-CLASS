#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned int i;

	scanf("%d",&i);
	
	if (i&0x01) 
	{
		i=i>>1;
		i=i|(1<<31);
	}
	printf("%u\n",i);
}

