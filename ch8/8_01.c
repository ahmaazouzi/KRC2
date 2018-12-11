#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#define PERMS 666
#define STANDARS_IN  0
#define STANDARS_OUT 1

void error(char *, ...);

int main(int argc, char *argv[]){
	void filecat(int);
	int f1;

	if (argc == 1)
		filecat(STANDARS_IN);
	else
		while (--argc > 0)
			if ((f1 = open(*++argv, O_RDONLY, 0)) == -1){
				error("cat: can't open %s\n", *argv);
			} else {
				filecat(f1);
				close(f1);
			}
	return 0;
}

void filecat(int f1){
	char buf[BUFSIZ];
	int n;

	while ((n = read(f1, buf, BUFSIZ)) > 0)
		if (write(STANDARS_OUT, buf, n) != n)
			error("cat: write error on stdout");
}

void error(char *fmt, ...){
	va_list args;

	va_start(args, fmt);
	fprintf(stderr, "error, ");
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");
	va_end(args);
	exit(1);
}