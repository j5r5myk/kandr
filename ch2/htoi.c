#include <stdio.h>
#include <ctype.h>

int htoi(char s[]);

#define MAXSIZE 1000

int main(void) {
	int c, i;
	char hex[MAXSIZE];
	
	i = 0;
	while ((c=getchar()) != '\n') {
		hex[i] = c;
		i++;
	}
	hex[i+1] = '\0';
	printf("%d\n", htoi(hex));
	
	return 0;
}

//takes string of hex e.g. 0xFFFF0A
//converts to int

int htoi(char s[]) {
	int i = 0, n = 0;

	if (s[0]==0)
		if (s[1]=='x' || s[1]=='X')
			i=2;
	while (s[i] != '\0') {
		if (isdigit(s[i])) {
			n = 16 * n + (s[i] - '0');
			printf("digit\n");
		}

		else if ('a' <= s[i] && s[i] <= 'f') {
			n = 16 * n + (s[i] - '0' - 39);
			printf("lower case\n");
		}

		else if ('A' <= s[i] && s[i] <='F') {
			n = 16 * n + (s[i] - '0' - 7);
			printf("upper case\n");
		}
	
		i++;
	}


	return n;
}
