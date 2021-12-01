#include <stdio.h>
#include <string.h>

void reverse(char *s, long last, int indexa, char elem){
	if (indexa < last)
		reverse(s, last, indexa + 1, *(s + indexa + 1));
	s[last - indexa] = elem;
}

int main(){
	char s[] = "abcdefghijklmnopqrstuvwxyz";
	long last = strlen(s);
	reverse(s, last - 1, 0, *s);
	printf("%s\n", s);
}