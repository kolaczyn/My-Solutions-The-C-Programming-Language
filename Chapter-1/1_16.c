#include<stdio.h>

#define MAXLINE	1000

int mygetline(char line[], int maxline);

int main() {
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = mygetline(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0)
		printf("%s", longest);
	getchar();
	return 0;
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
void copy(char to[], char from[]) {
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
