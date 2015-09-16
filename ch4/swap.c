#include <stdio.h>

#define MAXSIZE 100

#define swap(t, x, y) t tmp; tmp = x; x = y; y = tmp
//#define assign(c, x) c = x

int main(void) {
	int x, y;
	x = 10;
	y = 0;
	printf("before:\tx = %d\ty=%d\n", x, y);
	swap(int, x, y);
	printf("after:\tx = %d\ty=%d\n", x, y);
	
	return 0;
}

