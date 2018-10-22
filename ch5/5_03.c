#include <stdio.h>

void strcatt(char *, char *);

int main(){
	char s[] = "z";
	char t[] = "ddd";
	strcatt(s,t);
	printf("%s\n", s);
	return 0;
}

void strcatt(char *s, char *t){
	while (*s)
		s++;
	while ((*s++ = *t++))
		;
}
