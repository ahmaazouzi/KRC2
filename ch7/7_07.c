#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000


char *f_gets(char *, int n, FILE *);
int f_puts(char *, FILE *);
int get_line(char *, int);

int main(int argc, char const *argv[]){
	FILE * fp;
	char line[MAXLINE];
	int index = 1;

	if (argc < 2)
		printf("Usage: find pattern\n");
	else if (argc == 2){
		while (f_gets(line, MAXLINE, stdin) != NULL)
			if (strstr(line, argv[1]) != NULL)
				printf("%s\n", line);
	} 
	else if (argc > 2){
		while (--argc > 1){
			if ((fp = fopen(argv[++index], "r")) == NULL){
				fprintf(stderr, "can't open %s\n", *argv);
				exit(1);
			} else {
				while (f_gets(line, MAXLINE, fp) != NULL)
					if (strstr(line, argv[1]) != NULL)
						printf("%s", line);
			}
			fclose(fp);
		}
	}

	exit(0);
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