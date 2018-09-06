
#include <stdio.h>


#define board1 ARMBOARD
#define board2 BEAGLEBOARD
#define board3 ARDUINO

int main()
{
	printf("code before ifdef block\n");
#if defined board1  || !defined board2 || defined board3
	printf("any one board defined");
#endif

#ifndef board1
	printf("ARM board not defined ");
#endif

	printf("\ncode after ifdef block\n");

}


