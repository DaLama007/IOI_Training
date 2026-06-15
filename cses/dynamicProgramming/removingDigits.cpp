#include "bits/stdc++.h"
using namespace std;

vector<int> dp(1e6+1, INT_MAX);
int main (int argc, char *argv[]) {
  int n; cin>> n;

  dp[n] = 0;

  for (int i = n; i >= 0; i--) {
    int numActs = dp[i];
    if(numActs==INT_MAX) continue;
    auto strNum = to_string(i);
    for(char digit: strNum) {
      int num = digit - '0';
      if(i-num>=0) dp[i-num] = min(dp[i]+1, dp[i-num]);
    }
  }

  if(dp[0] == INT_MAX) cout<<"-1\n";
  else cout<<dp[0] << "\n";
  return 0;
}
