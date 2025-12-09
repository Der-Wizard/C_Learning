#include <stdio.h>

//K&R C, Exercise 2.9

int CountBitsInNumber() {
	int input = 5; //pretend this number is a user input

	bitcount(input);
	bitcountOpt(input);
}

//suboptimal example
int bitcount(unsigned x) {
	int b;
	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;
	return b;
}

//optimal example
int bitcountOpt(unsigned x) {
	int b = 0;
	while (x != 0) {
		x &= (x - 1);
		b++;
	}
	return b;
}

//Explanation:
/*
In the first example bitcount, we move through each and every bit of the number to check if the
bits are set or not.
This is inefficient because we are moving through all of the bits depending on the wordsize
(32 to 64 bits depending on architecture).
In the second example bitcountOpt, we only move as long as there are any bit flags still open.
This is achieved my utilizing the &= operator with a x - 1 statement to continuesly delete the rightmost bit.
Take following iteration record:

input = 5 => in bit: 101

For the first algo we go like this:
	Iter1:
		x = 101
		x & 01 
			=> true; b++
		x >>= 1 = 010 
	Iter2:
		x & 01
			=> false;
		x >>= 1 = 001
	Iter3:
		x & 01
			=> true; b++
		x >>= 1 = 000
	End

The second algo goes like this:
	Iter1:
		x = 101
		x - 1 = 100
		x &= (x - 1) = 100
		b = 1
	Iter2:
		x = 100
		x - 1 = 011
		x &= (x - 1) = 000
		b = 2
	End

Lets take a bigger example:

input = 64 = 0100_0000

First Algo (brief):
	0100_0000
	0010_0000
	0001_0000
	0000_1000
	0000_0100
	0000_0010
	0000_0001 => & 01
	END
	b => 1

Second Algo:
	x = 1000_0000
	x - 1 = 0111_111
	x &= (x - 1) = 0000_0000
	b = 1
	END
	b => 1
*/