#include <stdio.h>

#define IN	1
#define	OUT	0
#define MAX_L 5 // maximal length of the word


int main()
{
	int c, i, j, n, state, count, max;
	state = IN;
	count = 0;
	max = 0;
	int nwords[MAX_L + 1]; // in nwords[0] there is a number of words that are longer than MAX
	for (i = 0; i < MAX_L + 1; i++)
		nwords[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (state == IN) {
				if (count < MAX_L + 1)
					nwords[count]++;
				else
					nwords[0]++;
				state = OUT;
			}
		}
		else {
			if (state == IN)
				count++;
			else
				count = 1;
			state = IN;
		}
	}


	for (i = 0; i < MAX_L + 1; i++) {
		printf("%3d", i);
		if (max < nwords[i])
			max = nwords[i];
	}
	putchar('\n');
	for (i = 1; i <= max; i++)
	{
		for (j = 0; j < MAX_L + 1; j++) {
			printf("  ");
			if (i <= nwords[j])
				putchar('-');
			else
				putchar(' ');
		}
		putchar('\n');
	}
	getchar();
}
