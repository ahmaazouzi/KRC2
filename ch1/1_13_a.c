#include <stdio.h>

int main(){

  int j, i, c, wl, hcolumn;
  int wlarray[11];

  int state = OUT;
  c = wl = 0;

  for (i = 0; i <= 10; ++i){
    wlarray[i] = 0;
  }

  while((c = getchar()) !=EOF){

    if (c == '\t' || c == ' ' || c == '\n'){
      if (wl > 10) ++wlarray[10];
      else if (wl > 0)
        ++wlarray[wl -1];
      wl = 0;
    }
    else{
      ++wl;      
    }
  }

  printf("|  |1  2  3  4  5  6  7  9  10  11  12  13\n");
  for (i = 0; i <= 10; ++i){

    printf("|%2d|", i+1);
    for (j = 1; j <= wlarray[i]; j++){
      putchar('*');
      putchar(' ');
      putchar(' ');
    }
    printf("\n");
  }
  return 0;
}