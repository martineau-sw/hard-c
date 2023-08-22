#include <stdio.h>
#include <limits.h>

int main(int argc, char* argv[])
{

	int distance = 100;
	float power = 2.345f;
	double super_power = 56789.4532;
	char initial = 'A';
	char first_name[] = "Seth";
	char last_name[] = "Martineau";
	
	printf("You are %d miles away.\n", distance);
	printf("You have %f levels of power.\n", power);
	printf("You have %f awesome super powers.\n", super_power);
	printf("I have an initial %c.\n", initial);
	printf("I have a first name %s.\n", first_name);
	printf("I have a last name %s.\n", last_name);
	printf("My whole name is %s %c %s.\n", first_name, initial, last_name);
	
	int bugs = 100;
	double bug_rate = 1.2;

	printf("You have %d bugs at the imaginary rate of %f.\n", bugs, bug_rate);
	
	unsigned long universe_of_defects = 1L * 1024L * 1024L * 1024L * 1024L * 1024L * 1024L * 1024L;
	printf("The entire universe has %ld bugs.\n", universe_of_defects);
	printf("LONG_MIN: %ld\nLONG_MAX: %ld\n", (long)LONG_MIN, (long)LONG_MAX);
	printf("ULONG_MAX: %lu\n", (unsigned long)ULONG_MAX);

	char nul_byte = '\0';
	int care_percentage = bugs * nul_byte;
	printf("Which means you should care %d%%.\n", care_percentage);
	
	return 0;
}
