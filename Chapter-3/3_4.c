#include <stdio.h>

#define MAX 21// just enough for the biggest 64 bit value + '\0'

void itoa(int n, char s[]);
void reverse(char s[]);

int main() {
	int n = -314;
	char s[MAX];
	itoa(n, s);
	printf(s);
	getchar();
}

// TODO
void itoa(int n, char s[]) {
	int i, sign;

	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
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