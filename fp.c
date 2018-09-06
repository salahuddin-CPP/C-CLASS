#include <stdio.h>

int add(int a, int b)
{
	return a+b;
}



int sub(int a, int b)
{
	return a-b;
}

int mul(int a, int b)
{
	return a*b;
}

int div(int a, int b)
{
	return a/b;
}



int main()
{
	int i=0,no1=45;
	int no2=5,sum=0;
	int (*fp[4])(int x,int y);
	
	fp[0]=add;
	fp[1]=sub;
	fp[2]=mul;
	fp[3]=div; 
	

	for(i=0;i<4;i++)
	printf("\n%d\n",(fp[i])(no1,no2));

	
}


