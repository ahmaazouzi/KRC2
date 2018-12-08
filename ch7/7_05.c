#include "stdio.h"

#define MAXLINE 500

int get_line(char s[], int lim);
int main(){
	double op1, op2;
	char s;

	char line[MAXLINE];

	while (get_line(line, sizeof(line)) > 0)
		if (scanf("%lg  %lg %c", &op1, &op2, &s) == 3){
		 	if (s == '+')
				printf("\t%.8g\n", op1 + op2);
			else if (s == '-')
				printf("\t%.8g\n", op1 - op2);
			else if (s == '*')
				printf("\t%.8g\n", op1 * op2);
			else if (s == '/' && op2 != 0.0)
				printf("\t%.8g\n", op1 / op2);
			else 
				printf("error: unknown command %c\n", s);
		}

	return 0;
}

int get_line(char s[], int lim){
  int c, i;

  for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n'){
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
