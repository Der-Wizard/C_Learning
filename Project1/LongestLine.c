#include <stdio.h>

#define MAXLINE 1000

static int max;
static char line[MAXLINE];
static char longest[MAXLINE];

static int getline(void);
static void copy(void);

int playLongestLine()
{
	int len;
	extern int max;
	extern char longest[];

	printf("Type in any amounts of lines in the console\n");
	printf("This program will evaluate the longest line and reprint it\n");
	printf("Press Ctrl + Z and Enter to get the results\n");
	printf("//////////////////////////////////////////\n");

	max = 0;
	while ((len = getline()) > 0)
		if (len > max)
		{
			max = len;
			copy();
		}

	if (max > 0)
		printf("The longest line is:\n%s", longest);

	return 0;
}

static int getline(void)
{
	int c, i;
	extern char line[];

	for (i = 0; i < MAXLINE - 1
		&& (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;

	if (c == '\n')
	{
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

static void copy(void)
{
	int i;
	extern char line[], longest[];

	i = 0;
	while ((longest[i] = line[i]) != '\0')
		++i;
}