#include "bits/stdc++.h"
using namespace std;

// seprated blocks
long long dpA[1000005];

// combined blocks
long long dpB[1000005];

int MOD = 1e9+7;
int main (int argc, char *argv[]) {
  int t; cin>>t;
    
    dpA[0] = 1;
    dpB[0] = 1;
    for (int  i = 1; i < 1000001; i++) {
      dpA[i] = (4 * dpA[i-1] + dpB[i-1]) % MOD;
      dpB[i] = (dpA[i-1] + 2 * dpB[i-1]) % MOD;
    }
    
  while (t--) {
    int h; cin>>h;
    int res = (dpA[h-1] + dpB[h-1]) % MOD;
    cout << res << "\n";
  }
  return 0;
}
