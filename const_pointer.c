#include <stdio.h>

int main()
{
	int i=12;
	int arr[5];
	int *const ptr=&i; 
//	arr++;
	//ptr++;
	printf("i now is %d and arr =%p\n",*ptr,arr);
}

