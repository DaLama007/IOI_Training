#include "bits/stdc++.h"
using namespace std;

constexpr int MOD = 1e9+7;
constexpr int maxX = 1e6;
int dp[maxX];
int c[101];

int32_t main () {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,x; cin>>n >> x;
  for (int i = 0; i < n; i++) {
    cin>>c[i];
  }

  dp[0] = 1;

  for (int i = 1; i <= x; i++) {
    for (int j = 0; j < n; j++) {
      int var = c[j];
      if(i-var>=0) dp[i] = (dp[i] + dp[i-var])%MOD;
    }
  }

  cout << dp[x] << "\n";
  return 0;
}
