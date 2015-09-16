//recursive itoa function
//convert integer to string recursively
#include <stdio.h>
#define MAXLINE 1024

void itoa(int n);
//void printd(int n);
char a[MAXLINE];

int main(void) {
	
	int c = 213123;
	itoa(c);
	printf("%s\n", a);
	//printd(c);
	
	return 0;
}


void itoa(int n) {
	static int i = 0;

	if (n / 10) {
		itoa(n / 10);
	}
	a[i] = (n % 10 + '0');
	i++;
	
}
