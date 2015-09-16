#include <stdio.h>

unsigned invert(unsigned, int, int);

int main(void) {
	unsigned x = 8;
	printf("%u\n", invert(x, 3, 1));

	return 0;
}


/*invert: invert n bits of x from position p*/
//(p+1) - n is crucial
unsigned invert(unsigned x, int p, int n) {
	if ((p+1) - n == 0)
		return x ^ ~(~0 << n); //n ones 
	
	else
		return x ^ (~(~0 << n)) << p;

	}
