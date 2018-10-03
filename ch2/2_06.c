#include <stdio.h>

int setbits(int x, int p, int n, int y);
int main(){
	unsigned int l = 3;
	printf("%d\n", (~(~0 << l)) << 3);
	return 0;
}

int setbits(int x, int p, int n, int y){
	return x;
}