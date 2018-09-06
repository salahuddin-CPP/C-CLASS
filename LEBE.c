#include <stdio.h>

int main()
{
	unsigned short int i=0x7825;
	unsigned short int res;
	

	res=(i<<8)|(i>>8);


	printf("0x%x\n",res);
}


