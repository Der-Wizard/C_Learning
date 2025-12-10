#include <stdio.h>
#include <stdlib.h>

static int stopOnNewLine(int c) { return c == '\n'; }
static int stopNever(int c) { return 0; }

static char* readLineUntil(int (*stop)(int));

/// <summary>
/// Stops reading from the Standard Input once an EOF or \n appears.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
char* readLineFromInput(void)
{
	return readLineUntil(stopOnNewLine);
}

/// <summary>
/// Will only stop searching for text after an EOF appears.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
char* readTextFromInput(void)
{
	return readLineUntil(stopNever);
}

static char* readLineUntil(int (*stop)(int))
{
	int c;
	size_t current = 0;
	size_t size = 64;
	char* line = malloc(size);
	if (!line) {
		printf("Failed to allocate Memory\n");
		return 0;
	}

	while ((c = getchar()) != EOF && !stop(c)) {
		if (current + 1 > size) {
			size *= 2;
			char* tempPtr = realloc(line, size);
			if (tempPtr == NULL) {
				printf("Failed to allocate Memory\n");
				return 0;
			}
			line = tempPtr;
		}
		line[current++] = c;
	}

	line[current] = '\0';

	return line;
}