#include <bits/stdc++.h>
using namespace  std;


int jump(vector<int> v, long long k){
  
  int hb=0;
  for(auto var : v) {
    int ah = var-hb;
    if(k<0){
      return -1;
    }
    else if (ah==k) {
      k--;
    }
    else if (ah>k) {
      return -1;
    }
    hb=var;
  }
  return k;
}
int main (int argc, char *argv[]) {
  int tc;cin>>tc;

  while (tc--){
    long long high=10100000;
    long long low = 1;
    int n;cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin>>v[i];
    }
    int bestk = high;
    bool foundp = false;
    while (low<=high) {
      long long mid = (low+high)/2;
      int result = jump(v,mid);
      if (result>=0) {
        if (bestk>mid) {
          bestk=mid;
        }
        high = mid-1;
      }
      else{
        low = mid+1;
      }
    }
    cout<<bestk<<"\n";
   
  }
  return 0;
}

