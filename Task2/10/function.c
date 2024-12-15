#include <stdio.h>
#include "function.h"

int delete_negative(int *numbers,  int length)
{
	int i, j;
	int step;
	
	step = 0;
	for (i = 0; i < length; ++i)
	{
		if (numbers[i] < 0)
		{
			++step;	
		}
		else
		{
			numbers[i - step] = numbers[i];
		}
	}

	return length - step;
}
