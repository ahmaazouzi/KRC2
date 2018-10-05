
#include <stdio.h>
#define CHAR_BITSIZE 32

int rightrot(unsigned int x,unsigned int n);
int main(){
	printf("%d\n", rightrot(15, 2));
	return 0;
}

int rightrot(unsigned int x, unsigned int n){
	x = ((x & (~(~0 << (n)))) << (CHAR_BITSIZE - n)|
		(x >> n));
	return x;
}