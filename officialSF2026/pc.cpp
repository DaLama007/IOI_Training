#include "postcard.h"
#include <bits/stdc++.h>
int postcard(int N, int M){
  long long low = 1;
  long long high = N;
  long long max = N;
  while (low<high) {
    long long mid = (low+high)/2;
    int result = ask(mid);
    if(result<=M){
      if (mid<max) {
        max=mid;
      }
    }
    else if(result>M){
      high=mid-1;
    }
  }
  return max;
}
