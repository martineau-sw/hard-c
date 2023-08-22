#include <stdio.h>

int main(int argc, char *argv[])
{
  if(argc != 2) 
  {
    printf("Please pass in one argument.");
    return 1;
  }

  unsigned short i = 0;

  while(argv[1][i] != '\0')
  {

    char c = argv[1][i++];

    if(c < 65) continue;
    if(c < 97) c += 32;
    switch(c)
    {
      case 'a':
      case 'i':
      case 'o':
      case 'u':
      case 'e':
        printf("%c is a vowel.\n", c);
        break;
      default:
        printf("%c is not a vowel\n", c);
        break;
    }
  }

  return 0;
}
