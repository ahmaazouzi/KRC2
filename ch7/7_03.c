#include <stdarg.h>
#include <stdio.h>

void minprintf(char *, ...);
int main(){
	minprintf("%d\n", 55);
	return 0;
}

void minprintf(char *fmt, ...){
	va_list ap;
	char *p, *sval;
	int ival;
	double dval;

	va_start(ap, fmt);
	for (p = fmt; *p; p++){
		if (*p != '%'){
			putchar(*p);
			continue;
		}
		switch(*++p){
		case 'd':
			ival = va_arg(ap, int);
			printf("%d", ival);
			break;
		case 'o':
			ival = va_arg(ap, unsigned);
			printf("%d", ival);
			break;
		case 'g':
			ival = va_arg(ap, double);
			printf("%g", dval);
			break;
		case 'i':
			ival = va_arg(ap, int);
			printf("%i", ival);
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf("%f", dval);
			break;
		case 's':
			for (sval = va_arg(ap, char *); *sval; sval++)
				putchar(*sval);
			break;
		default:
			putchar(*p);
			break;
		}
	}
	va_end(ap);
}