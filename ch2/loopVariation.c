#include <stdio.h>

int main(void) {
	int lim = 1000;
	int j = 0;
	char c;
	printf("i loop: ");
	for (int i = 0; i<lim-1 && (c = getchar()) != '\n' && c != EOF; ++i) {
		printf("%d", i);
	}
	printf("\n");
	printf("j loop: ");
	while ((c = getchar()) != '\n'){
		if (j < lim -1 ) {
			if (c != EOF) {
				printf("%d", j);
				++j;
			}
		}
	}
	printf("\n");

	return 0;

}
