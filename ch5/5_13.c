#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
#define MAXLEN 300
#define TAIL 10
#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines, int);
void writelines(char *lineptr[], int nlines);

int main(int argc, char *argv[]){
	int nlines, tail, tailval;
	char lineread[MAXLEN];

	tailval = TAIL;
	tail = 0;
	while (--argc > 0 && (*++argv)[0]){
		if ((*argv)[0] == '-' && (*argv)[1] == 'n'){
			tail = 1;
			break;
		}
	}

	if (tail)
		tailval = atoi(*++argv);

	if ((nlines = readlines(lineptr, MAXLINES, tailval)) >= 0){
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("%s", "error: input too big to sort\n");
		return 1;
	}
}

int get_line(char *, int);
char *alloc(int);
void afree(char *);

int readlines(char *lineptr[], int maxlines, int tailval){
	int len, nlines, tailines;
	char *p, line[MAXLEN]; 

	nlines = tailines = 0;
	while ((len = get_line(line, MAXLEN)) > 0){
		if (nlines >= maxlines ||  (p = alloc(MAXLEN-1)) == NULL)
			return -1;
		else {
			if (tailines == (2 * tailval)){
				tailines = tailval;
				afree(allocbuf);	
			}

			line[len-1] = '\0';
			strcpy(p, line);

			lineptr[tailines++] = p;
		}
		nlines++;
	}
	return (tailval % tailines);
}

void writelines(char *lineptr[], int nlines){
	int z = 1;
	while (nlines-- > 0)
		printf("%d: %s\n", z++, *lineptr++);
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

