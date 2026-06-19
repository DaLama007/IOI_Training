#include "bits/stdc++.h"
using namespace std;
long long a[(int)(2*1e5)];
#define int long long

int32_t main () {
  int tc; cin >> tc;

  while (tc--) {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    
    int ans = 0;
    int curr = a[0];

    for (int i = 0; i < n; i++) {
      if(curr <= a[i]){
        ans = max(ans, curr);
        curr = a[i];
      }
      else{
        curr += a[i];
      }
    }
    ans = max(curr, ans);
    cout<< ans <<"\n";
  }
  return 0;
}
