#include <stdio.h>

int main()
{
	int i=10;	

	const int* const ptr=&i;

//	(*ptr)++;
	ptr++;
}




