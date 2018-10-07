/* As the question is not very clear, I'll assume that 
 * that a trailing and leading dashes are meaningless. 
 * Only when  the characters surrounding the dash are in order 
 * will the process run.
 * It handles patterns like a-z0-9, a-z & a-b-c.
 * Maybe future feedback will calrify what the question means exactly
 * and the code will be adjusted accordingly.
 */

#include "stdio.h"
#include <string.h>
void expand(char s1[], char s2[]);
int main(){
	char s2[1000];
	expand("A-Z", s2);
	printf("%s\n", s2);
	return 0;
}

void expand(char s1[], char s2[]){
	int start, end, symbol, i, j;
	start = end = symbol = i = j= 0;

	while (s1[i] != '\0'){
		if ((s1[i] >= 'a' && s1[i] <= 'z') ||
			(s1[i] >= 'A' && s1[i] <= 'Z') ||
			(s1[i] >= '0' && s1[i] <= '9')){

		 	if (start && symbol)
		 		end = s1[i];
		 	else
		 		start = s1[i];
		}

		if (s1[i] == '-' && start)
			symbol = 1;

		if (end){
			for (int a = start; a <= end; a++){
				if (s2[j-1] != a){
					s2[j] = a;
					j++;
				}
			}

			end = 0;
			symbol = 0;
			if (s1[i+1] == '-'){
				start = s1[i];
			}
		}
		++i;
	}

	s2[++j] = '\0';
}