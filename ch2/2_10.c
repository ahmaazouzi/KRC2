#include "stdio.h"

int lower(int c);

int main(){
	printf("%c\n", lower(65));
	return 0;
}

int lower(int c){
	return ((c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c);
}