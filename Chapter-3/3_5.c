#include <stdio.h>

#define MAX 21// just enough for the biggest 64 bit value + '\0'

void itob(int n, char s[], int b);
void reverse(char s[]);

int main() {
	int n = 43981;
	char s[MAX];
	itob(n, s, 16);
	printf(s);
	getchar();
}

void itob(int n, char s[], int b) {
	int i, sign;
	int rem;

	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		if ((rem = n % b) >= 0 && rem <= 9)
			s[i++] = rem + '0';
		else
			s[i++] = rem -10 + 'A';
	} while ((n /= b) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]) {
	int i;
	int end;
	int mid;
	int swap;
	for (end = 0; s[end] != '\0'; end++) // we find the end
		;
	mid = end / 2;
	for (i = 0; i < mid; i++) {
		swap = s[i];
		s[i] = s[end - i - 1];
		s[end - i - 1] = swap;
	}
}