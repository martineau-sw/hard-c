#include <stdio.h>

int main(int argc, char *argv[])
{
  int numbers[4] = { 0 };
  char name[5] = { 'A' };

  printf("numbers: %d %d %d %d\n", 
    numbers[0],
    numbers[1],
    numbers[2],
    numbers[3]);

  printf("name each: %c %c %c %c %c\n",
    name[0],
    name[1],
    name[2],
    name[3],
    name[4]);

  printf("name: %s\n", name);

  numbers[0] = 1;
  numbers[1] = 2;
  numbers[2] = 3;
  numbers[3] = 4;

  name[0] = 'S';
  name[1] = 'e';
  name[2] = 't';
  name[3] = 'h';
  name[4] = '\0';


  printf("numbers: %d %d %d %d\n", 
    numbers[0],
    numbers[1],
    numbers[2],
    numbers[3]);

  printf("name each: %c %c %c %c %c\n",
    name[0],
    name[1],
    name[2],
    name[3],
    name[4]);

  printf("name: %s\n", name);


  char *another = "Seth";

  printf("another: %s\n", another);

  printf("another each: %c %c %c %c %c\n", 
    another[0],
    another[1],
    another[2],
    another[3],
    another[4]);

  return 0;
}
