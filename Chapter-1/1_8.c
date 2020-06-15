#include <stdio.h>

int main()
{
	int c, ns, nt, nn;
	ns = nt = nn = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			ns++;
		else if (c == '\t')
			nt++;
		else if (c == '\n')
			nn++;
	}
	printf("s: %d t: %d n: %d", ns, nt, nn);
	getchar();
}
