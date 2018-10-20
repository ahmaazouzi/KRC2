#include <stdio.h>
#include <ctype.h>

#define SIZE 10

double getfloat(double *);

int main(){
	int n, array[SIZE], ge(int *);
	int val;

	for (int i = 0; i < SIZE; i++){
		array[i] = 666;
	} 

	for (int i = 0; i < SIZE && (val = getint(&array[i])) != EOF; i++){
		;
	}

	for (int i = 0; i < SIZE; i++){
		printf("%d ", array[i]);
	} 
	printf("\n");




	return 0;
}

double getch(void);
void ungetch(double);

double getfloat(double *np){
	double val, power, c;
	int sign;

	while (isspace(c = getch()))
		;
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	if (!isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c);
		return 0;
	}
	for (*np = 0.0; isdigit(c); c = getch())
		*np = 10 * *np + (c - '0');
	if (c == '.')
		c = getch();
	for (power = 1.0; isdigit(c); c = getch()){
		*np = 10 * *np + (c - '0');
		power *= 10.0;
	}


	*np = (*np /power) * sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

#define BUFFSIZE 100

char buf[BUFFSIZE];
int bufp = 0;

double getch(void){
	return (bufp > 0) ? buf[--bufp]: getchar();
}

void ungetch(double c){  
	if (bufp >= BUFFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

