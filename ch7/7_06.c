#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

char *f_gets(char *, int n, FILE *);
int main(int argc, char const *argv[]){
	char line1[MAXLINE];
	char line2[MAXLINE];
	FILE *fp1, *fp2;

	if (argc == 3){
		if ((fp1 = fopen(argv[1], "r")) == NULL){
			printf("can't open %s\n", argv[1]);
			return 1;
		}

		if ((fp2 = fopen(argv[2], "r")) == NULL){
			printf("can't open %s\n", argv[2]);
			return 1;
		}
	}

	while ((f_gets(line1, MAXLINE, fp1) != NULL) &&
		(f_gets(line2, MAXLINE, fp2) != NULL))
		if (strcmp(line1, line2) != 0){
			printf("%s: %s", argv[1], line1);
			printf("%s: %s", argv[2], line2);
			break;
		}

	fclose(fp1);
	fclose(fp2);

	return 0;
}

char *f_gets(char *s, int n, FILE *iop){
	register int c;
	register char *cs;

	cs = s;
	while (--n > 0 && (c = getc(iop)) != EOF)
		if ((*cs++ = c) == '\n')
			break;
	*cs = '\0';
	return (c == EOF && cs == s) ? NULL : s;
}