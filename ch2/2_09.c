/* Not sure if this is faster. The conditional is removed
 * and the the observation is made use of. I believe the answer
 * is right.
 */

#include <stdio.h>

int bitcount(unsigned x);
int main(){
	printf("%d\n", bitcount(15));
	return 0;
}

int bitcount(unsigned x){
	int b = 0;

	while (x){
		x &= (x - 1);
		b++;
	} 

	return b;
}
