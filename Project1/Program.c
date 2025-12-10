#include <stdio.h>
#include "DigitPaster.h"
#include "LongestLine.h"
#include "HelloWorld.h"
#include "NumberGuesser.h"
#include "ReadNumberFromLine.h"
#include "CountingBitsInNumber.h"
#include "StringFinder.h"

int main()
{
	int input;
	do {
		printf("Wähle aus welches Program du starten willst:\n");
		printf("1: DigitPaster\n");
		printf("2: LongestLine\n");
		printf("3: HelloWorld\n");
		printf("4: NumberGuesser\n");
		printf("5: BitCounter\n");
		printf("6: PatternFinder\n");
		printf("0: Exit\n");
		printf("////////////////////////////////////////////////////////////\n");

		input = readNumberFromInput();

		switch (input) 
		{
			case 1:
				playDigitPaster();
				break;
			case 2:
				playLongestLine();
				break;
			case 3:
				playHelloWorld();
				break;
			case 4:
				playNumberGuesser();
				break;
			case 5:
				playBitCounter();
				break;
			case 6:
				playStringFinder();
				break;
		}
		printf("//////////////////////////////////////////\n");

	} while (input != 0);

	printf("Thank you for playing!");
}