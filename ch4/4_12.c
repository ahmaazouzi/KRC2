#include "stdio.h"
#define MAXSIZE 50

void prind(int, char []);

int main(){
	int a = 122;
	char b[MAXSIZE]; 
	printf("%s\n", b);
	prind(a, b);
	printf("%s\n", b);
	return 0;
}

void prind(int n, char s[]){
	static int i = 0;
	if (n < 0){
		s[i++] = ('-');
		n = -n;
	}
	if (n / 10)
		prind(n / 10, s);
	s[i++] = (n % 10 + '0');
	s[i] = '\0';
	if (n == 0) s[i] = '\0'; // Not sure if this adding a terminating char correctly
}

