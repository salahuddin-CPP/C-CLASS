

#include <stdio.h>

int main()
{
	const int i=10;
	 int* ptr=&i; 

	(*ptr)++;

	printf("i now is %d\n",i);
}


	
