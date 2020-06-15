#include <stdio.h>

#include <stdio.h>

#define TABL 8// tabs' length

int main() {
	int c;
	int s; //Spaces; needed spaces
	int t; //Tabs; how much tabs we can put
	int a; //All; how far into tab we are
	int j;
	s = t = a = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			s++;
			a++;
			if (a == TABL) {
				a = s = 0;
				t++;
			}
		}
		else if (c == '\t') {
			t++;
			a = s = 0;
		}
		else if (c == '\n') {
			a = s = t = 0;
			putchar(c);
		}
		else {
			if (t != 0) {
				for (j = 0; j < t; j++)
					putchar('\t');
				t = 0;
			}
			if (s != 0) {
				for (j = 0; j < s; j++)
					putchar(' ');
				s = 0;
			}
			a++;
			putchar(c);
		}
	}
}
