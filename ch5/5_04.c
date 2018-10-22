#include <stdio.h>
#include <string.h>
#define OUT 0
#define IN 1

int strend(char *, char *);

int main(){
	char *s = "isch der Fisch";
	char *t = "isch";

	printf("%d\n", strend(s,t));
	return 0;
}

int strend(char *s, char *t){
	int state = OUT;

	while (*s++ && strlen(s) >= strlen(t))
		state = (*s == *t) ? IN : OUT;
	return state;
}
