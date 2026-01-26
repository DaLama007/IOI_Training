#include <bits/stdc++.h>
using namspace std;

int main (int argc, char *argv[]) {
  int tc;
  cin>>tc;
  for (int o = 0; o < tc; o++) {
    int n;
    cin>>n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
      int num;
      cin>>num;
      v.push_back(num);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
      int j=0;
      int sum=-1;
      bool first= false;
      int currSum=0;
      while (v[j]<=i && j<n) {
        int currTot=0;
        for (int p = j; p > 0; p--) {
          currTot= i-i%v[p];
          currSum= (i-i%v[p])%p;

          if(currTot==i){
            break;
          }
        }
        if(first currSum){

        }

        }
        j++;
      }
      std::cout << sum<<" ";
    }
    cout<<"\n";
  }
  return 0;
}
