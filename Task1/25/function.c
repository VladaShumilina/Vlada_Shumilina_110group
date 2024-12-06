#include <stdio.h>


int max_distance(FILE *input)
{
	int cur_index = 0; // index of the current number
	int prev_index = 0; // index of the previous max 
	int next, cur, prev; //next number; current number; previous number
	int max_distance = -1;

	if (fscanf(input, "%d", &prev) == EOF) return max_distance;
	if (fscanf(input, "%d", &cur) == EOF) return max_distance;

	cur_index = 2;
	
	int p;
	while ((p = fscanf(input, "%d", &next)) == 1)
	{		
		if ((cur > prev) && (cur > next))
		{
			if (prev_index != 0)
			{
				if (cur_index - prev_index - 1 > max_distance) max_distance = cur_index - prev_index - 1;
			}
			prev_index = cur_index;
		}
		
		++cur_index;
		prev = cur;
		cur = next;
	}
	if (p == EOF) return max_distance;
	return -2;
}
