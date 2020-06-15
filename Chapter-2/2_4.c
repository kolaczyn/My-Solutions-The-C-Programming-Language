#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main() {
	char s1[] = { 'a', 'a', 'z', 'x', 'b', 'a', 'z', 'a', 'z', 'x', '\0'};
	char s2[] = { 'x', 'z', '\0' };

	squeeze(s1, s2);
	int i;
	for (i = 0; s1[i] != '\0'; i++)
		printf("%c ", s1[i]);
	getchar();
}

// If s2 is only a few characters long, the algorithm is O(n).
// If s1 and s2 have roughly the same size, the time complexity goes to O(n^2)
// I would have to use a hash table to make it linear, but I doubt
// K&R wanted reader to do that
void squeeze(char s1[], char s2[]) {
	int i, j, k;
	k = 0;
	for (i = j = 0; s1[i] != '\0'; i++) {
		for (k = 0; s2[k] != s1[i] && s2[k] != '\0'; k++) // we look for s1[i] in s2
			;
		if (s2[k] == '\0') // ;if s1[i] was not found in s2
			s1[j++] = s1[i];
	}
	s1[j] = '\0';
}