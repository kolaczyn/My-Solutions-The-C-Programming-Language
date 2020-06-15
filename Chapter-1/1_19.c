#include<stdio.h>

#define MAXLINE 1000

int mygetline(char s[], int lim);
void reverse(char s[]);

int main() {
	char line[MAXLINE];

	while (mygetline(line, MAXLINE)) {
		reverse(line);
	}
	getchar();
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
// it doesn't actually reverse an array, but just prints to the output a reversed string
void reverse(char s[]) {
	int i;
	for (i = 0; s[i] != '\n'; i++)
		;
	for (i--; i >= 0; i--)
		putchar(s[i]);
	putchar('\n');
}
