#include "stdio.h"
#define swap(t, x, y) t temp = x; x = y; y = temp;

int main(){
	float a = 2.22;
	float b = 3.33;
	swap(float, a, b);
	printf("2.22 becomes: %.2f\n", a);
	printf("3.33 becomes: %.2f\n", b);
	return 0;
}