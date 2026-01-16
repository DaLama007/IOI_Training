#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{ 
  int nOps;
  while (scanf("%d" , &nOps) == 1) {
    int stack[1000];
    int prioQueue[1000];
    int queue[1000];
    int arrSize=0;
    bool isQueue = true;
    bool isPrioQueue = true;
    bool isStack = true;
    int i = 0;
    while(i<nOps){
      int opType;
      int num;
      scanf("%d %d", &opType, &num);
      i++;
      if(opType==1){
        arrSize++;
        stack[arrSize-1]=num;
        prioQueue[arrSize-1]=num;
        queue[arrSize-1]=num;
      }
      else {
        bool removed = false;
        if(isQueue){
          if(num == queue[0]){
            int j;
            for(j=1;j<arrSize;j++){
              queue[j-1]=queue[j];
            }
            removed=true;
          }
          else{
            isQueue=false;
          }

        }
        if(isPrioQueue){
          int max=prioQueue[0];
          int maxIndex=0;
          int j;
          for (j=0;j<arrSize;j++) {
            if(max<prioQueue[j]){
              max=prioQueue[j];
              maxIndex=j;
            }
  
          }
          if(num == max){
            for (j=maxIndex;j<arrSize-1;j++) {
              prioQueue[j]= prioQueue[j+1];
            }
            removed=true;
          }
          else{
            isPrioQueue=false;
          }
        }
        if(isStack){
          if(num == stack[arrSize-1]){
            removed=true;
          }
          else{
            isStack=false;
          }

        }
        if (isQueue || isPrioQueue || isStack) {
          arrSize--;
        }
      }

    }
    char * res="impossible";
    int sum=0;
    if(isQueue) sum++;
    if(isPrioQueue) sum++;
    if(isStack) sum++;
    if(sum>1){
      res = "not sure";
    }

    else{
      if(isQueue) res= "queue";
      if(isPrioQueue) res="priority queue";
      if(isStack) res="stack";
    }
    printf("%s\n",res);
  }
  return 0;


}
