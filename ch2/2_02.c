#include "stdio.h"
#define MAXLINE 1000
#define MINLINE 80

int get_line(char line[], int maxline);

int main(){
	int len;
	char line[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0){
		if (len > MINLINE){
			printf("%s", line);
		}
	}

	return 0;
}

int get_line(char s[], int lim){
	int c, i;

	for (i=0; (c = getchar()) != EOF; ++i){
		if (c != '\n')
			if(i < lim-1)
				s[i] = c;
	}

	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	return i;
}