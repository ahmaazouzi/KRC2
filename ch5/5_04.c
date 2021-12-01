/*
December 2021: The older version required the use of <string.h> and missed some edge cases like
empty strings and sometimes identical strings.
*/

#include <stdio.h> 

int strend(char *, char *);

int main(){
	char *s = "isch der Fisch";
	char *t = "isch";

	printf("%d\n", strend(s,t));
	return 0;
}

int strend(char *s, char *t){
	char *tb = t;
	while (*s){
		if (*s == *t){
			t++;
		} 
		else {
			t = tb;
		}
		s++;
	}

	if (*s == '\0' && *s == *t)
		return 1;
	return 0;
}