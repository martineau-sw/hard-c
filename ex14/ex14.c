#include <stdio.h>
#include <ctype.h>

// forward declarations
void print_letters(char arg[]);

void print_arguments(int argc, char *argv[])
{
  for(unsigned short i = 0; i < argc; i++)
  {
    print_letters(argv[i]);
  }
}

void print_letters(char arg[])
{
  for(unsigned short i = 0; arg[i] != '\0'; i++)
  {
    char ch = arg[i];

    if(isalpha(ch) || isblank(ch))
    {
      printf("'%c' == %hu ", ch, ch);
    }
  }

  printf("\n");
}

int main(int argc, char *argv[])
{
  print_arguments(argc, argv);
  return 0;
}