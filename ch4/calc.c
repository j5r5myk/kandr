#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
double check(void);

/* reverse polish calculator!!!!*/

int main(void) {
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {

		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: can't divide by zero yo!\n");
			break;
		case '%': //bad with negatives
			op2 = pop();
			push((int)pop() % (int) op2);
			break;
		case 'p': //print but do not pop
				if (check() > 0)
					printf("top of stack: %g\n", check());
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
}

#define MAXVAL 100 /* maximum size of stack */

int sp = 0;
double val[MAXVAL];

//push
void push(double f) {
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full ay\n");
}

double pop(void) {
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

//return top but do not pop
double check(void) {
	if (sp > 0)
		return val[sp-1];
	else
		return 0.0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

//getop
//modify to not need ungetch
//use internal static variable
int getop(char s[]) {
	int i, c;
	static int buf;
	while ((s[0] = c= getch()) == ' ' || c == '\t') //ignore whitespace
		;
	s[1] = '/0'; //incase length == 1
	if (!isdigit(c) && c != '.')
		return c; //return letters and other stuff for commands
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch())) //set s[] = to string of digits
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch())) //include digits after decimal
			;
	s[i] = '\0';
	if (c != EOF) //this is for when there is another number next
		ungetch(c);
	return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {//calls from the buffer before input
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {//puts things on the buffer
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
