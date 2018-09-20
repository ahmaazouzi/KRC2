#include "stdio.h"
#define MAXLINE 1000
#define IN  1
#define OUT 0

int detrail(char line[], int maxline);
void copy(char to[], char from[]);

int main(){
	int len;
	char line[MAXLINE];
	char detrailed_line[MAXLINE];

	while ((len = detrail(line, MAXLINE)) > 0){
		copy(detrailed_line, line);
		printf("%s", detrailed_line);
	}		
	return 0;
}

int detrail(char s[], int lim){
	int c, i, trimedge, blanklength;
	int state = OUT;

	trimedge = 0;
	for (i=0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i){
		
		if (c == '\t' || c == '#' || c == ' '){
			state = OUT;
			++trimedge;
		}
		else {
			state = IN;
			trimedge = 0;
		}
		s[i] = c;
	}

	if (trimedge > 0){
		blanklength = i-trimedge;
	} else {
		blanklength = i;
	}
	if (c == '\n'){
		s[blanklength] = '\n';
		++blanklength;	
	}

	if (s[0] == '\n'){
		s[0] = 0;
	}

	s[blanklength] = '\0';

	return blanklength;
}

void copy(char to[], char from[]){
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}