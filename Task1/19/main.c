#include <stdio.h>
#include "function.h"


int main()
{
	FILE *input, *output;

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

	int answer = whats_more(input); // -1 - not increasing, 1 - increasing, 0 - equally, -2 - error
	
	if (answer == 1)
	{
		fprintf(output, "More increasing sections\n");
		fclose(input);
		fclose(output);
		return 0;
	}
	else if (answer == -1)
	{
		fprintf(output, "More not increasing sections\n");
		fclose(input);
		fclose(output);
		return 0;
	}
	else if (answer == 0)
	{
		fprintf(output, "Equally\n");
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
}
