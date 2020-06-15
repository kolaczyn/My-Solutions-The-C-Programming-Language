#include <stdio.h>

#include <stdio.h>

#define DIV 10 // max ammount of characters on one line
#define MAX 100 // max length of an array

void formatline(char s[]);
int mygetline(char s[], int lim);


int main() {
	char line[MAX];
	while (mygetline(line, MAX))
		formatline(line, 0);
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

// tabs and long lines without tabs or lines currently don't work
void formatline(char s[], int beg) { // n - where we begin formating, current line
	if (s[beg] == '\0')
		return;
	int i, j;
	char c;
	int lnw; // last non whitespace
	lnw = beg;
	for (i = beg; ((c = s[i]) != '\n') && i < DIV+beg; i++)
		if (c != ' ' && c != '\t')
			lnw = i;
	for (i = beg; i <= lnw; i++)
		putchar(s[i]);
	putchar('\n');
	formatline(s, lnw + 1);
}
