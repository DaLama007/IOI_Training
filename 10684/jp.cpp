#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
  int n;
  while (cin>>n) {
    if(n==0){
      return 0;
    }
    vector<int> v(n);
    int gM=0;
    int localMax=0;
    for (int i = 0; i < n; i++) {
      int num;
      cin>>num;
      v[i] = num;
    }
    gM=v[0];
    for(auto num: v) {
      if(localMax>=0){
        localMax+=num;
      }
      else{
        localMax=num;
      }

      gM= max(gM,localMax);
    }
    if(gM>0){
      cout<<"The maximum winning streak is "<<gM<<".\n";
    }
    else{
      cout<<"Losing streak.\n";
    }
  }
  return 0;
}
