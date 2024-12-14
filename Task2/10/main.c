#include <stdio.h>
#include "function.h"


int main(void)
{
	FILE *input, *output;
	int length, new_length, i;
	int numbers[100];
	int p;
	
	input = fopen("input.txt", "r");
	if (!input)
	{
		printf("Couldn't open the file: input.txt\n");
		return -1;
	}

	output = fopen ("output.txt", "w");
	if (!output)
	{
		printf("Couldn't open the file: output.txt\n");
		fclose(input);
		return -1;
	}
	
	if (fscanf(input, "%d", &length) != 1)
	{
		printf("Invalid data\n");
		fclose(input);
		fclose(output);	
		return -1;
	}
	
	p = 1;	
	for (i = 0; i < length; ++i)
	{
		if ((p = fscanf(input, "%d", &numbers[i])) != 1)
		{
			break;
		}
	}

	if (p == 0)
	{
		printf("Invalid data\n");
		fclose(input);
		fclose(output);
		return -1;
	}

	if (p == EOF)
	{
		printf("Invalid length\n");
		fclose(input);
		fclose(output);
		return -1;
	}

	new_length = delete_negative(numbers, length);
	fprintf(output, "New length: %d\n", new_length);

	for (i = 0; i < new_length; ++i)
	{
		fprintf(output, "%d ", numbers[i]);
	}
	fprintf(output, "\n");

	fclose(input);
	fclose(output);
	return 0;
}
