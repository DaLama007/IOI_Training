#include "bits/stdc++.h"
using namespace std;
#define int long long
int MOD =pow(10,9)+7;

int32_t main () {
  int n; cin>>n;
  vector<int> dp(n+1, 0);
  dp[0]=1;
  dp[1]=1;
  for (int i = 2; i <= n; i++) {
    for(int j = 1; j<=6; j++){
      if(i-j>=0)dp[i]=(dp[i] + dp[i-j]) % MOD;
    }
  }
  cout<<dp[n]<<"\n";
  return 0;
}
