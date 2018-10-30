#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXLINE 1000
#define NONNUMBER "b"

void expr(char *[], int);
int main(int argc, char *argv[]){
	int numnum = 0;
	char *nums_ops[100]; 

	for (int i = 1; i < argc; i++){
		if (argv[i][0] == '+' || argv[i][0] == '*' || 
		 argv[i][0] == '/' ||  argv[i][0] == '-' || isdigit(argv[i][0] )){
			nums_ops[numnum++] = argv[i];
		}
	}

	expr(nums_ops, numnum);


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



int recursions = 0;


void expr(char *argv[], int argc){
	int tempnums, numsonly;
	char *nums[100];
	char *temp[100];
	char buff[100] = "";

	// tempnums = 0;
	// for (int i = 0; i < argc; i++){
	// 	temp[i] = argv[i];
	// 	tempnums++;
	// }
	// numsonly = tempnums;

	// printf("\n");

	// // while (numsonly >= 1){
	// 	for (int i = 0; i < numsonly; ++i){
	// 		if (temp[i][0] == '+' || temp[i][0] == '*' || 
	// 		 temp[i][0] == '/' ||  temp[i][0] == '-'){

	// 		 	if (i > 1){
	// 		 		strcat(buff, temp[i-1]);
	// 		 		temp[i-1] = NONNUMBER;
	// 		 		strcat(buff, temp[i]);
	// 		 		// break;
	// 		 	}
	// 		 	if (i > 2){
	// 		 		strcat(buff, temp[i-2]);
	// 		 		temp[i-2] = NONNUMBER;
	// 		 	}

	// 		 	strcpy((temp[i] = malloc(sizeof(100))), buff);
	// 		 	strcpy(buff, "");
	// 		 	break;
	// 		}
	// 	}
	// // }
	// 	for (int i = 0; i < numsonly; i++){
	// 		if (temp[i][0] == '+' || temp[i][0] == '*' || 
	// 		 temp[i][0] == '/' ||  temp[i][0] == '-' || isdigit(temp[i][0] )){
	// 			nums[numsonly++] = temp[i];
	// 		}
	// 	}

	// 	for (int i = 0; i < count; ++i)
	// 	{
	// 		/* code */
	// 	}

	// 	return;

	int rec = 0;
	for (int i = 0; i < argc; i++){
		if (argv[i][0] == '+' || argv[i][0] == '*' || 
		 argv[i][0] == '/' ||  argv[i][0] == '-'){
		 	if (i > 0){
		 		strcat(buff, argv[i-1]);
		 		argv[i-1] = NONNUMBER;
		 		strcat(buff, argv[i]);
		 	}
		 	if (i > 1){
		 		strcat(buff, argv[i-2]);
		 		argv[i-2] = NONNUMBER;
		 	}
		 	strcpy((argv[i] = malloc(sizeof(100))) ,buff); //argv[i] = buff;
		 	strcpy(buff, "");
		 	break;
		}
	}
	printf("%s\n", buff);
	

	numsonly = 0;

	for (int i = 0; i < argc; i++){
		if (argv[i][0] == '+' || argv[i][0] == '*' || 
		 argv[i][0] == '/' ||  argv[i][0] == '-' || isdigit(argv[i][0] )){
			nums[numsonly++] = argv[i];
		}
	}

	for (int i = 0; i < numsonly; ++i)
	{
		printf("%s", nums[i]);
	}

	printf("\n");
	// return;

	if (numsonly == 1)
		printf("%s\n", buff);
	else {
		rec++;
		printf("num rec: %d\n", numsonly);
		expr(nums, numsonly);
	}


	// copy to a new array whith only operators and numbers
		
}
