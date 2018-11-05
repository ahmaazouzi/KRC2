#include <stdio.h>
#include <string.h>

#define MAXLINES 10
#define MAXLEN 10
#define TAIL 3
#define ALLOCSIZE 44

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

int main(){
	int nlines;
	char lineread[MAXLEN];

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0){
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("%s\n", "error: input too big to sort\n");
		return 1;
	}
}

int get_line(char *, int);
char *alloc(int);
void afree(char *);

int readlines(char *lineptr[], int maxlines){
	int len, nlines;
	char *p, line[MAXLEN];

	int lala = TAIL;
	nlines = 0;
	while ((len = get_line(line, MAXLEN)) > 0){

		if (nlines >= maxlines ||  (p = alloc(len)) == NULL)
			return -1;
		else {

			line[len-1] = '\0';
			if (nlines)
				afree(p);

			strcpy(p, line);

			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

void writelines(char *lineptr[], int nlines){
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}

void swap(char *v[], int i, int j){
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int get_line(char *s, int lim){
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

// #define ALLOCSIZE 20

// static char allocbuf[ALLOCSIZE];
// static char *allocp = allocbuf;



char *alloc(int n){
	if (allocbuf + ALLOCSIZE - allocp >= n){
		allocp += n;
		return allocp - n;
	} else
		return 0;
}

void afree(char *p){
	if (p >= allocbuf && p <= allocbuf + ALLOCSIZE)
		allocp = p;
}

