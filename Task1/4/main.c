#include <stdio.h>
#include "function.h"


int main(void)
{
	FILE *input, *output;
	int answer;
	double x;
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
	
	printf("Print the number X:\n");
	if (scanf("%lf", &x) != 1)
	{
		printf("Invalid value of X\n");
		fclose(input);
		fclose(output);
		return -1;
	}

	answer = is_x(input, x); // 1 - yes; 0 - no; -1 - error
	
	if (answer == -1)
	{
		printf("Invalid data\n");
		fclose(input);
		fclose(output);
		return -1;
	}
	else if (answer == 1)
	{
		fprintf(output, "Yes\n");
		fclose(input);
		fclose(output);
		return 0;
	}
	else if (answer == 0)
	{
		fprintf(output, "No\n");
		fclose(input);
		fclose(output);
		return 0;
	}
}
