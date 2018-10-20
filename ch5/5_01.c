#include <stdio.h>
#include <ctype.h>

#define SIZE 10

int getint(int *);

int main(){
	int n, array[SIZE], getint(int *);
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

int getch(void);
void ungetch(int);

int getint(int *np){
	int c, sign;

	while (isspace(c = getch()))
		;
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	if (!isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c);
		return 0;
	}
	for (*np = 0; isdigit(c); c = getch())
		*np = 10 * *np + (c - '0');
	*np *= sign;
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

