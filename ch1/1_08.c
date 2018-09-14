#include "stdio.h"

int main()
{
	int c, tl=0, bl=0, nl=0;
	while((c = getchar()) !=EOF){
		if (c == '\b')
			tl++;
		if (c == '\t')
			bl++;
		if (c == '\n')
			nl++;
	}
	printf("Number of tabs:   %d\n", tl);
	printf("Number of blanks: %d\n", bl);
	printf("Number of lines:  %d\n", nl);
}