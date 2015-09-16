#include <stdio.h>
#define MAXLINE 1000
//delete any character in s2 that matches a character in s1 (totally n^2 problem)

void squeeze(char s[], int c);
int main(void) {
	int c = 'm';
	int d;
	int i = 0;
	char s[MAXLINE];
	//char s2[MAXLINE];

	while ((d = getchar()) != '\n') {
			s[i++] = d;
		}

	squeeze(s, c);
	printf("%s\n", s);
	return 0;

}


void squeeze(char s[], int c) {
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++) {
		if (s[i] != c)
			s[j++] = s[i];
		
	
	}
	s[j] = '\0';
}


/*
for (i = 0; s1[i] != '\0'; i++)
		for (j = 0; s2[i] != '\0'; j++)
			if (s1[i] == s2[i]) {
				if (s[i+1]!='\0')
					s[i] == s[i+1];
				else
					s[i]='\0';
			}
*/
