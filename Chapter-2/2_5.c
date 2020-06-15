#include <stdio.h>

int any(char s1[], char s2[]);

int main() {
	char s1[] = { 'a', 'b', 'c', 'z', 'd', 'y', '\0'};
	char s2[] = { 'x', 'y', 'z', '\0' };

	int pos;
	if ((pos = any(s1, s2)) != -1)
		printf("Fount at position %d", pos);
	else
		printf("Didn't find it");
	getchar();
}

// would have to use hash table to make it linear most
// likely didn't K&R didn't want readers to do this
int any(char s1[], char s2[]) {
	int i, j, k;
	k = 0;
	for (i = j = 0; s1[i] != '\0'; i++)
		for (k = 0; s2[k] != '\0'; k++)
			if (s1[i] == s2[k])
				return i;
	return -1;
}