#include "stdio.h"

/* print Celsius-Fahrenheit table as a FUNCTION*/

int celsius_to_fahr();
float temp_convert(float degree);

int main(){
	celsius_to_fahr();
	return 0;
}

int celsius_to_fahr(){
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	celsius = lower;
	printf("Celsius-Fahrenheit table:\n\n");
	while (celsius <= upper){
		printf("%3.0f %6.1f\n", celsius, temp_convert(celsius));
		celsius = celsius + step;
	}
	return 0;
}


float temp_convert(float celsius){
	return ((9.0/5.0) * celsius) + 32.0;
}