#include <stdio.h>

void print_addr_info(void *pointer);

int main(int argc, char *argv[])
{
  char *name = "Seth";
  unsigned short x = 1;
  unsigned short *short_indexer = (unsigned short*)name;
  char *char_indexer = name;

  printf("x is @%p with value %hu\n", &x, x);
  int i;
  
  for(i = 0, char_indexer = name; 
      // *(char_indexer) != '\0';
      i < 4;      
      char_indexer--, i++ ) {
    printf("%p: '%x\t'(%lu)\n", char_indexer, *char_indexer, sizeof(*char_indexer));
  }

  printf("---\n");

  for(char_indexer = name; 
    *(char_indexer) != '\0';
      char_indexer++ ) {
    short_indexer = (unsigned short*)char_indexer;
    print_addr_info(short_indexer);
  }
  
}

void print_addr_info(void *pointer)
{
  printf("@%p: *%x (%lu)", pointer, *pointer, sizeof(*pointer));
}
