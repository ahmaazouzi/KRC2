#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000
#define TAIL 10
#define ALLOCSIZE 10122

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
		printf("%s", "error: input too big to sort\n");
		return 1;
	}
}

int get_line(char *, int);
char *alloc(int);
void afree(char *);

int readlines(char *lineptr[], int maxlines){
	int len, nlines, tailines;
	char *p, line[MAXLEN];

	int lala = TAIL;
	nlines = tailines = 0;
	while ((len = get_line(line, MAXLEN)) > 0){
		if (nlines >= maxlines ||  (p = alloc(MAXLEN-1)) == NULL)
			return -1;
		else {
			if (tailines == TAIL){
				afree(allocbuf);
				tailines = 0;
			}

			line[len-1] = '\0';
			strcpy(p, line);

			lineptr[tailines++] = p;
		}
		nlines++;
	}
	return tailines;
}

void writelines(char *lineptr[], int nlines){
	while (nlines-- > 0)
		printf("%d: %s\n", nlines, *lineptr++);
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

