#include <stdio.h>

int htoi(char s[]);

int main() {
	//char s[2] = { '1','2' };
	//char s[1] = { '\0' }; //'empty' number return 0, which kinda makes sense
	char s[6] = {'0', 'x', 'A', 'B', 'C', '\0' };
	int out;
	if ((out = htoi(s)) != -1)
		printf("%d", out);
	else
		printf("invalid number");
	getchar();
}

int htoi(char s[]) {
	int i = 0;
	int out = 0;
	int num;
	int c;
	if (s[0] == '0') // works even if s == { '0' }
		if (s[1] == 'x' || s[i] == 'X')
			i = 2;
	while ((c = s[i++]) != '\0') {
		if (c >= '0' && c <= '9')
			num = c - '0';
		else if (c >= 'a' && c <= 'f')
			num = c - 'a' + 10;
		else if (c >= 'A' && c <= 'F')
			num = c - 'A' + 10;
		else // invalid number
			return -1;
		out = 16 * out + num;
	}
	return out;
}