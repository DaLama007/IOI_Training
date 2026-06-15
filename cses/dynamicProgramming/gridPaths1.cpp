#include "bits/stdc++.h"
using namespace std;

int MOD = 1e9+7;

int main (int argc, char *argv[]) {
  int n; cin>>n;
  vector<string> grid(n);
  vector<vector<int>> dp(n, vector<int>(n, 0));
  
  
  char temp[n];
  cin>> temp;
  grid[0] = temp;
  if(grid[0][0] == '.') dp[0][0] = 1;
  bool isFirst = true;
  for (int i = 0; i < n; i++) {
    if (!isFirst) {
      char temp[n];
      cin>> temp;
      grid[i] = temp;
    }
    else isFirst = false;
    for (int j = 0; j < n; j++) {
      if(grid[i][j]=='.' && i-1>=0) dp[i][j]  = (dp[i][j] + dp[i-1][j])%MOD;
      if(grid[i][j]=='.' && j-1>=0) dp[i][j] = (dp[i][j] + dp[i][j-1])%MOD;
    }
  }

  cout<< dp[n-1][n-1] << "\n";

  return 0;
}
