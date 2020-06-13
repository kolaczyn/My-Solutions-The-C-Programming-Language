#include<stdio.h>

// program prints lines which are long (longer than LONG chars long)

#define MAXLINE	1000
#define	LONG	80

int getline(char line[], int maxline);

int main() {
	int len;
	int max;
	char line[MAXLINE];

	while ((len = getline(line, MAXLINE)) > 0)
		if (len > LONG) {
			printf("%s", line);
		}
	getchar();
}

int getline(char s[], int lim) {
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return i;
}
