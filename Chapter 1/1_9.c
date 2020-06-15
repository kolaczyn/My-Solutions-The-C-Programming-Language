#include <stdio.h>

#define IN	1 // in word
#define OUT	0 // out of word

int main()
{
	int c;
	int state;
	state = IN;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			putchar(' ');
			putchar(c);
			state = IN;
		}
		else
			putchar(c);
	}
	getchar();
}
