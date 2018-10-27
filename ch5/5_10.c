#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 1000


int main(int argc, char *argv[]){
	char *first, *second, *third, *temp;
	int numnum;

	char *opstack[100];
	int opindex = 0;

	while ((--argc > 0) && *++argv != NULL) 
			if ((*argv)[0] == '+' || (*argv)[0] == '-'){
				second = *argv;
				temp = *argv;
				while (isdigit((*--argv)[0]) || (*argv)[0] == 'z'){
					if (isdigit((*argv)[0])){ 
						if (numnum == 0){
							first = *argv;
							*argv = "z";
						}
						if (numnum == 1){
							third = *argv;
							opstack[opindex++] = first;
							opstack[opindex++] = second;
							opstack[opindex++] = third;
							*argv = "z";
						}
						numnum++;
					}
				}
				numnum = 0;
				
				*argv = temp;
				*argv = "z";
			}


	for (int i = 0; i < opindex; i++){
		printf("%s\n", opstack[i]);
	}



		// while (--argc > 0)
		// if ((*++argv)[1] == '*')
		// 	printf("WTF\n");
	// if (argc != 1)
	// 	printf("Usage: find -x -n pattern\n");
	// else
	// 	while (get_line(line, MAXLINE) > 0) {
	// 		lineno++;
	// 		if ((strstr(line, *argv) != NULL) != except) {
	// 			if (number)
	// 				printf("%ld:", lineno);
	// 			printf("%s", line);
	// 			found++;
	// 		}
	// 	}
	// return found;
}
