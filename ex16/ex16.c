#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int is_equal(char*, char*);
struct Person 
{
  char *name;
  int age;
  int height;
  int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight)
{
  struct Person *who = malloc(sizeof(struct Person));
  assert(who != NULL);
  
  who->name = strdup(name);
  who->age = age;
  who->height = height;
  who->weight = weight;

  return who;
}

void Person_destroy(struct Person *who)
{
  assert(who != NULL);

  free(who->name);
  free(who);
}

void Person_print(struct Person *who)
{
  char *name = (char*)&(*who);

  int *age = (int*)((char*)who + 8);
  int *height = &(who->height);
  int *weight = &(who->weight);

  printf("\nName@[%p(%ld)]: %s\n", name, sizeof(name), name);
  printf("\tAge@[%p(%ld)]: %i\n", age, sizeof(*age), *age); 
  printf("\tHeight@[%p(%ld)]: %d\n", height, sizeof(*height), *height);
  printf("\tWeight@[%p(%ld)]: %d\n", weight, sizeof(*weight), *weight);

//  is_equal(name, who->name);
}

int is_equal(char *str0, char *str1)
{
  int outcome = 1;
  int i = 0;
  printf("\n--- str test ---\n");
  printf("\nstr0@[%p(%ld)]: %s\n", str0, sizeof(str0), str0);
  printf("str1@[%p(%ld)]: %s\n", str1, sizeof(str1), str1);

  while(outcome)
  {
    outcome = str0[i] == str1[i];
    printf("\n\t[%i]", i);

    printf("\tstr0@[%p(%ld)]: %c", &str0[i], sizeof(str0[i]), str0[i]);
    printf("\tstr1@[%p(%ld)]: %c\n", &str1[i], sizeof(str1[i]), str1[i]);
    i++;
  }
  printf("\nname == who->name : %i\n", outcome);
  return outcome;
}

int main(int argc, char *argv[])
{
  struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
  struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

  printf("@[%p(%ld)]: %s\n", joe, sizeof(*joe), (char*)*joe);
//  Person_print(joe);
  
  printf("\tjoe->name@[%p(%ld)]: %s", &joe->name, sizeof(joe->name), joe->name);
//  printf("@[%p(%ld)]:\n", frank, sizeof(*frank));
  Person_print(frank);

  joe->age += 20;
  joe->height -= 2;
  joe->weight += 40;

  frank->age += 20;
  
  Person_print(joe);
  Person_print(frank);

  Person_destroy(joe);
  Person_destroy(frank);

  return 0;
}