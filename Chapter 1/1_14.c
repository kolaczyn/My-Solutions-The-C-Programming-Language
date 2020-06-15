#include <stdio.h>

int main() {
	int c;
	int i, j;
	int ch[26];
	for (i = 0; i < 26; i++)
		ch[i] = 0;
	while ((c = getchar()) != EOF) {
		if (c >= 'a' && c <= 'z')
			ch[c - 'a']++;
		else if ((c >= 'A' && c <= 'Z'))
			ch[c - 'A']++;
	}
	for (i = 0; i < 26; i++) {
		printf("%c, %c: ", i + 'a', i + 'A');
		for (j = 0; j < ch[i]; j++)
			putchar('>');
		putchar('\n');
	}
	getchar();
}
