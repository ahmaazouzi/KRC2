#include "stdio.h"
#define OUTSTRING  0
#define INSTRING   1
#define SLASH      '/'
#define STAR       '*'
#define INCOMMENT  1
#define OUTCOMMENT 0
#define EMPTY      '\0'
#define	NONSLASHED 0
#define SLASHED	   1
#define REMOVELINE 1
#define LEAVELINE  0
#define ENDL       '\n'

int isInString(int state);

int main(){
	int c, stringState, commentState, slashState, lineEndState, lineEnd;
	slashState = NONSLASHED;
	char commentStart[2];
	char commentEnd[2];
	stringState  = OUTSTRING;
	commentState = OUTCOMMENT;
	lineEndState = LEAVELINE;

	while ((c = getchar()) != EOF){
		if (lineEndState == REMOVELINE && c == ENDL)
			c = EMPTY;
		lineEndState = LEAVELINE;
		if (c == '\"'){
			stringState = isInString(stringState);
		}

		if (stringState == OUTSTRING){
			if (commentState == OUTCOMMENT){
				if (c != STAR && slashState == SLASHED)
					putchar(SLASH);
				if (c == SLASH){
					commentStart[0] = SLASH;
					slashState = SLASHED;
				} else {
					slashState = NONSLASHED;
				}
				if (c == STAR)
					commentStart[1] = STAR;

			} else if (commentState == INCOMMENT){
				if (c == STAR)
					commentEnd[0] = STAR;
				if (c == SLASH && commentEnd[0] == STAR){
					commentEnd[1] = SLASH;
				}
			}

			if (commentStart[0] == SLASH && commentStart[1] == STAR){
				commentState = INCOMMENT;
				commentStart[0] = EMPTY;
				commentStart[1] = EMPTY;
			} 

			if (commentEnd[0] == STAR && commentEnd[1] == SLASH){
				lineEndState = REMOVELINE;
				commentState = OUTCOMMENT;
				commentEnd[0] = EMPTY;
				commentEnd[1] = EMPTY;
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
