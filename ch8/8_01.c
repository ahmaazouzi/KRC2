#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define PERMS 666

int main(int argc, char const *argv[]){
	void filecat(int, int);
	int f1;

	if (argc == 1)
		filecat(0, 1);
	else
		while (--argc > 0)
			if ((f1 = open(*++argv, O_RDONLY, 0)) == -1){
				printf("cat: can't open %s\n", *argv);
			} else {
				filecat(f1, 1);
				close(f1);
			}
	return 0;
}

void filecat(int f1, int f2){
	char buf[BUFSIZ];
	int n;

	while ((n = read(f1, buf, BUFSIZ)) > 0)
		if (write(1, buf, n) != n)
			// error("cat: write error on some file");
			printf("cat: write error on some file");
}