/* Assuming that the bits start at p and n somehwere 
 * on the right side of p.
*/

#include <stdio.h>

int setbits(int x, int p, int n, int y);
int main(){
	unsigned int l = 3;
	printf("%d\n",setbits(102, 7, 4, 85));
	return 0;
}

int setbits(int x, int p, int n, int y){
	/* Set n bits starting at p to 1 */
	int setToOne = (~(~0 << n) << (p - n)); 
	printf("%d\n", setToOne);
	x = x & setToOne;
	/* shift the n rightmost bits of i to where the n bits 
	of x starting at p are and set every other bit of y to 1*/
	int maskOne = (y & (~0 << n)) << (p - n);
	maskOne = maskOne | ~(~0 << (n));
	/* change n bits of */
	x = x & maskOne;
	return x;
}