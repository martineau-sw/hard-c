#include <stdio.h>

int main(int argc, char* argv[])
{
  int i = 0;

  if(argc == 1)
  {
    printf("You have too few arguments.\n");
  }
  else if(argc > 1 && argc < 4)
  {
    printf("Here're your arguments:\n");

    for(i = 0; i < argc; i++)
    {
      printf("%s ", argv[i]);
    }
  }
  else
  {
    printf("You have too many arguments.\n");
  }

  return 0;
}
