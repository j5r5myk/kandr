#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);
int strrindex(char s[], char t[]);

char pattern[] = "ould";

int main(void) {
	char line[MAXLINE];
	int found = 0;
	

	while (getline(line, MAXLINE) > 0) {
		int x = strrindex(line, pattern);
		//if (x >= 0) {
			printf("%d", x);
			found++;
		//}
	}
	return found;
}

int getline(char s[], int lim) {
	int c, i;
	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
//this returns the index of t in s
int strindex(char s[], char t[]) {
	int i, j, k;

	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}

//return rightmost index of t (phrase) in s (line)
int strrindex(char s[], char t[]) {
	int i, j, k, current;
	current = 0;
	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0') {
			current = i;
			//printf("current update");
		}
	}
	if (current > 0)
		return current;
	

	return -1;
}
