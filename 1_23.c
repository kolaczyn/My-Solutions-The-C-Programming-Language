#include <stdio.h>

int mygetline(char s[], int lim);
#define MAX 10000 // max no. of chars per line

#define COM	0 //comment
#define ST1	1 //string1; "
#define ST2 2 //string2; '
#define KOD 3 //code
#define LCO 4 //long comment

int main() {
	char s[MAX];
	int c;
	int len;
	int i;
	int state;
	state = KOD;

	while ((len = mygetline(s, MAX)) > 0) {
		for (i = 0; i < len; i++) {
			c = s[i];
			if ((c == '\n') && (state != LCO)) {
				state = KOD;
				putchar(c);
			}
			else if (state == ST1) {
				if (c == '"')
					state = KOD;
				putchar(c);
			}
			else if (state == ST2) {
				if (c == '\'')
					state = KOD;
				putchar(c);
			}
			else if (state == LCO) {
				if ((c == '*') && (s[i + 1] == '/')) {
					state = KOD;
					i++;
				}
			}
			else if (state == KOD) {
				if (c == '"') {
					state = ST1;
					putchar(c);
				}
				else if (c == '\'') {
					state = ST2;
					putchar(c);
				}
				else if ((c == '/') && (s[i + 1] == '/'))
					state = COM;
				else if ((c == '/') && (s[i + 1] == '*'))
					state = LCO;
				else
					putchar(c);
			}
		}
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
