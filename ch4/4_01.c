#include "stdio.h"

int strrindex(char s[], char t[]);
int strrindex(char s[], char t[]);
int main(){

	printf("%d\n", strrindex("ahmedaa aaa aa aaa", "aaa"));
	return 0;
}

int strrindex(char s[], char t[]){
	int i, j, k, pos;

	pos = -1;
	for (i = 0; s[i] != '\0'; i++){
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			pos = i;
	}

	return pos;
}
