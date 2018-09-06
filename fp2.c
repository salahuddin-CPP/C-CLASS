#include <stdio.h>

float average(int j,int k)
{
	float res=0;
	 res=(float)(j+k)/2;

	return res;
}

int main()
{
	float f;
	float (*fp)(int no1,int no2);
	
	fp=average;
	//f=*fp(23,24);
	printf("%f\n",fp(23,24));

}








