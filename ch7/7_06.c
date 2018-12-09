#include <stdio.h>
#include <string.h>

#define MAXLINE 1000
#define MAXLINES 5000


char *f_gets(char *, int n, FILE *);
int f_puts(char *, FILE *);
int get_line(char *, int);

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
			printf("%s: %s\n", argv[1], line1);
			printf("%s: %s\n", argv[2], line2);
			break;
		}

	fclose(fp1);
	fclose(fp2);

	return 0;
}

int get_line(char *line, int max){
	if (f_gets(line, max, stdin) == NULL)
		return 0;
	else
		return strlen(line);
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

int f_puts(char *s, FILE *iop){
	int c;

	while ((c = *s++))
		putc(c, iop);
	return ferror(iop) ? EOF : 0;
}

// int main(int argc, char const *argv[]){
// // // 	FILE *fp;
// // // 	void filecopy(FILE *, FILE *);

// // // 	if (argc == 1)
// // // 		filecopy(stdin, stdout);
// // // 	else
// // // 		while (--argc > 0)
// // // 			if ((fp == fopen(*++argv, "r")) == NULL){
// // // 				printf("cat: can't open %s\n", *argv);
// // // 				return 1;
// // // 			} else {
// // // 				filecopy(fp, stdout);
// // // 				fclose(fp);
// // // 			}
// 	return 0;
// }

// void filecopy(FILE *ifp, FILE *ofp){
// 	int c;

// 	while ((c = getc(ifp)) != EOF)
// 		putc(c, ofp);
// }