#include <stdio.h>
#include <ctype.h>
#define SIZE 100

//int getint(int *);
int getch(void);
void ungetch(int);


int main(void) {

	int n, a[SIZE], getint(int *), i;
	float getfloat(float *);

	for (n = 0; n < SIZE && getint(&a[n]) != EOF; n++)
		;
	
	for (n = 0; n < SIZE && getfloat(&a[n]) != EOF; n++)
		;

	i = 0;
	while (i <= n) {
		printf("%d", a[i]);
		i++;
	}	
	printf("\n");

	return 0;
}

float getfloat(float *pn) {
	int c, sign, fraction;
	//meh


}

int getint(int *pn) {
	int c, sign;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c!= '-') {
		ungetch(c); //put it on the buffer list. but why would you want to read it again??
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c== '-') {
		c = getch(); //get first digit after sign
		if (!isdigit(c))
			//ungetch(c);
			ungetch(sign == 1 ? '+' : '-');
			return 0;
	}
	
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;

}


#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {//calls from the buffer before input
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {//puts things on the buffer
	if (bufp >= BUFSIZE) {
		printf("bufp = %d\n", bufp);
		printf("ungetch: too many characters\n");
	}
	else
		buf[bufp++] = c;
}
