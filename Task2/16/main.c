#include <stdio.h>
#include <stdlib.h>
#include "function.h"


int main(void)
{
	FILE *input, *output;
	int length, answer, i;
	int *numbers;
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

	if (length <= 0)
	{
		printf("Invalid data\n");
		fclose(input);
		fclose(output);
		return -1;
	}

	numbers = malloc(length * sizeof(int));

	if (!numbers)
	{
		printf("Memory error\n");
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
		free(numbers);
		return -1;
	}

	if (p == EOF)
	{
		printf("Invalid length\n");
		fclose(input);
		fclose(output);
		free(numbers);
		return -1;
	}

	answer = is_happy(numbers, length); // 0 - not happy; 1 - happy

	if (answer)
	{
		fprintf(output, "Happy\n");
	}
	else
	{
		fprintf(output, "Not happy\n");
	}
	
	free(numbers);
	fclose(input);
	fclose(output);
	return 0;
}
