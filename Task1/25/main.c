#include <stdio.h>
#include "function.h"


int main()
{
	FILE *input, *output;
	int answer;

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

	answer = max_distance(input); // -1 - no local maximums; -2 - error
	
	if (answer == -1)
	{
		fprintf(output, "No two local maximums\n");
		fclose(input);
		fclose(output);
		return 0;
	}
	else if (answer == -2)
	{
		printf("Invalid data\n");
		fclose(input);
		fclose(output);
		return -1;
	}
	else
	{
		fprintf(output, "%d\n", answer);
		fclose(input);
		fclose(output);
		return 0;
	}
}
