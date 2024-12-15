#include <stdio.h>
#include "function.h"

int is_happy(int *numbers,  int length)
{
	int i, j, is_happy, cur_sum, sum;
	
	sum = 0;
	for (i = 0; i < length; ++i)
	{
		sum += numbers[i];
	}
	

	is_happy = 0;
	cur_sum = 0;
	for (i = 0; i < length - 1; ++ i)
	{
		cur_sum += numbers[i];
		if (cur_sum == sum - cur_sum)
		{
			is_happy = 1;
			break;
		}
	}

	if (is_happy)
	{	
		return 1;
	}
	return 0;
}
