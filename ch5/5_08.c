/* The plan was to outsource error checking to an validation
 * function that handles both functions, but since the avalidation
 * occurs at multiple stages, it would be wasteful to either allow 
 * any of the functions to keep running until all possible errors are
 * can be caught at once. It would also be sad to call the validator function
 * multiple times.
 */
#include <stdio.h>

#define RANGE(a) a > 1900 && a < 2500

int day_of_year(int, int, int);
void month_day(int, int, int *, int *);


static char daytab[2][13] = {
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int main(){
	int m, d;
	printf("%d\n", day_of_year(1800,2,29));
	month_day(3000, 3000, &m, &d);
	printf("%d\n", m);
}

int day_of_year(int year, int month, int day){
	int i, leap;

	if (!(RANGE(year))){
		printf("error: year out of range: ");
		return 0;
	}

	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

	if (month > 12){
		printf("error: there are ony 12 months in a year: ");
		return 0;
	}
	if (day > daytab[leap][month]){
		printf("error: month %d can't have more than %d days: ", month,daytab[leap][month]);
		return 0;
	}

	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday){
	int i, leap;

	if (!(RANGE(year))){
		printf("error: year out of range\n");
		return;
	}

	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	if ((yearday > 366 && leap) || yearday > 365){
		printf("%s", "error: a year can't have that many days: ");
		*pmonth = 0;
		return;
	}
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];

	*pmonth = i;
	*pday = yearday;
}




