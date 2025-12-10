#include <stdio.h>

int readNumberFromInput(void)
{
	int c;

	int number = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == '\n')
			break;
		if (c >= '0' && c <= '9')
			number = number * 10 + (c - '0'); //Example: 15 saved, 5 pressed => 15 * 10 => 150 + 5 => 155
		else {} //invalid, skip
	}

	if (c == EOF)
		number = EOF;

	return number;
}