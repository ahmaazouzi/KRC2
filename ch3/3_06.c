#include "stdio.h"
#include <string.h>

void reverse(char s[]);
void itoa(char n, char s[], char f);
int main(){
	char s[300];
	itoa(-12, s, 4);
	printf("%s\n", s);
	return 0;
}

void itoa(char n, char s[], char f){
	int i, sign;

	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
		
	while (f > strlen(s))
		s[i++] = ' ';
	
	reverse(s);
}

void reverse(char s[]){
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}