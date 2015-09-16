#include <stdio.h>

void swap( int *px, int *py);

int main(void) {
	int c, *p, a, b;
	a = 22;
	b = 222;
	c = 100;
	p = &c; //p points to c
	
	*p+=100;
	printf("c: %d\n", c);
	printf("p: %d\n", *p);
	printf("a: %d\tb: %d\n", a, b);
	swap(&a, &b);
	printf("a: %d\tb: %d\n", a, b);

	return 0;


}

void swap(int *px, int *py) {
	int temp;

	temp = *px;
	*px = *py;
	*py = temp;

}
