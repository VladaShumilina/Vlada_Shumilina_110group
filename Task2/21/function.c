#include <stdio.h>
#include "function.h"

void shuffle(int *numbers,  int length)
{
	int i, j, c;

	for (i = 0; i < (length - 1) / 2; ++i)
	{
		for (j = 1 + i; j < length - i - 1; j += 2)
		{
			c = numbers[j];
			numbers[j] = numbers[j + 1];
			numbers[j + 1] = c;	
		}	
	}
}
