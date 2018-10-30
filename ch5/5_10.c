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
}

void expr(char *argv[], int argc){
	int numsonly;
	char *nums[100];
	char buff[100] = "";

	for (int i = 0; i < argc; i++){
		if (argv[i][0] == '+' || argv[i][0] == '*' || 
		 argv[i][0] == '/' ||  argv[i][0] == '-'){
		 	if (i > 0){
		 		if (argv[i][0] == '+' || argv[i][0] == '-'){
		 			strcat(buff, "(");
		 			strcat(buff, " ");
		 		}
		 		strcat(buff, argv[i-1]);
		 		strcat(buff, " ");
		 		argv[i-1] = NONNUMBER;
		 		strcat(buff, argv[i]);
		 		strcat(buff, " ");
		 	}
		 	if (i > 1){
		 		strcat(buff, argv[i-2]);
		 		strcat(buff, " ");
		 		argv[i-2] = NONNUMBER;
		 		if (argv[i][0] == '+' || argv[i][0] == '-')
		 			strcat(buff, ")");
		 	}
		 	strcpy((argv[i] = malloc(sizeof(100))) ,buff); //argv[i] = buff;
		 	strcpy(buff, "");
		 	break;
		}
	}
	

	numsonly = 0;

	for (int i = 0; i < argc; i++)
		if (argv[i][0] == '+' || argv[i][0] == '*' || 
		 argv[i][0] == '/' ||  argv[i][0] == '-' || isdigit(argv[i][0]) || argv[i][0] == '(')
			nums[numsonly++] = argv[i];

	if (numsonly == 1)
		printf("%s\n", nums[0]);
	else 
		expr(nums, numsonly);	
}
