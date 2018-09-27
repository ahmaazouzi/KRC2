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
#define BSLASHED         1
#define UNBSLASHED       0
#define BSLASH           '\\'
#define LINEEND          '\n'
#define SLASH            '/'
#define STAR             '*'
#define INQUOTE          1
#define OUTQUOTE         0
#define INCOMMENT        1
#define OUTCOMMENT       0
#define EMPTY            '\0'

void getBalanceScore(char s[], int i);
int deStringify(int c);
// int unComment();
// int handleEscape();

int main(){
    int c, i, bSlashState, commentState, quoteState;
    char groupers[MAXSYMBS];
    // slash by itslef is a syntax error. come back to this

    bSlashState = UNBSLASHED;
    commentState = OUTCOMMENT;
    quoteState = OUTQUOTE;
    i = 0;
    while ((c = getchar()) != EOF){

        c = deStringify(c);
        // c = unComment(c, commentState)

        if (c == OPENPARANTHESES||c == CLOSEPARANTHESES||
            c == OPENBRACE ||c == CLOSBRACE||
            c == OPENBRACKET||c == CLOSBRACKET){
            groupers[i] = c;
            ++i;
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
        if (groupers[t] == CLOSEPARANTHESES)
            --parantheses;
        if (groupers[t] == CLOSBRACE)
            --braces;
        if (groupers[t] == CLOSBRACKET)
            --brackets;
    }

    if (parantheses > 0)
        printf("%d missing '%c'\n", parantheses, OPENPARANTHESES);
    if (parantheses < 0)
        printf("%d unexpexted '%c'\n", abs(parantheses), CLOSEPARANTHESES);
    if (brackets < 0)
        printf("%d missing '%c'\n", brackets, OPENBRACKET);
    if (brackets > 0)
        printf("%d unexpexted '%c'\n", abs(brackets), CLOSBRACKET);
    if (braces < 0)
        printf("%d missing '%c'\n", braces, OPENBRACE);
    if (braces > 0)
        printf("%d unexpexted '%c'\n", abs(braces), CLOSBRACE);
}

int deStringify(int c){
    int quoteState;
    quoteState = INQUOTE;
    // if (c == DOUBLEQUOTE && quoteState == OUTQUOTE)
    //     quoteState = INQUOTE;
    // if (c == DOUBLEQUOTE && quoteState == INQUOTE)
    //         quoteState = OUTQUOTE;
    if (quoteState == INQUOTE)
        c = '2'; 
    printf("%c\n", c);
    return c;
}

// // int unComment(){

// // }

// // int handleEscape(){

// // }

