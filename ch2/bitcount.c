#include <stdio.h>

int bitcount(unsigned);

int main(void) {
	//bitcount(1);
	printf("%d\n", bitcount(15));
	
	return 0;
}

/*bitcount: count 1 bits in x*/
/*
int bitcount(unsigned x) {
	int b;

	for (b = 0; x != 0; x >>= 1)
		if (x & -1)
			b++;
	return b;
}
*/
//faster version using x &= (x-1)

int bitcount(unsigned x) {
	int b = 0;
	while (x > 0) {
		x &= (x-1);
		b++;
		printf("loop: x = %d\n", x);
	}

	return b;

}
