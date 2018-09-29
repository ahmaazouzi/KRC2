/* Check unbalanced parantheses, blanks, braces..
 * If anything is inside single or double quote, comments, it's ignored.
 * This could've been done recursively much more elegantly, but I work with what I have so far
 */

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
#define INSQUOTE         1
#define OUTSQUOTE        0
#define INCOMMENT        1
#define OUTCOMMENT       0
#define EMPTY            '\0'

void getUnbalanced(char groupers[], int i);
int isInQuote(int c, int quoteCommentState);
int isInComment(int c, int commentState, int slashState, int starState);
int isInSQuote(int c, int sQuoteState);

int main(){
    int c, i, commentState, quoteState, slashState, starState, sQuoteState;
    char groupers[MAXSYMBS];


    commentState = OUTCOMMENT;
    quoteState = OUTQUOTE;
    slashState = UNSLASHED;
    sQuoteState = OUTSQUOTE;
    i = 0;
    while ((c = getchar()) != EOF){
        quoteState = isInQuote(c, quoteState);
        commentState = isInComment(c, commentState, slashState, starState);
        sQuoteState = isInSQuote(c, sQuoteState);

        if (quoteState == INQUOTE && commentState == INCOMMENT && sQuoteState == INSQUOTE){
            c = EMPTY;
        }

        if (c == OPENPARANTHESES||c == CLOSEPARANTHESES||
            c == OPENBRACE ||c == CLOSBRACE||
            c == OPENBRACKET||c == CLOSBRACKET){
            groupers[i] = c;
            ++i;
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
    getUnbalanced(groupers, i);

    return 0;
}

void getUnbalanced(char groupers[], int i){
    int s, sym;
    char symbArray[MAXSYMBS];
    sym = 0 ;

    for (s = 0; s <= i; ++s){
        if (groupers[s] == OPENPARANTHESES || groupers[s] == OPENBRACKET ||
        groupers[s] == OPENBRACE){
            symbArray[sym] = groupers[s];
            ++sym;
        }

        if (groupers[s] == CLOSEPARANTHESES){
            if (symbArray[sym - 1] == OPENPARANTHESES && sym > 0){
                --sym;
            }
            else if (sym > 0){
                printf("Unexpectted %c was encountered\n", groupers[s]);
                if (sym > 0)
                    --sym;    
            }
        }

        if (groupers[s] == CLOSBRACKET){
            if (symbArray[sym - 1] == OPENBRACKET && sym > 0){
                --sym;
            }
            else {
                printf("Unexpectted %c was encountered\n", groupers[s]);
                if (sym > 0)
                    --sym;    
            }
        }

        if (groupers[s] == CLOSBRACE){
            if (symbArray[sym - 1] == OPENBRACE && sym > 0){
                --sym;
            }
            else {
                printf("Unexpectted %c was encountered\n", groupers[s]);
                if (sym > 0)
                    --sym;  
            }
        }
    }

    if (sym > 0){
        for (s = 0; s < sym; ++s)
            printf("A symbol corresponding to %c is missing.\n", symbArray[s]);
    }
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

int isInSQuote(int c, int sQuoteState){
    if (c == SINGLEQUOTE && sQuoteState == OUTSQUOTE)
        sQuoteState = INSQUOTE;

    else if (c == SINGLEQUOTE && sQuoteState == INSQUOTE)
        sQuoteState = OUTSQUOTE;

    return sQuoteState;
}

