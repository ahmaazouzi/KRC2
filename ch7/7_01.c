#include <ctype.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
	int c;

	while ((c = getchar()) != EOF)
		if (strcmp("./lowercase", argv[0]) == 0)
			putchar(tolower(c));
		else 
			putchar(toupper(c));
	return 0;
}
