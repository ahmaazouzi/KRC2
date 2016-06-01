/*
The solution to a modified version of excercise 1.14 in the KR2. 
The original questions asks for a histogram of the frequency of all
characters ina a text.
This version takes the alphabet characters only.
*/

#include <stdio.h>

#define MAX 122
#define MIN 97
#define DIFF 32

int main(){
  int c = EOF;
  int i, j;
  int array[MAX - MIN];

  for (i = MIN; i <= MAX; i++){
    array[i] = 0;
  }

  while ((c = getchar()) != EOF){
    if (c >= MIN)
    ++array[c];
    else {
      ++array[c + DIFF];
    }
  }
  
  for (i = MIN; i <= MAX; i++){
    printf("|%c%c|", i - DIFF, i);
    for (j = 1; j <= array[i]; j++){
      putchar('*');
    }
    putchar('\n');  
  }

  return 0;
}

/*
Below is an example of the program's output.
*/

/*
|Aa|************************************
|Bb|**********
|Cc|***************************
|Dd|******************
|Ee|***************************************************************
|Ff|***************
|Gg|*********
|Hh|****************
|Ii|*************************************************
|Jj|
|Kk|****
|Ll|*****************************
|Mm|***************************
|Nn|**********************************
|Oo|***********************************************************
|Pp|***************
|Qq|
|Rr|**********************************************
|Ss|****************************************
|Tt|********************************************
|Uu|********************
|Vv|*****
|Ww|***
|Xx|**
|Yy|********
|Zz|
*/