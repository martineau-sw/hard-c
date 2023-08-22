#include <stdio.h>

int main(int argc, char *argv[])
{
  int areas[] = {10, 12, 13, 14, 20};
  char name[] = "Seth";
  char full_name[] = { 'S', 'e', 't', 'h', ' ', 'W', '.', ' ', 'M', 'a', 'r', 't', 'i', 'n', 'e', 'a', 'u', '\0' };

  printf("The size of an int: %ld\n", sizeof(int));
  printf("The size of areas (int[]): %ld\n", sizeof(areas));

  printf("Count of areas: %ld\n", sizeof(areas) / sizeof(int));

  printf("The size of an char: %ld\n", sizeof(char));
  printf("The size of name(char[]): %ld\n", sizeof(name));

  printf("Count of name: %ld\n", sizeof(name) / sizeof(char));

  printf("The size of full_name (char[]): %ld\n", sizeof(full_name));

  printf("Count of full_name: %ld\n", sizeof(full_name) / sizeof(char));
  printf("name: %s, full_name: %s", name, full_name);
  return 0;
  
}
