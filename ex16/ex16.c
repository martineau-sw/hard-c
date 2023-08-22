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
  printf("Person\t@[%p(%ld)]:\n", who, sizeof(*who));
  // Get values from pointers as a challenge

  // Type cast double pointer to assert appropriate  size 
  // so that the correct value is read
  
  char *name = *((char**)who); // == who->name

  // Person pointer is converted to char pointer
  // to allow for byte size memory offsets.

  int *age = (int*)((char*)who + 8); // == who->age
  int *height = (int*)((char*)who + 12); // == who->height
  int *weight = (int*)((char*)who + 16); // == who-> weight

  // Notice how the addresses are together in memory
  // and are distanced consistent with their size.
  
  printf("Name\t@[%p(%ld)]:\t%s\n", name, sizeof(name), name);
  printf("Age\t@[%p(%ld)]:\t%i\n", age, sizeof(*age), *age); 
  printf("Height\t@[%p(%ld)]:\t%d\n", height, sizeof(*height), *height);
  printf("Weight\t@[%p(%ld)]:\t%d\n\n", weight, sizeof(*weight), *weight);
}

int main(int argc, char *argv[])
{
  struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
  struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

  Person_print(joe);
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