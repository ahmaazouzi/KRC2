#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main(){
	int nlines;    

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0){
		qsort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}

	return 0;
}

#define MAXLEN 1000
int get_line(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines){
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = get_line(line, MAXLEN)) > 0){
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

void writelines(char *lineptr[], int nlines){
	int i;

	for (i = 0; i < nlines; i++){
		printf("%s\n", lineptr[i]);
	}

	// or
	// while (nlines-- > 0)
	// 	printf("%s\n", *lineptr++);
}

void qsort(char *v[], int left, int right){
	int i, last;
	void swap(char *v[], int i, int j);

	if (left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j){
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

#define ALLOCSIZE 10000

static char allocbuff[ALLOCSIZE];
static char *allocp = allocbuff;

char *alloc(int n){
	if (allocbuff + ALLOCSIZE - allocp >= n){
		allocp += n;
		return allocp - n;
	} else
		return NULL;
}

int get_line(char s[], int lim){
	int c, i;

	for (i=0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i){
		s[i] = c;
	}

	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	return i;
}
