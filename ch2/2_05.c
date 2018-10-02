/* Needs more work
*/ 

#include <stdio.h>

int squeeze(char s[], char z[]);
int squzzo(char s[], int c);
int main(){
	char s[1000] = "BssssssssssssZ";
	;
	printf("%d\n", squeeze(s, "absssss"));
}

int squeeze(char s[], char z[]){
	int i, j, v, found;
	found = 0;
	v = -1;

	for (i = 0; z[i] != '\0' && found == 0; i++){
		for (j = 0; s[j] != '\0' && found == 0; j++){
			if (z[i] == s[j]){
				v = i;
				found = 1;
			}
		}
	}
	return v;
}