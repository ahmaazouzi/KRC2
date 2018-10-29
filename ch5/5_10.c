#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 1000
#define NONNUMBER "b"

void expr(char *[], int, int);
int main(int argc, char *argv[]){
	int numnum = 0;

	for (int i = 1; i < argc; i++){
		if (argv[i][0] == '+' || argv[i][0] == '*' || 
		 argv[i][0] == '/' ||  argv[i][0] == '-' || isdigit(argv[i][0] )){
			numnum++;
		}
	}

	expr(argv, argc, numnum);


	// int numnum, ind, operations;
	// char *first = "", *second = "", *third = "";
	// printf("%lu\n", strlen(first));
	// printf("%lu\n", strlen(second));
	// printf("%lu\n", strlen(third));
	// printf("\n");
	// char buff[100] = "";

	// char *opstack[100];
	// int opindex = 0;

	// for (int i = 1; i < argc; i++){
	// 	if (argv[i][0] == '+' || argv[i][0] == '*' || 
	// 	 argv[i][0] == '/' ||  argv[i][0] == '-'){
		
		 
	// 		second = argv[i];
	// 		ind = i;
	// 		operations = 0;
	// 		while (ind >= 0){

	// 			if (strlen(first) && strlen(third)) {
	// 				break;
	// 			}
				 
	// 			if (isdigit(argv[ind][0]) && !strlen(third)){
	// 				third = argv[ind];
	// 				argv[ind--] = "z";
	// 				operations++;
	// 			}

	// 			else if (isdigit(argv[ind][0]) && strlen(third)){
	// 					first = argv[ind];
	// 					argv[ind--] = "z";
	// 			} 


	// 			else {
	// 				ind--;
	// 			} 
	// 		}

	// 		printf("%s, ", first);
	// 		printf("%s, ", second);
	// 		printf("%s, ", third);
	// 		printf("\n");

	// 		strcat(buff, first);			
	// 		strcat(buff, second);
	// 		strcat(buff, third);

	// 		strcpy(argv[i], buff);
	// 		strcpy(buff, "");
	// 		first = second =  third = "";
				
	// 	}	
	// }

	// for (int i = 1; i < argc; i++){
	// 		printf("%s\n", argv[i]);
		
	// }

}

char *nums[100];
char buff[100] = "";

void expr(char *argv[], int argc, int opnum){
	int numsonly;
	for (int i = 1; i < argc; i++){
		if (argv[i][0] == '+' || argv[i][0] == '*' || 
		 argv[i][0] == '/' ||  argv[i][0] == '-'){
		 	if (i > 1){
		 		strcat(buff, argv[i-1]);
		 		argv[i-1] = NONNUMBER;
		 		strcat(buff, argv[i]);
		 	}
		 	if (i > 2){
		 		strcat(buff, argv[i-2]);
		 		argv[i-2] = NONNUMBER;
		 	}
		 	argv[i] = buff;
		 }
	}

	numsonly = 0;

	for (int i = 1; i < argc; i++){
		if (argv[i][0] == '+' || argv[i][0] == '*' || 
		 argv[i][0] == '/' ||  argv[i][0] == '-' || isdigit(argv[i][0] )){
			nums[numsonly++] = argv[i];
		}
	}

	if (numsonly == 1)
		printf("%s\n", buff);
	else {
		strcpy(buff, "");
		expr(nums, opnum, numsonly);
	}


	// copy to a new array whith only operators and numbers
		
}
