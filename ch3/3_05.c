#include "stdio.h"
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);
int main(){
	char z[300];
	itob(-255, z, 16);
	printf("%s\n", z);
	return 0;
}

void itob(int n, char s[], int b){
	char v[300] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i, sign;

	if ((sign = n) < 0)
		n = -n;

	i = 0;
	do {
		s[i++] = v[(n % b)];
	} while ((n /= b) > 0);

	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
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