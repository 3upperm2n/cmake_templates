#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include "ToDo.h"

int compare(int a, int b)
{
	int v = 0;	
	if(a < b)
		v = 1;
	return v;	
}
