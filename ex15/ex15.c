#include <stdio.h>

int main(int argc, char *argv[])
{
  short ages[] = { 23, 43, 12, 89, 2 };
  char *names[] = { "Alan", "Frank", "Mary", "John", "Lisa" };

  unsigned short ages_count = sizeof(ages) / sizeof(short);
  unsigned short i = 0;

  for(i = 0; i < ages_count; i++)
  {
    printf("%s has %i years alive.\n", names[i], ages[i]);
  }

  printf("---\n");

  short *cur_age = ages;
  char **cur_name = names;

  for(i = 0; i < ages_count; i++)
  {
    printf("%s is %i years old.\n", *(cur_name + i), *(cur_age + 1));
  }

  printf("---\n");

  for(i = 0; i < ages_count; i++)
  {
    printf("%s is %i years old again.\n", cur_name[i], cur_age[i]);
  }

  printf("---\n");

  for(cur_name = names, cur_age = ages; (cur_name - names) < ages_count; cur_name++, cur_age++)
  {
    printf("%s has lived %i years so far.\n", *cur_name, *cur_age);
    printf("%p has lived %p years so far.\n", cur_name, cur_age);
  }
}
