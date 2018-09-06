#include <stdio.h>
#include <stdlib.h>

inline int square(int x) { return x*x; }

int main()
{
  int x = 81/square(4);
  printf("result x is %d\n", x);
  return 0;
}
