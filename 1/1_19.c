/*
This program include the reverse function which one line at a time.
*/ 
#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char ta[], char fram[], int line);

int main(){
  int len;
  char line[MAXLINE];
  char longer[MAXLINE];


  while((len = get_line(line, MAXLINE)) > 0)
    if (len >= 0){
      reverse(line, longer, len);
      printf("%s", longer);
    }
    printf("\n");
  return 0;
}

int get_line(char s[], int lim){
  int c, i;

  for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n'){
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void copy(char to[], char from[]){
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}

void reverse(char from[], char to[], int lim){
  int i, b;
  i = lim-1;
  b = 0;
  while (from[i] >= 0){
    to[b] = from[i];
    ++b;
    --i;
  }
   
}