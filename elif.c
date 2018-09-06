
#include <stdio.h>

//#define board1 ARM
#define board2 BBB


int main()
{
	printf("before ifdef block \n");

#if board1==ARM
	printf("ARM board defined\n");

#elif board2==BBB
	printf("BBB defined \n");

#endif

	printf("code after ifdef block\n");
}

