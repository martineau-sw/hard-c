#include <stdio.h>

/* This is a comment. */
int main(int argc, char* argv[]) 
{
	int distance = 100;

	// This is also a comment.
	printf("You are %d miles away.\n", distance);
	printf("The char for distance is '%c.'\n", distance);
	printf("This is \%f: %f\n", distance, distance);
	printf("2 * %i = %i\n", distance, 2 * distance);
	printf("2 * (%c + 1) = %c\n", distance, 2 * (distance + 1));
	return 0;
}
