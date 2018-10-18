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