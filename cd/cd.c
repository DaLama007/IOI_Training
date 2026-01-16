#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  while(1){
  int N;
  int M;
  scanf("%d", &N);
  scanf("%d", &M);
if (N == 0 && M == 0) break;
  
  int *jackArr  = malloc(N*sizeof(int));
  int *jillArr = malloc(M*sizeof(int));
  int i;
  for (i=0;i<N;i++) {
    scanf("%d", &jackArr[i]);
  }
  for (i=0;i<M;i++) {
    scanf("%d", &jillArr[i]);
  }
  int jillPointer=0;
  int jackPointer=0;
  int result=0;
  while(jackPointer<N && jillPointer<M){

    int jackNum= jackArr[jackPointer];
    int jillNum = jillArr[jillPointer];
    if(jackNum==jillNum){
      jackPointer++;
      jillPointer++;
      result++;
    }
    else if (jackNum>jillNum) {
      jillPointer++;
    }
    else{
      jackPointer++;
    }
  }
  printf("%d\n", result);
  free(jackArr);

  free(jillArr);
}
  return 0;}
