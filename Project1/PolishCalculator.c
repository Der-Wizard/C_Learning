#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP	100
#define NUMBER	'0'

static int getop(char[]);
static void push(double);
static double pop(void);
static double popNoWarning(void);
static void printHelp(void);

int playCalculator() {
	int type;
	double op1;
	double op2;
	char s[MAXOP];

	printHelp();

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '*':
			push(pop() * pop());
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			op1 = pop();
			if (op2 != 0.0)
				push(op1 - op2 * (int)(op1 / op2));
			else
				printf("error: zero divisor\n");
			break;
		case 's':
			op1 = pop();
			printf("Top operator:\t%.8g\n", op1);
			push(op1);
			break;
		case 'd':
			op1 = pop();
			printf("Top operator duplicated:\t%.8g\n", op1);
			push(op1);
			push(op1);
			break;
		case 'c':
			printf("Clearing stack\n");
			while (op1 = popNoWarning())
				printf("\t%.8g\n", op1);
			break;
		case 'q':
			op2 = pop();
			op1 = pop();
			push(op2);
			push(op1);
			printf("Swapped both operators\n");
			break;
		case 'h':
			printHelp();
			while (popNoWarning())
				;
			break;
		case 'x':
			push(sin(pop()));
			break;
		case 'y':
			push(cos(pop()));
			break;
		case 't':
			push(tan(pop()));
			break;
		case 'p':
			op2 = pop();
			op1 = pop();
			if (op2 <= 0.0)
			{
				printf("error: exponent cannot be 0 or lower.\n");
				break;
			}
			if (op1 == 0.0) {

				printf("error: base cannot be 0.\n");
				break;
			}
			push(pow(op1, op2));
			break;
		case 'e':
			push(exp(pop()));
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}

	return 0;
}

static void printHelp(void) {
	printf("Type in any numbers and operators in reverse polish notation. I.e.: 10 10 +\n");
	printf("Operators:\n");
	printf("\t+\t:\t Addition\n");
	printf("\t-\t:\t Substraction\n");
	printf("\t*\t:\t Multiplication\n");
	printf("\t/\t:\t Division\n");
	printf("\t%\t:\t Modulus\n");
	printf("\tp\t:\t Power\n");
	printf("\te\t:\t Exponential\n");
	printf("\tx\t:\t Sin\n");
	printf("\ty\t:\t Cos\n");
	printf("\tt\t:\t Tan\n");
	printf("\ts\t:\t Show top operator\n");
	printf("\tc\t:\t Clear all operators before\n");
	printf("\td\t:\t Duplicate last operator\n");
	printf("\tq\t:\t Swap last two operators\n");
	printf("\th\t:\t Show operator info list\n");
}

#define MAXVAL 100

static int sp = 0;
static double val[MAXVAL];

static void push(double f) {
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

static double pop(void) {
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

static double popNoWarning(void) {
	if (sp > 0)
		return val[--sp];
	return 0.0;
}

#include <ctype.h>

static int getch(void);
static void ungetch(int);

static int getop(char s[]) {
	int i, c;
	i = 0;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.') {
		if (c == '-') {	//collect negative sign
			s[i] = c;
			if (!isdigit(s[++i] = c = getch())) {
				ungetch(c);
				return s[0]; //Not a number
			}
		}
		else {
			return c; //Not a number
		}
	}
	if (isdigit(c))	//collect integer part
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')	//collect fraction part
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFSIZE 100

static char buf[BUFSIZE];
static int bufp;

static int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

static void ungetch(int c) {
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}