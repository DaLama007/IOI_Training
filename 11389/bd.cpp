#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
  while(1){
    
    int n,d,r;
    cin>>n;
    if(n==0){
      break;
    }
    cin>>d>>r;
    vector<int> day;
    for (int i = 0; i < n; i++) {
      int n1;
      cin>>n1;
      day.push_back(n1);
    }
    vector<int> night;
    for (int i = 0; i < n; i++) {
      int n1;
      cin>>n1;
      night.push_back(n1);
    }

    sort(day.begin(),day.end());
    sort(night.begin(), night.end());
    
    int overpay=0;
    for (int l = 0; l < n; l++) {
      int over = day[l] + night[n-1-l] - d;
      if(over>0){
        overpay+=over;
      }
    }
    cout<<overpay*r<<"\n";

  }
  return 0;
}
