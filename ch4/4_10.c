#include "stdio.h"
#include "math.h"
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char [], char [], int);
void push(double);
double pop(void);
int get_line(char [], int);

int lineindex = 0;

int main(){
	int //type, 
	len;
	int type;
	double op2;
	char s[MAXOP];
	char line[MAXOP];
	while ((len = get_line(line, MAXOP)) > 0){
		lineindex = 0;
		while (lineindex < len){
			type = getop(s, line,len);
			lineindex++;
			// printf("%f\n", (atof(s)));
			
			
			switch(type){
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				push((long) pop() % (long) op2);
				break;
			case ('e'):
				push(exp(pop()));
				break;
			case ('^'):
				push(pow(pop(), pop()));
				break;
			case ('s'):
				push(sin(pop()));
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;			
			}
		}
	}
	return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f){
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void){
	if (sp > 0)
		return val[--sp];
	else{
		printf("error: stack empty\n");
		return 0.0;
	}
}

#include <ctype.h>

int getop(char s[], char line[], int len){
	int i;
	while ((s[0] = line[lineindex]) == ' ' || line[lineindex] == '\t')
		lineindex++;
	s[1] = '\0';
	if (!isdigit(line[lineindex]) && line[lineindex] != '.'){
		return line[lineindex];
	} 

	i = 0;
	if (isdigit(line[lineindex]))
		while (isdigit(s[++i] = line[++lineindex]))
			;
	if (line[lineindex] == '.')
		while (isdigit(s[++i] = line[++lineindex]))
			;
	s[i] = '\0';

	return NUMBER;


	// while ((s[0] = c) == ' ' || c == '\t')
	// 	lineindex++;
	// s[1] = '\0';
	// if (!isdigit(c) && c != '.'){
	// 	return c;
	// }
	// lineindex++;
	// return c;
	// i = 0;
	// if (isdigit(c))
	// 	while (isdigit(s[++i] = c))
	// 		lineindex++;
	// if (c == '.')
	// 	while (isdigit(s[++i] = c))
	// 		lineindex++;
	// s[i] = '\0';
	// return NUMBER;
}

int get_line(char s[], int lim){
	int c, i;

	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i){
		s[i] = c;
	}

	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	return i;
}


