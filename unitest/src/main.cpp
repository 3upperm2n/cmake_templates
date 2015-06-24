#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "ToDo.h"
#include "compute.h"

int main(int argc, char *argv[])
{
	puts("compare:");
	int value = compare(1,2);
	if (value)
		puts("true");
	else 
		puts("false");

	puts("compute:");
	printf("%d\n", compute(1, 2));

	return 0;
}
