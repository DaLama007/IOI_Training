#include "bits/stdc++.h"
using namespace std;
int main () {
  int tc; cin>> tc;

  while (tc--) {
    int l; cin>> l;
    vector<int> v(l);
    for (int i = 0; i < l; i++) {
      cin>>v[i];
    }
    sort(v.begin(), v.end());
    if(l == 2){
      cout<< v[l-1] << " " << v[0] << "\n";
      continue;
    }
    bool working = true;
    for(int i = l-1; i>= 2; i --){
      if (v[i]%v[i-1] != v[i-2]) {
        working = false;
        break;
      }
    }
    if(working == true) cout << v[l-1] << " " << v[l-2] << "\n";
    else cout<< "-1"<<"\n";
  }
  return 0;
}
