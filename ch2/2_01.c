/* I don't know exactly what's meant by 'compute ranges.' I just used 
the standard headers
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
	printf("value range of unsigned char is: %d to %d\n", 0, UCHAR_MAX);
	printf("value range of signed char is: %d to %d\n", SCHAR_MIN, SCHAR_MAX);

	printf("value range of unsigned short is: %d to %d\n", 0, USHRT_MAX);
	printf("value range of signed short is: %d to %d\n", SHRT_MIN, SHRT_MAX);
	

	printf("value range of unsigned int is: %u to %u\n", 0, UINT_MAX);
	printf("value range of signed int is: %d to %d\n", INT_MIN, INT_MAX);

	printf("value range of usigned long is: %d to %lu\n", 0, ULONG_MAX);
	printf("value range of signed long is: %ld to %ld\n", LONG_MIN, LONG_MAX);

	printf("value range of float is: %f to %f\n", FLT_MIN, FLT_MAX);
	
	printf("value range of double float is: %f to %f\n", DBL_MIN, DBL_MAX);
	return 0;
}