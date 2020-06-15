#include <stdio.h>

#define MAX 256
//I'm assuming user will not exceed the limit
//so I'm not checking that

void escape(char s[], char t[]);

int main() {
	char s[MAX], t[MAX];
	int i;
	int c;
	printf("Write the text you want to convert. Type Ctrl + Z to stop writing.\n");
	for (i = 0; (t[i] = getchar()) != EOF; i++)
		;
	t[i] = '\0';
	escape(s, t);
	printf("\Converted text:\n");
	for (i = 0; (c = s[i]) != '\0'; i++)
		putchar(s[i]);
	getchar();
}

void escape(char s[], char t[]) {
	int i; //t iterator
	int j; //s iterator
	for (i = j = 0; t[i] != '\0'; i++) {
		if (t[i] == '\\')
			switch (t[++i]) {
			case 'n':
				s[j++] = '\n';
				break;
			case 't':
				s[j++] = '\t';
				break;
			default:
				s[j++] = '\\';
				s[j++] = t[i];
			}
		else
			s[j++] = t[i];
	}
	s[j] = '\0';
}