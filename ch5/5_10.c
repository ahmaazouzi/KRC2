#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 1000


int main(int argc, char *argv[]){
	int numnum, ind;
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
			while (ind > 0){
				if (isdigit(argv[ind][0]) && (numnum == 0)){
					third = argv[ind];
					argv[ind--] = "z";
					numnum++;
				}

				else if (isdigit(argv[ind][0]) && (numnum == 1)){
						first = argv[ind];
						argv[ind--] = "z";
						numnum++;
				} else {
					ind--;
				}
			}

			if (numnum > 1){
				opstack[opindex++] = first;
				opstack[opindex++] = second;
				opstack[opindex++] = third;
			}


		}
			
	}

	for (int i = 0; i < argc; i++){
		printf("%s ", argv[i]);
	}
	printf("\n");


	for (int i = 0; i < opindex; i++){
		printf("%s ", opstack[i]);
	}
	printf("\n");
}
