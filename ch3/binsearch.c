#include <stdio.h>
//rewrite with 1 inner loop test!!!!
int binsearch(int, int *, int);


int main(void) {
	int v[] = {0, 1, 23, 44, 44, 44, 44, 44, 50, 51, 52, 57, 20443, 30000};
	printf("%d\n", binsearch(44, v, 14));
}

int binsearch(int x, int v[], int n) {
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high) /2;
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	
	if (v[mid] ==x)
		return mid;
	else
		return -1;
}
