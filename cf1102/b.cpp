#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main () {
  int tc; cin>> tc;
  while (tc--) {
    int num; cin>> num;
    
    if(num == 10){
      cout<<"-1\n";
      continue;
    }
    int nNum = num%12;
    int coeff = num/12;

    if(nNum == 10){
      cout<<"22 "<<(coeff-1)*12<<"\n";
    }
    else{
      cout<<nNum<< " "<<coeff*12<<"\n";
    }
  }
  return 0;
}
