#include <stdio.h>
#include "DigitPaster.h"
#include "LongestLine.h"
#include "HelloWorld.h"
#include "NumberGuesser.h"

int main()
{
	int c;
	do {
		printf("Wähle aus welches Program du starten willst:\n");
		printf("1: DigitPaster\n");
		printf("2: LongestLine\n");
		printf("3: HelloWorld\n");
		printf("4: NumberGuesser\n");
		printf("0: Exit\n");
		printf("////////////////////////////////////////////////////////////\n");

		c = getchar();

		switch (c) 
		{
			case '1':
				playDigitPaster();
				break;
			case '2':
				playLongestLine();
				break;
			case '3':
				playHelloWorld();
				break;
			case '4':
				playNumberGuesser();
				break;
		}
		printf("//////////////////////////////////////////\n");

	} while (c != '0');

	printf("Thank you for playing!");
}