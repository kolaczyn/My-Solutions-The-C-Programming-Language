#include<stdio.h>

#define LIM 64

int main() {
	int i;
	int c;
	char s[LIM];

	// The original loop
	//for (i = 0; !((i >= LIM - 1) + ((c = getchar()) == '\n') + (c == EOF)); i++)
	//	s[i] = c;
  
	for (i = 0; i < LIM - 1 && (c = getchar()) == '\n' && c != EOF; i++)
		s[i] = c;
	getchar();
}
