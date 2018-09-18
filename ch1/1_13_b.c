#include <stdio.h>

#define OUT 0
#define IN 1

int main(){

  int j, i, c, wl, hcolumn, max;
  int wlarray[11];

  int state = OUT;
  c = wl = 0;

  for (i = 0; i <= 10; ++i){
    wlarray[i] = max = 0;
  }

  while((c = getchar()) !=EOF){

    if (c == '\t' || c == ' ' || c == '\n'){
      if (wl > 10) ++wlarray[10];
      else if (wl > 0)
        ++wlarray[wl -1];
      state = OUT;
      wl = 0;
    }
    else{
      state = IN;
      ++wl;      
    }
  }

  for (i = 0; i <= 10 ; ++i){
    if (wlarray[i] >= max)
      max = wlarray[i];
  }

  printf("\n\n   Word length Frequencies:\n\n");
  printf("  |");
  for (i = 0; i <= 10; ++i){
    printf("---");
  }
  printf("-|");
  putchar('\n');

  while (max > 0){
    printf("%2d|", max);
    for (i = 0; i <= 10; ++i){
        putchar(' ');
        putchar(' ');
        if ((max - wlarray[i]) <= 0){
          putchar('*');         
        }
        else {
          putchar(' ');
        } 
      }
      printf(" |");
    putchar('\n');
    max--;
  }

  printf("  |");
  for (i = 0; i <= 10; ++i){
    printf("---");
  }
  printf("-|");

  putchar('\n');

  printf("  |");
  for (i = 0; i <= 10; ++i){
    printf("%3d", i+1);
  }
  printf(" |");
  putchar('\n');

  printf("  |");
  for (i = 0; i <= 10; ++i){
    printf("---");
  }
  printf("-|");
  putchar('\n');
  return 0;
}