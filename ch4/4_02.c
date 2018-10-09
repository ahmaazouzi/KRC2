#include "stdio.h"
#include <ctype.h>

double atof(char s[]);
int main(){
	double atofresult = atof("0.2315e3");
	printf("%f\n", atofresult);
	printf("%f\n", 0.2315e3);
	return 0;
}

double atof(char s[]){

	 double val, power, expower, exponent;
	 int sign, i, expsign;

	 for (i = 0; isspace(s[i]); i++)
	 	;
	 sign = (s[i] == '-') ? -1 : 1;
	 if (s[i] == '+' || s[i] == '-')
	 	i++;
	 for (val = 0.0; isdigit(s[i]); i++)
	 	val = 10.0 * val + (s[i] - '0');
	 if (s[i] == '.')
	 	i++;
	 for (power = 1.0; isdigit(s[i]); i++){
	 	val = 10.0 * val + (s[i] - '0');
	 	power *= 10.0;
	 }

	 if (s[i] != 'e' || s[i] != 'E'){
		i++;
		expsign = (s[i] == '-') ? -1 : 1;
		if (s[i] == '+' || s[i] == '-')
		 	i++;
		for (exponent = 0.0; isdigit(s[i]); i++)
		 	exponent = 10.0 * exponent + (s[i] - '0');

		if (exponent != 0){
		 	expower = 1;
		 	while (exponent > 0){
		 		expower *= 10;
		 		exponent--;
		 	}

		 	val = (expsign > 0) ? (val * expower):(val / expower);	
		}

	 }

	 return sign * val / power;
}
