#include<stdio.h>

#define MAXLINE 1000

int mygetline(char s[], int lim);
void reverse(char s[]);

int main() {
	char line[MAXLINE];

	while (mygetline(line, MAXLINE)) {
		reverse(line);
		printf(line);
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

void reverse(char s[]) {
	int i;
	int end;
	int mid;
	int swap;
	for (end= 0; s[end] != '\n'; end++) // we find the end
		;
	mid = end / 2;
	for (i = 0; i < mid; i++) {
		swap = s[i];
		s[i] = s[end - i-1];
		s[end - i-1] = swap;
	}
}
