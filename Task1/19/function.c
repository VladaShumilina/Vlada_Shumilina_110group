#include <stdio.h>
#include "function.h"

int whats_more(FILE *input)
{
	int inc = 0; // quantity increasing sections
	int dec = 0; // quantity not increasing sections
	int cur, prev; // current number; previous number
	int is_increasing = 0; // -1 is not increasing; 1 is increasing
	int is_first = 1;

	int p;
	while ((p = fscanf(input, "%d", &cur)) == 1)
	{
		if (is_first == 1)
		{
			is_first = 0;
			prev = cur;
			continue;
		}	
		
		if ((cur > prev) && (is_increasing == -1 || is_increasing == 0))
		{
			++inc;
			is_increasing = 1;
		}
		else if ((cur <= prev) && (is_increasing == 1 || is_increasing == 0))
		{
			++dec;
			is_increasing = -1;
		}

		prev = cur;
	}

	if (p != EOF) return -2; // error

	if (inc > dec) return 1;
	else if (inc < dec) return -1;
	else if (inc == dec) return 0;
}
