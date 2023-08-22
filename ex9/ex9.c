#include <stdio.h>

int main(int argc, char* argv[])
{
  unsigned short i = 0;

  while(i < 25)
  {
    printf("%hu\n", i++);
  }

  return 0;
}
