#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int comp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int main(int argc, char *argv[])
{   

  while(1){  
    int amnt;
    scanf(" %d", &amnt);
    if(amnt==0){
      return 0;
    }
    int i;
    int j;
    int classComs[amnt][5];
    for(i=0;i<amnt;i++){
      for(j=0;j<5;j++){
        int e;
        scanf(" %d", &e);
        classComs[i][j] = e;
      }
    }
    for(i=0;i<amnt;i++){
      qsort(classComs[i], 5, sizeof(int), comp);
    }

    int max = 0;
    
      int numCombs=1;
    for (i=0;i<amnt;i++) {
      int newMax=0;
      for(j=i;j<amnt;j++){
        if(memcmp(classComs[i], classComs[j], 5 * sizeof(int)) == 0){
          newMax++;
        }
      }
      if(newMax>max){
        max=newMax;
        numCombs=1;
      }
      else if(newMax==max){
        numCombs++;
      }
    }
    if(max!=1){
      printf("%d\n", max*numCombs);
    }
    else{
      printf("%d\n", amnt);
    }
  }
}
