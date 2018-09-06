
#include <stdio.h>

int main()
{
	int no1,no2,sum,diff,pr,quo,rem;

	printf("enter no1 and no2 \n");
	scanf("%d %d ",&no1,&no2);

	sum=no1+no2;
	diff=no1-no2;
	pr=no1*no2;
	quo=no1/no2;
	rem=no1%no2;

	printf("sum=%d diff=%d pr=%d quo=%d rem=%d\n",sum,diff,pr,quo,rem);

}

