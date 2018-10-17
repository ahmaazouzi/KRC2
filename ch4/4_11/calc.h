#define NUMBER '0'
void push(double);
double pop(void);
int getop(char []);
int getch(int);
void ungetch(int);

#define BUFFSIZE 100

char buf[BUFFSIZE];