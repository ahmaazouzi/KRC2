#include "stdio.h"
#include "math.h"
#include "calc.h"
#include "stdlib.h"

#define MAXOP 100

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

	return 0;
}