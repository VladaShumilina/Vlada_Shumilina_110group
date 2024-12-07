#include <stdio.h>
#include "function.h"

int is_x(FILE *input, double x)
{
	double cur;
	double epsilon = 0.0001;
	
	int p;
	while ((p = fscanf(input, "%lf", &cur)) == 1)
	{		
		if ((x - epsilon < cur) && (x + epsilon > cur)) return 1;
	}

	if (p == EOF) return 0;
	return -1;
}
