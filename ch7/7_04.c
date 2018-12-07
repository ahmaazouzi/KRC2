#include <stdarg.h>
#include <stdio.h>

void minscanf(char *, ...);
int main(){
	int day, year;
	char monthname[20];
	char *s;

	minscanf("%d %s %d", &day, monthname, &year);
	printf("%d %s %d\n", day, monthname, year);

	return 0;
}

void minscanf(char *fmt, ...){
	va_list ap;
	char *p, *sval;
	int *ival;
	float  *dval;

	va_start(ap, fmt);
	for (p = fmt; *p; p++){
		if (*p != '%')
			continue;

		switch(*++p){
		case 'd':
			ival = va_arg(ap, int *);
			scanf("%d", ival);
			break;
		case 'o':
			ival = va_arg(ap, int *);
			scanf("%d", ival);
			break;
		case 'g':
			dval = va_arg(ap, float *);
			scanf("%g", dval);
			break;
		case 'i':
			ival = va_arg(ap, int *);
			scanf("%i", ival);
			break;
		case 'f':
			dval = va_arg(ap, float *);
			scanf("%f", dval);
			break;
		case 's':
			sval = va_arg(ap, char *);
			scanf("%s", sval);
			break;
		default:
			break;
		}
	}
	va_end(ap);
}