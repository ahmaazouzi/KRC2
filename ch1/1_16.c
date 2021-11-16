#include "stdio.h"
#define MAXLINE 3

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main(){
	int len, i, c;
	int max, maxmax;
	char line[MAXLINE];
	char longest[MAXLINE];

	maxmax = 0;
	max = 0;
	while ((len = get_line(line, MAXLINE)) > 0){
		if (len == (MAXLINE - 1)){
			maxmax = len;
			getchar();
			maxmax = maxmax + 2;
			while ((c = getchar()) != EOF && c != '\n'){
				++maxmax;
			}
			copy(longest, line);
		}

		if (len > max){
			max = len;
			copy(longest, line);

		}
	}
	
	if (maxmax > 0){
		printf("%d\n", maxmax);
		printf("%s\n", longest);		
	} else if (max > 0){
		printf("%d\n", max);
		printf("%s\n", longest);		
	}

	return 0;
}

int get_line(char s[], int lim){
	int c, i;

	for (i=0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i){
		s[i] = c;
	}

	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	return i;
}

void copy(char to[], char from[]){
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
