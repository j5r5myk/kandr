#include <stdio.h>
#define MAXLINE 1000
//delete any character in s2 that matches a character in s1 (totally n^2 problem)

void squeeze(char s1[], char s2[]);
int main(void) {
	//int c = 'm';
	int d;
	int i = 0;
	char s1[MAXLINE];
	char s2[MAXLINE];
	printf("String 1: ");
	while ((d = getchar()) != '\n') {
			s1[i++] = d;
		}
		s1[i] = '\0';
	printf("\n");
	
	i=0;
	printf("String 2: ");
	while ((d = getchar()) != '\n') {
			s2[i++] = d;
		}
	s2[i] = '\0';
	printf("\n");

	squeeze(s1, s2);
	printf("%s\n", s1);
	return 0;

}


void squeeze(char s1[], char s2[]) {
	int i, j;

	for (i = 0; s1[i] != '\0'; i++) {
		for (j = 0 ; s2[j] != '\0'; j++) {
			if (s1[i] == s2[j])	{
				if (s1[i]!= '\0')
					s1[i] = s1[i+1];
				else
					s1[i] = '\0';
			}
		}
	
	}
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
