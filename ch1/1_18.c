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
		if (len > 0)
			printf("%s", detrailed_line);
	}		
	return 0;
}

int detrail(char s[], int lim){
	int c, i, trimedge, dudu;
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
		dudu = i-trimedge;
	} else {
		dudu = i;
	}
		if (c == '\n' && state == OUT){
		state = OUT;
		s[dudu] = '\n';
		++dudu;	
	}

	if (s[0] == '\n'){
		s[0] = 0;
	}


	s[dudu] = '\0';

	return dudu;
}

void copy(char to[], char from[]){
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}