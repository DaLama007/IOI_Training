#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MaxW 5000
#define MaxL 210

int count;
char words[MaxW][MaxL];
int cmp(const void *a, const void *b){
  return strcmp((char *)a,(char *)b);
}
int exists(char *w){
  for(int i=0;i<count;i++){
    if(strcmp(words[i],w)==0){
      return 1;
    }
  }
    return 0;
}
int main(int argc, char *argv[])
{
  char line[300];
  while(fgets(line,sizeof(line),stdin)){
    int i=0;int j=0;
    char word[MaxL];
    while(1){
      if(line[i]== '\0'){
        break;
      }
      while(i>=MaxL || isalpha(line[i])){
        i++;
      }
     int currPosArr=0;
    while(j<i){
      word[currPosArr]=tolower(line[j]);
      j++;
      currPosArr;
      currPosArr++;
    }
    if(exists(word)==0){
      strcpy(words[count],word);
      count++;
    }
  }
  }

  qsort(words,count,sizeof(words[0]),cmp);
  int i;
  for(i=0;i<count;i++){
    printf("%s\n", words[i]);
  }

}
