#include "stdio.h"
#define MAX 1000

int escape(char s[], char t[]);
int main(){
	char s[MAX] = "\tBoyakasha.\nI is here wih not ozer zan\nmy main\tbabba";
	char t[MAX];

	escape(s, t);

	printf("%s\n", t);

	return 0;
}

int escape(char s[], char t[]){
	int i, j;
	i = j = 0;

	while (s[i] != '\0'){
		switch(s[i]) {
			case('\t'):
				t[j] = '\\';
				t[++j] = 't';
				break;
			case('\n'):
				t[j] = '\\';
				t[++j] = 'n';
				break;
			default:
				t[j] = s[i];
		}
		++i;
		++j;
	}
	return 0;
}