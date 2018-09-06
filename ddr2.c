
#include <stdio.h>
void print_strings(char a[][5]);
int main()
{
	char a[5][5]={{"hi"},{"howw"},{"are"},{"you"},{"cmgn"}};
	int i,j;

	print_strings(a);


/*
	for(i=0;i<5;i++)
	{
		printf("\n");
		for(j=0;j<5;j++)
		printf("%c",a[i][j]);
	}*/
}
void print_strings(char a[][5])
{
	int i,j;
	for(i=0;i<5;i++)
	{
	for(j=0;a[i][j]!='\0';j++)
	printf("%c",a[i][j]);
	printf("\n");
	}
}	
	
