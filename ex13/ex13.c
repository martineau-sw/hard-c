#include <stdio.h>

int main(int argc, char *argv[])
{
  unsigned short i = 0;

  for(i = 0; i < argc; i++)
  {
    printf("arg %hu: %s\n", i, argv[i]);
  }

  char *states[] = { "CA", "WY", "OR", "TX"};
  unsigned short states_count = sizeof(states) / sizeof(char*);

  for(i = 0; i < states_count; i++)
  {
    printf("state %hu: %s\n", i, states[i]);
  }

  return 0;
}
