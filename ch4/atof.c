#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

int power(int, int);

/*a bad calculator*/
int main(void) {
	double sum, atof(char []);
	char line[MAXLINE];
	int getline(char line[], int max);

	sum = 0;
	
	while(getline(line, MAXLINE) > 0) {
		sum += atof(line);
		printf("\t%g\n", sum);
	}
	return 0;

}

/* atof: convert string s to double */
double atof(char s[]) {
	double val, power;
	int i, sign, exp;

	for ( i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
	}
	//handle decimal
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	//handle exponent
	if (s[i] == 'e' || s[i] =='E') {
		i++;

		for (exp = 0; isdigit(s[i]); i++) {
			exp = 10 * exp + (s[i] - '0');
		}

		for (int p = 1; exp > 0; --exp)
			val *= 10;

	}
	
	return sign * val / power;
	
}

int getline(char s[], int lim) {
	int c, i;
	i = 0;
	while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

int power(int base, int n) {
	int p;

	for (p = 1;  n > 0; --n)
		p = p * base;
	return p;
}
