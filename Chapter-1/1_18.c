#include<stdio.h>

#define MAXLINE	1000

int mygetline(char s[], int lim);
int del_end_whitespaces(char s[]);

int main() {
	char line[MAXLINE];

	while ((mygetline(line, MAXLINE)) > 0){
		if (del_end_whitespaces(line) != 1)
			printf("%s", line);
		}
}

int mygetline(char s[], int lim) {
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		s[++i] = '\0';
	}
	else if (c != EOF)
	{
		s[i] = '\0';
		while ((c = getchar()) != EOF && c != '\n')
			i++;
	}
	return i;
}

int del_end_whitespaces(char s[]) {
	int i;
	for (i = 0; s[i] != '\0'; i++) //find array's length
		;
	i -= 2;
	for (; (s[i] == ' ') || (s[i] == '\t'); i--) //delete whitespaces
		;
	s[++i] = '\n';
	s[++i] = '\0';
	return i;
}
