#include <stdio.h>

int playDigitPaster() {
	int c, i, nwhite, nother;
	int ndigit[10];

	nwhite = nother = 0;
	for (i = 0; i < 10; ++i)
		ndigit[i] = 0;

	printf("Type in any amount of letters, numbers, new lines and co.\n");
	printf("This program will evaluate the different digits having been pressed\n");
	printf("Press Ctrl + Z and Enter to get the results\n");
	printf("//////////////////////////////////////////\n");

	while ((c = getchar()) != EOF)
		if (c >= '0' && c <= '9')
			++ndigit[c - '0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;

	printf("digits =");
	for (i = 0; i < 10; i++)
		printf(" %d", ndigit[i]);
	printf(", white space = %d, other = %d\n",
		nwhite, nother);

	return 0;
}