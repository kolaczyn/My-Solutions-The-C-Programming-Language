#include <stdio.h> 

#define MAX 128

void strncpy(char *s, char *t, int n);
void strncat(char *s, char *t);
int strncmp(char *s, char *t);


int main() {
	printf("strncpy:\n");
	char s1[MAX];
	char t1[] = "hello world";
	strncpy(s1, t1, 16);
	printf(s1); //hello world

	printf("\n\nstrncat:\n");
	char s2[MAX] = "hello";
	char t2[] = " world";
	strncat(s2, t2);
	printf(s2); //hello world

	printf("\n\nstrncmp:\n");
	char s3[MAX] = "hello world";
	char t3[]	= "hello work";
	printf("%d", strncmp(s3, t3)); // 1

	getchar();
}

// I assume that s at least n chars long
void strncpy(char* s, char* t, int n) {
	int i;
	for (i = 0; *t && i < n; s++, t++, i++)
		*s = *t;

	while (++i < n)
		*s++ = 0;
	*s = 0;

}

void strncat(char* s, char* t){
	while (*++s)
		;
	while (*t)
		*s++ = *t++;
	}

int strncmp(char* s, char* t){
	for (; *s && *t; s++, t++)
		if (*s != *t)
			return (*s - *t);
	return 0;
}
