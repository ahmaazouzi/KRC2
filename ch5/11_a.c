#include "stdio.h"
#define TABSIZE 8

int main(){
	int c, tablength;

	tablength = 0;

	while ((c = getchar()) != EOF){

		if (c == '\t'){
			while(tablength < TABSIZE){
				putchar('#');
				tablength++;
			}
			tablength = 0;	
		} else {
			putchar(c);
			tablength++;
		}	
	}

	return 0;
}