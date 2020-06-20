#include <stdio.h>

void strcat(char *s, char *t);

#define MAX 128

int main(){
	char s[MAX] = "hello ";
	char t[]		= "world";

	strcat(s, t);
	printf(s);
}


void strcat(char *s, char *t){
	while(*++s)
		;
	while(*t)
		*s++=*t++;
}
