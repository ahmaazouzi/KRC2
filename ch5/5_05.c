#include <stdio.h>

void strncppy(char *, char *, int);
void strncatt(char *, char *, int);
int strncmpp(char *, char *, int);

int main(){
	char s[] = "aaaz";
	char t[] = "aaaa";
	char a[50];
	strncatt(s, t, 2); 
	strncppy(a, s, 3); 
	printf("%s\n", s);
	printf("%s\n", a);
	printf("Lexigraphical order: %d\n", strncmpp(s, t, 4));
	return 0;
}

void strncppy(char *s, char *t, int n){
	int p = 0;
	while (p < n && (*s++ = *t++))
		p++;
}

void strncatt(char *s, char *t, int n){
	int p = 0;
	while (*s)
		s++;
	while (p < n && (*s++ = *t++))
		p++;
}

int strncmpp(char *s, char *t, int n){
	int p = 1;

	for (; (*s == *t) && p < n ; s++, t++){
		if (*s == '\0')
			return 0;
		p++;
	}
	return *s - *t;
}