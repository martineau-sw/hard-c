#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person 
{
  char *name;
  int age;
  int height;
  int weight;
};

struct Person Person_create(char *name, int age, int height, int weight)
{
  struct Person who;
  who.name = strdup(name);
  who.age = age;
  who.height = height;
  who.weight = weight;

  return who;
}

void Person_print(struct Person who)
{
  printf("Person\t@[%p(%ld)]:\n", &who, sizeof(who));
  
  printf("who.name\t@[%p(%ld)]:\t%s\n", &who.name, sizeof(who.name), who.name);
  printf("who.age\t@[%p(%ld)]:\t%i\n", &who.age, sizeof(who.age), who.age); 
  printf("who.height\t@[%p(%ld)]:\t%d\n", &who.height, sizeof(who.height), who.height);
  printf("who.weight\t@[%p(%ld)]:\t%d\n\n", &who.weight, sizeof(who.weight), who.weight);
}

int main(int argc, char *argv[])
{
  struct Person joe = Person_create("Joe Alex", 32, 64, 140);
  struct Person frank = Person_create("Frank Blank", 20, 72, 180);

  Person_print(joe);
  Person_print(frank);

  joe.age += 20;
  joe.height -= 2;
  joe.weight += 40;

  frank.age += 20;
  
  Person_print(joe);
  Person_print(frank);

  return 0;
}