/* This looks very very bad */
#include "stdio.h"

int atoi(char s[]);
int main(){
	printf("%d\n", atoi("0xf0"));
	return 0;
}

int atoi(char s[]){
	int n, i, z, x;
	x = 0;

	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')){
		x = 2;
	}

	n = 0;
	for (i = x; (s[i] >= '0' && s[i] <= '9') ||
		(s[i] >= 'A' && s[i] <= 'F') ||
		(s[i] >= 'a' && s[i] <= 'f')
		; ++i) 
	{
		if (s[i] >= '0' && s[i] <= '9')
			z = (s[i] - '0');
		else {
			if (s[i] == 'A' || s[i] == 'a')
				z = 10;
			if (s[i] == 'B' || s[i] == 'b')
				z = 11;
			if (s[i] == 'C' || s[i] == 'c')
				z = 12;
			if (s[i] == 'D' || s[i] == 'd')
				z = 13;
			if (s[i] == 'E' || s[i] == 'e')
				z = 14;
			if (s[i] == 'F' || s[i] == 'f')
				z = 15;
		}
		n = 16 * n + z;
	}
	return n;
}