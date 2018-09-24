#include "stdio.h"
#define OUTSTRING  0
#define INSTRING   1
#define SLASH      '/'
#define STAR       '*'
#define INCOMMENT  1
#define OUTCOMMENT 0
#define NAH        'n'

int isInComment(int state);
int isInString(int state);

int main(){
	int c, stringState, commentState;
	char commentStart[2];
	char commentEnd[2];
	stringState  = OUTSTRING;
	commentState = OUTCOMMENT;

	while ((c = getchar()) != EOF){

		if (c == '\"'){
			stringState = isInString(stringState);
		}

		if (stringState == OUTSTRING){
			if (commentState == OUTCOMMENT){
				if (c == SLASH)
					commentStart[0] = SLASH;
				if (c == STAR)
					commentStart[1] = STAR;
			} else if (commentState == INCOMMENT){
				if (c == STAR)
					commentEnd[0] = STAR;
				if (c == SLASH)
					commentEnd[1] = SLASH;
			}

			if (commentStart[0] == SLASH && commentStart[1] == STAR){
				commentState = INCOMMENT;
				commentStart[0] = NAH;
				commentStart[1] = NAH;
			} 
			if (commentEnd[0] == STAR && commentEnd[1] == SLASH){
				commentState = OUTCOMMENT;
				commentEnd[0] = NAH;
				commentEnd[1] = NAH;
			} 

			if (commentState == OUTCOMMENT)
				if (c != SLASH)
					putchar(c);

		} else {
			putchar(c);
		}
	}
	return 0;
}

int isInString(int state){
 	if (state == OUTSTRING )
		state = INSTRING;
	else 
		state = OUTSTRING;
 	return state;
}
