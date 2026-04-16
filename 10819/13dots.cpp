#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
  int m, n;
  cin>> m >> n;

  vector<pair<int,int>> v;
  for (int i = 0; i < n; i++) {
    int c,f; cin>>c >> f;
    v.push_back({c,f});
  }
  
  
  vector<int> dp(m+1, 0);
  dp[0] = 0;
  for(pair<int,int> var : v) {
    for (int i = m+1; i >= var.first; i--) {
      dp[i] = max(dp[i], dp[i-var.first]+var.second);
    }
  }
  cout<<dp[m+1]<<"\n";
  return 0;
}
