#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main () {
  int n,x; cin>> n >> x;

  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  vector<int> dp(x+1, INT_MAX);

  dp[0] = 0;
  for (int i = 1; i <= x; i++) {
    for(auto var : c) {
      if(i-var>=0 && dp[i-var]!=INT_MAX) dp[i] = min(dp[i], 1+ dp[i-var]);
    }
  }
  if(dp[x]== INT_MAX) cout<<"-1\n";
  else cout<<dp[x]<<"\n";

  return 0;
}
