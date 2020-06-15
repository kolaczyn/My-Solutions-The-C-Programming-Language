#include <stdio.h>

#include <stdio.h>

#define TAB 8// tabs' length

int main() {
	int c;
	int i; //where are we in tab
	int j;
	i = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			for (j = 0; j < TAB-i; j++)
				putchar(' ');
			i = 0;
		}
		else if (c == '\n' || i == TAB - 1) {
			putchar(c);
			i = 0;
		}
		else {
			i++;
			putchar(c);
		}
	}
}
