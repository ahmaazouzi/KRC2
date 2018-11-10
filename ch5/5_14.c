#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAXLINES 5000
#define MAXLEN 1000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qasort(void *lineptr[], int left, int right,
	int (*comp)(void *, void *));

int numcomp(const char *, const char *);

int main(int argc, char *argv[]){
	int nlines;
	int numeric = 0;

	if (argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0){
		qasort((void **) lineptr, 0, nlines - 1,
			(int (*) (void *, void *)) (numeric ? numcomp : strcmp));
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("%s\n", "error: input too big to sort\n");
		return 1;
	}
}

int get_line(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines){
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = get_line(line, MAXLEN)) > 0)
		if (nlines >= maxlines ||  (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

void writelines(char *lineptr[], int nlines){
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}

void qasort(void *v[], int left, int right,
	int (*comp) (void *, void *)){

	int i, last;
	void swap(void *v[], int, int);

	if (left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qasort(v, left, last - 1, comp);
	qasort(v, last + 1, right, comp);
}

int numcomp(const char *s1, const char *s2){
	double v1, v2;

	v1 = atof(s1);
	v2 =atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

void swap(void *v[], int i, int j){
	void *temp;

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

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n){
	if (allocbuf + ALLOCSIZE - allocp >= n){
		allocp += n;
		return allocp - n;
	} else
		return 0;
}