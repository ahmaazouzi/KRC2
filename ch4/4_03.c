#include "stdio.h"
#include "math.h"
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
void printstacktop(void);
void swap(void);
void duplicatetop(void);
void clearstack(void);

int main(){
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF){
		switch(type){
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			printstacktop();
			swap();
			duplicatetop();
			clearstack();
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
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;			
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

void duplicatetop(void){
	double duplicate = val[sp - 1];
	if (sp < MAXVAL)	
		val[sp++] = duplicate;
	else
		printf("error: stack full, can't duplicate %g\n", val[sp-1]);
}

void printstacktop(void){
	if (sp > 0)
		printf("Top of stack is: %g\n", val[sp - 1]);
	else
		printf("stack empty\n");
}

void swap(void){
	int temp;
	if (sp >= 2){
		temp = val[sp - 1];
		val[sp -1] = val[sp - 2];
		val[sp - 2] = temp;
	}
}

void clearstack(void){
	while (sp > 0)
		val[--sp] = '\0';
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[]){
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFFSIZE 100

char buf[BUFFSIZE];
int bufp = 0;

int getch(void){
	return (bufp > 0) ? buf[--bufp]: getchar();
}

void ungetch(int c){
	if (bufp >= BUFFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
