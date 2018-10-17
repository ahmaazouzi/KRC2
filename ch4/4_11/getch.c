#include <stdio.h>
#include "calc.h"

int getch(int bufp){
	return (bufp > 0) ? buf[--bufp]: getchar();
}