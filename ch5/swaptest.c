#include <stdio.h>

void swap(int, int);

int main(void) {
	int x = 100;
	int y = 2;
	printf("before\tx: %d\n", x);
	printf("before\ty: %d\n", y);
	swap (x, y);
	printf("after\tx: %d\n", x);
	printf("after\ty: %d\n", y);
	printf("EOF value: %d\n", EOF);

	return 0;
}


void swap(int x, int y) {
	printf("before\tx copy: %d\n", x);
	printf("before\ty copy: %d\n", y);
	int temp = x;
	x = y;
	y = temp;
	printf("after\tx copy: %d\n", x);
	printf("after\ty copy: %d\n", y);

}
