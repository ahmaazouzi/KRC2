#include "stdio.h"
#include <string.h>

void recreverse(char []);

int main(){
	char s[] = "ah";
	printf("%lu\n", strlen(s));
	printf("%s\n", s);
	recreverse(s);
	printf("%s\n", s);

	return 0;
}

void recurse (char [], long, long);
void recreverse(char s[]){
	long last = strlen(s) - 1;
	long first = 0;
	recurse(s, first, last);
}

void recurse (char s[], long first, long last){
	char temp;
	if (last != first){
		temp = s[last];
		s[last] = s[first];
		s[first] = temp;
		if (first + 1 <= last - 1)
			recurse(s, first + 1, last - 1);
	}
}

// Alternative
/*
void reverse(char s[], int last, int indexa, char elem){
	if (indexa < last)
		reverse(s, last, indexa + 1, s[indexa + 1]);
	s[last - indexa] = elem;
}
*/

// Alternative
/*
void printd(char s[], int indexa){
	if (indexa < strlen(s))
		printd(s, indexa + 1);
	putchar(s[indexa]);
}
*/