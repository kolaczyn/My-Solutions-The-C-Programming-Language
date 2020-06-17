#include <stdio.h>

#define MAXLINE 100

int main() {
	double sum, atof(char[]);
	char line[MAXLINE];
	int getline(char line[], int max);

	sum = 0;
	while (getline(line, MAXLINE) > 0)
		printf("\t%g\n", sum += atof(line));
	return 0;
}

double atof(char s[]) {
	double val;
	int power1; // power because of '.'
	int power2; // power because of 'e'
	int power; // power1+power2
	int i;
	int sign1, sign2; // sign1 - before e. sign2 - after e
	int e; // is e positive or negative
	e = 0;
	for (i = 0; isspace(s[i]); i++)
		;
	sign1 = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power1 = 0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power1--;
	}
	if (s[i] == 'e' || s[i] == 'E') {
		i++;
		if (s[i] == '-') {
			sign2 = -1;
			i++;
		}
		else if (s[i] == '+') {
			sign2 = 1;
			i++;
		}
		else
			sign2 = 1;
		for (power2 = 0; isdigit(s[i]); i++)
			power2 = 10 * power2 + (s[i] - '0');
		power2 *= sign2;
	}
	else
		power2 = 0;
	if ((power = power1 + power2) > 0)
		for (i = 0; i < power; i++)
			val *= 10;
	else
		for (i = 0; i < -power; i++)
			val /= 10;
	return sign1 * val;
}

int getline(char s[], int lim) {
	int c, i;

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}