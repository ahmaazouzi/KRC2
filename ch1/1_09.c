#include "stdio.h"

int main()
{
	int c, bl=0;
	while((c = getchar()) !=EOF){
		if (c != 'z'){
			bl = 0;
		}
		
		if ( bl > 0){
			c= 0;
		}
		if (c == 'z')
			bl++;
		putchar(c);
		
		
	}
}