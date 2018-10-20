/* Assuming that a float is a whole a number.
 * All integers are whole numbers
 * So intgers will also be grabbed.
 */
#include <stdio.h>
#include <ctype.h>

#define SIZE 10

double getfloat(double *);

int main(){
	double array[SIZE], getfloat(double *);
	double val;

	for (int i = 0; i < SIZE; i++){
		array[i] = 0.0;
	} 

	for (int i = 0; i < SIZE && (val = getfloat(&array[i])) != EOF; i++){
		;
	}

	for (int i = 0; i < SIZE; i++){
		printf("%2.2f ", array[i]);
	} 
	printf("\n");

	return 0;
}

int getch(void);
void ungetch(int);

double getfloat(double *np){
	double val, power;
	int sign, c;

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

int getch(void){
	return (bufp > 0) ? buf[--bufp]: getchar();
}

void ungetch(int c){  
	if (bufp >= BUFFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

