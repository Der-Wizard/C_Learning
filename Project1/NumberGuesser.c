#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXLINE 4

static int secret = 0;
static int number = 0;

static void ng_readNumber(void);
static void ng_generateSecretNumber(void);

int playNumberGuesser() 
{
	int attempts;

	attempts = 0;
	ng_generateSecretNumber();
	printf("A secret number has been created. Can you try and guess it?\n");
	printf("Press Ctrl + Z and Enter to terminate Game\n");
	printf("//////////////////////////////////////////\n");

	while (1)
	{
		ng_readNumber();

		++attempts;

		printf("\n");

		if (number == EOF) {
			printf("You gave up like a pus pus\n");
			return 0;
		}
		if (number == secret) {
			printf("Hurray!!! You are right!\n");
			break;
		}
		else if (number > secret) {
			printf("Nope, the secret number is lower\n");
		}
		else if (number < secret) {
			printf("Nope, the secret number is higher\n");
		}
	}

	printf("It took you %d attempts to get it right!\n", attempts);
	return 0;
}

static void ng_readNumber(void)
{
	int c;

	number = 0;

	while ((c=getchar()) != EOF) 
	{
		if (c == '\n')
			break;
		if (c >= '0' && c <= '9') 
			number = number * 10 + (c - '0'); //Example: 15 saved, 5 pressed => 15 * 10 => 150 + 5 => 155
		else {} //invalid, skip
	}

	if (c == EOF)
		number = EOF;
}

static void ng_generateSecretNumber(void) 
{
	time_t t = time(NULL);
	srand((unsigned int)t); //Seed, else will produce same sequence on every run
	secret = rand() % 101; //0-100
}