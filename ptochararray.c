
#include <stdio.h>
int main()
{
	int *ptoarray;
	int arr[5]={1,2,3,4,5};
	int i;
	ptoarray=&arr[0];

	for(i=0;i<5;i++)
	{
		printf(" 0x%x  %d\n",ptoarray,*ptoarray);
		ptoarray++;
	}
}

