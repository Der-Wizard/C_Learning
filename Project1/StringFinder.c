#include <stdio.h>
#include <stdlib.h>
#include "ReadTextFromLine.h"
#include "ReadNumberFromLine.h"

int playStringFinder(void) {
	printf("First print an example text that you wish to be scanned!\n");
	printf("Confirm with Ctrl + Z and Enter");
	printf("//////////////////////////////////////////\n");

	char* textInput = readTextFromInput();

	printf("//////////////////////////////////////////\n");
	printf("Great! Now input the pattern you wish to search for!\n");
	printf("Confirm with Ctrl + Z and Enter or just Enter");
	printf("//////////////////////////////////////////\n");

	char* patternInput = readLineFromInput();

	printf("//////////////////////////////////////////\n");
	printf("Select an option:\n");
	printf("0: Find all occurences\n");
	printf("1: Find left most occurence index\n");
	printf("2: Find right most occurence index\n");

	int input = readNumberFromInput();

	switch (input) {
		case 0: {
			int occurences = FindOccurencesOfPatternInText(textInput, patternInput);
			printf("There where %d occurences of the pattern in the provided text!\n", occurences);
			break;
		}
		case 1: {
			int index = FindLeftMostOccurenceOfPatternInText(textInput, patternInput);
			if (index == -1)
			{
				printf("No pattern was found\n");
				break;
			}

			printf("Found pattern occurence at: %d\n", index);
			break;
		}
		case 2: {
			int index = FindRightMostOccurenceOfPatternInText(textInput, patternInput);
			if (index == -1)
			{
				printf("No pattern was found\n");
				break;
			}

			printf("Found pattern occurence at: %d\n", index);
			break;
		}
	}

	free(patternInput);
	free(textInput);
}

static int FindLeftMostOccurenceOfPatternInText(char* source, char* pattern) 
{
	int sourceI, matchI, patternI, index;

	index = -1;

	for (sourceI = 0; source[sourceI] != '\0'; sourceI++)
	{
		for (matchI = sourceI, patternI = 0;
			(source[matchI] != '\0') && (source[matchI] == pattern[patternI]);
			matchI++, patternI++)
			;
		if (patternI > 0 && pattern[patternI] == '\0') {
			index = sourceI;
			break;
		}
	}

	return index;
}

static int FindRightMostOccurenceOfPatternInText(char* source, char* pattern) 
{
	int sourceI, matchI, patternI, index;

	index = -1;

	int sourceLim = 0;
	while (source[sourceLim] != '\0')
		++sourceLim;

	int patternLim = 0;
	while (pattern[patternLim] != '\0')
		++patternLim;
	--patternLim; //Ignoring '\0'

	if (sourceLim == 0 || patternLim == 0)
		return index;

	for (sourceI = sourceLim; sourceI >= 0; sourceI--)
	{
		for (matchI = sourceI, patternI = patternLim;
			(matchI >= 0) && (patternI >= 0) && (source[matchI] == pattern[patternI]);
			matchI--, patternI--)
			;
		if (patternI < 0) {
			index = sourceI - patternLim;
			break;
		}
	}

	return index;
}

static int FindOccurencesOfPatternInText(char* source, char* pattern) 
{
	int sourceI, matchI, patternI, occurences;

	occurences = 0;

	for (sourceI = 0; source[sourceI] != '\0'; sourceI++)
	{
		for (matchI = sourceI, patternI = 0; 
			(source[matchI] != '\0') && (source[matchI] == pattern[patternI]);
			matchI++, patternI++)
			;
		if (patternI > 0 && pattern[patternI] == '\0')
			++occurences;
	}

	return occurences;
}