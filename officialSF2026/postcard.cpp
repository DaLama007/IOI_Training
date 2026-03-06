#include "postcard.h"
#include <bits/stdc++.h>
using namespace std;
int postcard(int N, int M){
  long long low = 1;
  long long high = N;
  long long max = 0;
  while (low<=high) {
    long long mid = (low+high)/2;
    long long result=0;
    if(mid==0){
      result = ask(1);
    }
    else{
      result = ask(mid);
    }
    if(result<=M){
      if (mid>max) {
        max=mid;
      }
      low=mid+1;
    }
    else if(result>M){
      high=mid-1;
    }
  }
  return max;
}
