#include "stdio.h"

void expand(char s1[], char s2[]);
int main(){

	expand("a-v", "");
	return 0;
}

void expand(char s1[], char s2[]){
	int start, end, symbol, i;
	start = end = symbol = i = 0;

	while (s1[i] != '\0'){
		if (!start && ((s1[i] >= 'a' && s1[i] <= 'z') ||
			(s1[i] >= 'A' && s1[i] <= 'Z') ||
			(s1[i] >= '0' && s1[i] <= '9'))){
		 	start = s1[i];
		}

		if (s1[i] == '-' && start)
			symbol = 1;

		if (symbol && start &&
			((s1[i] >= 'a' && s1[i] <= 'z') ||
			(s1[i] >= 'A' && s1[i] <= 'Z') ||
			(s1[i] >= '0' && s1[i] <= '9'))
			){
			end =s1[i];
		}
		 ++i;
	}

	for (int a = start; a <= end; a++)
		printf("%c\n", a);
}