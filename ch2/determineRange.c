#include <stdio.h>
#include<limits.h>

int charMax(void);

int main(void) {
	printf("Here are the ranges of a few data types");
	printf("char: %d to %d\n", CHAR_MIN, CHAR_MAX);
	printf("short: %d to %d\n", SHRT_MIN, SHRT_MAX);
	printf("int: %d to %d\n", INT_MIN, INT_MAX);
	printf("long: %d to %d\n", LONG_MIN, LONG_MAX);
	printf("Overflow test: %d\n", charMax());


}

int charMax(void) {
char c=0;
while ((c+1)>c)
		++c;

return c;

}
