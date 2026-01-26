#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
  int tc;
  cin>>tc;
  for (int i = 0; i < tc; i++) {
    int n;
    cin>>n;
    vector<int> v;
    int num;
    cin>>num;
    int max=num;
    v.push_back(num);
    int maxInd=0;
    for (int j = 1; j < n; j++) {
      cin>>num;
      if(num>max){
        max = num;
        maxInd=j;
      }
      v.push_back(num);
    }
    int switchIndex=0;
    int candidate=max;
    int canInd = maxInd;
    if(maxInd==0){
      bool found=false;
      for (int j = 1; j < n; j++) {
        if (v[j-1]-1!=v[j] && found==false) {
          max=v[j+1];
          maxInd=j+1;
          switchIndex=j;
          found=true;
          break;
        }
      }

      for (int j = switchIndex+1; j < n; j++) {
        if(max<v[j]){
          max = v[j];
          maxInd=j;
        }
      }
      if(found && maxInd<n){
        reverse(v.begin() + switchIndex, v.begin() + maxInd  + 1);
      }
    }
    else {
      reverse(v.begin() , v.begin()+maxInd+1);
    }
    for (int j = 0; j < n; j++) {
      cout<<v[j]<<" ";
    }
    cout<<"\n";
  }

  return 0;
}
