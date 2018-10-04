
#include <stdio.h>

int invert(int x, int p, int n);
int main(){
	printf("%d\n", invert(182, 6, 3));
	return 0;
}

int invert(int x, int p, int n){
	x = (x & (~(~0 << (p-n)))) | 
	(~x & ((~(~0 << n)) << (p-n))) |
	(x & (~0 << p));

	return x;
}