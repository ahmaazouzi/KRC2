/* Check unbalanced parantheses, blanks, braces, quotes.. and comments */

#include "stdio.h"
#include "stdlib.h" /* Not seen yet, but the concept is obvious*/
#define MAXSYMBS         1000
#define OPENPARANTHESES  '('
#define CLOSEPARANTHESES ')'
#define OPENBRACKET      '['
#define CLOSBRACKET      ']'
#define OPENBRACE        '{'
#define CLOSBRACE        '}'
#define SINGLEQUOTE      '\''
#define DOUBLEQUOTE      '"'
#define BSLASH           '\\'
#define LINEEND          '\n'
#define SLASH            '/'
#define STAR             '*'
#define SLASHED          1
#define UNSLASHED        0
#define STARRED          1
#define UNSTARRED        0
#define INQUOTE          1
#define OUTQUOTE         0
#define INCOMMENT        1
#define OUTCOMMENT       0
#define EMPTY            '\0'

void getBalanceScore(char s[], int i);
int isInQuote(int c, int quoteCommentState);
int isInComment(int c, int commentState, int slashState, int starState);

int main(){
    int c, i, commentState, quoteState, slashState, starState;
    char groupers[MAXSYMBS];
    // slash by itslef is a syntax error. come back to this

    commentState = OUTCOMMENT;
    quoteState = OUTQUOTE;
    slashState = UNSLASHED;
    i = 0;
    while ((c = getchar()) != EOF){
        quoteState = isInQuote(c, quoteState);
        commentState = isInComment(c, commentState, slashState, starState);

        if (quoteState == OUTQUOTE && commentState == OUTCOMMENT){
            if (c == OPENPARANTHESES||c == CLOSEPARANTHESES||
                c == OPENBRACE ||c == CLOSBRACE||
                c == OPENBRACKET||c == CLOSBRACKET){
                groupers[i] = c;
                ++i;
            } 
        } 

        if (c == SLASH)
            slashState = SLASHED;
        else {
            slashState = UNSLASHED;
        }
        if (c == STAR)
            starState = STARRED;
        else {
            starState = UNSTARRED;
        }
    }
    ++i;
    groupers[i] = EMPTY;
    getBalanceScore(groupers, i);
    return 0;
}

void getBalanceScore(char groupers[], int i){
    int parantheses, braces, brackets;
    brackets = 0;
    braces = 0;
    parantheses = 0;
    for (int t = 0; t <= i; ++t){
        if (groupers[t] == OPENPARANTHESES)
            ++parantheses;
        if (groupers[t] == OPENBRACKET)
            ++brackets;
        if (groupers[t] == OPENBRACE)
            ++braces;
        if (groupers[t] == CLOSEPARANTHESES){
            --parantheses;
            if (parantheses < 0){
                printf("%d unexpexted '%c'\n", abs(parantheses), CLOSEPARANTHESES);
                parantheses = 0;
            }
        }
        if (groupers[t] == CLOSBRACE){
            --braces;
            if (braces < 0){
                printf("%d unexpexted '%c'\n", abs(braces), CLOSBRACE);
                braces = 0;
            }
        }
        if (groupers[t] == CLOSBRACKET){
            --brackets;
            if (brackets < 0){
                printf("%d unexpexted '%c'\n", abs(brackets), CLOSBRACKET);
                brackets = 0;
            }
        }
    }

    if (parantheses > 0)
        printf("%d missing '%c'\n", parantheses, OPENPARANTHESES);
    if (brackets > 0)
        printf("%d missing '%c'\n", brackets, OPENBRACKET);
    if (braces > 0)
        printf("%d missing '%c'\n", braces, OPENBRACE);
}

int isInQuote(int c, int quoteState){
    if (c == DOUBLEQUOTE){
        if (quoteState == OUTQUOTE){
            quoteState = INQUOTE;
        } 
        else {
            quoteState = OUTQUOTE;
        }
    }
    
    return quoteState;
}

int isInComment(int c, int commentState, int slashState, int starState){
    if (c == STAR && slashState == SLASHED){
        if (commentState == OUTCOMMENT){
            commentState = INCOMMENT;
        } 
    }

    if (c == SLASH && starState == STARRED){
        if (commentState == INCOMMENT){
            commentState = OUTCOMMENT;
        } 
    }

    return commentState;
}

