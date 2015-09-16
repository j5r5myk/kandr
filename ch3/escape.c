#include <stdio.h>

#define MAXLINE 1024

void escape(char s[], char t[]);

int main(void) {
	char t[MAXLINE] = "hey			thats 3 tabs\n\n 2 new lines \n \t \n \t";
	char s[MAXLINE];

	escape(s, t);

	printf("%s\n", s);
}

//copy t[] to s[]
void escape(char s[], char t[]) {
	int i, j;
	j = 0;
	for (i = 0; i < MAXLINE; i++)
		
//cannot use those char things
		switch(t[i]) {
			case '\t':
				s[j++] = '\\';
				s[j++] = 't';
				break;
			case '\n':
				s[j++] = '\\';
				s[j++] = 'n';
				break;
			default: 
				s[j++] = t[i];
				break;
	}

}
