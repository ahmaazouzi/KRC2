#include "stdio.h"

int binsearch(int x, int v[], int n);
int main(){
	int bsa[10];
	int b = 0;
	while (b <= 9){
		bsa[b] = b;
		b++;
	}

	printf("%d\n", binsearch(3, bsa, 10));
	return 0;
}

int binsearch(int x, int v[], int n){
	int low, mid, high;

	low = 0;
	high = n - 1;
	while (low <= high){
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	
	if (x == mid)
		return mid;

	return -1;
}