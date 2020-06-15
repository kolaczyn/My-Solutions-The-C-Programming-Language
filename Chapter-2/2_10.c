#include <stdio.h>

int lower(char c);

int main() {
	printf("%c", lower('g'));
	getchar();
}

int lower(char c) {
	return (c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : c;
}