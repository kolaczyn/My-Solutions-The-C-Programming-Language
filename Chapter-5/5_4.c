#include <stdio.h>

int strend(char *s, char* t);

#define MAX 128

int main(){
	char s[MAX] = "hello world";
	char t[]		= "what the fuck are you ding here?hello world";

  printf("%d", strend(s, t));
}

int strend(char *s, char* t){
  char *beg = t;
  // we find the end of both strings
  while(*++s)
    ;
  while(*++t)
    ;
  while(*t-- == *s-- && beg < t)
    ;
  return (beg == t) ? 1: 0;
}
