#include <stdio.h>
#define EXAMINE printf("value of x = %d and y = %d.\n", x, y)
 
void incr(int, int);
int main(void)
{
    int x = 5, y = 6;
 
    x++;
    y++;
    EXAMINE;
    incr(++x, y++);
    EXAMINE;
 
    ++x;
    ++y;
    EXAMINE;
}
 
void incr(int x, int y)
{
    EXAMINE;
    x++;
    y++;
    EXAMINE;
}
