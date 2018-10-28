#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 1000
#define OPERATION 1
#define NOOPERATION 0


int main(int argc, char *argv[]){
	int numnum, ind, operations;
	char *first, *second, *third;

	char *opstack[100];
	int opindex = 0;

	for (int i = 1; i < argc; i++){
		if (argv[i][0] == '+' || argv[i][0] == '*' || 
		 argv[i][0] == '/' ||  argv[i][0] == '-'){
			second = argv[i];
			argv[i] = "z";
			ind = i;
			numnum = 0;
			operations = 0;
			while (ind > 0){
				if (isdigit(argv[ind][0]) && (numnum == 0)){
					third = argv[ind];
					argv[ind--] = "z";
					numnum++;
				}

				else if (numnum == 1 && isdigit(argv[ind][0]) && operations == 0){
						first = argv[ind];
						argv[ind--] = "z";
						numnum++;
				} else {
					ind--;
				}
			}

			printf("numa %d\n", numnum);

			if (numnum == 2 && operations == 0){
				opstack[opindex++] = third;
				opstack[opindex++] = second;
				opstack[opindex++] = first;
				operations++;
			}

			if (operations > 0){
					opstack[opindex++] = second;
					operations--;	
			}

		}
			
	}

	for (int i = 0; i < opindex; i++){
		printf("%s ", opstack[i]);
	}
	printf("\n");
}
