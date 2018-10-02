/* I tried a nested loop where the outer loop
 * would go over s[]'s while the internal loop
 * scans the letters that need to be removed but
 * kept getting this 'segmentation fault'. I have 
 * no idea what that means.
*/ 

#include <stdio.h>

void squeeze(char s[], char z[]);
void squzzo(char s[], int c);
int main(){
	char s[1000] = "BaaaaakaaffffXaZ";
	squeeze(s, "abakaffffaZ");
	printf("%s\n", s);
}

void squeeze(char s[], char z[]){
	int i;

	for (i = 0; z[i] != '\0'; i++){
		squzzo(s, z[i]);
	}
}

void squzzo(char s[], int c){
	int i, j;

	for (i = j = 0; s[i] != '\0' ; i++){
		if (s[i] != c)
			s[j++] = s[i];
	}
	s[j] = '\0';
}