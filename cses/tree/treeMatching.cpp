#include <bits/stdc++.h>
using namespace std;

void match(int node, int parent, vector<vector<int>> &adj, vector<vector<int>> &dp){
  int sum = 0;
  int s = adj[node].size();
  for (int i = 0; i < s; i++) {
    int n = adj[node][i];
    if(parent == n) continue;
    match(n, node, adj, dp);
    sum+= dp[adj[node][i]][1];
  }
  if(parent == -1) dp[node][0] = sum;
  else dp[node][0] = sum+1;
  
  // so lets just compare the full sum to the individual selection of children
  for (int i = 0; i < s; i++) {
    int n = adj[node][i];
    if(parent == n) continue;
    dp[node][1] = max(
        dp[n][0] - dp[n][1]+sum,
        dp[node][1]
        );
  }
}

int main (int argc, char *argv[]) {
  int n; cin >> n;
  vector<vector<int>> adj(n+1);
  vector<vector<int>> dp(n+1, vector<int>(2));
  
  for (int i = 0; i < n-1; i++) {
    int f,s; cin >> f >> s;

    adj[f].push_back(s);
    adj[s].push_back(f);
  }

  match(1, -1, adj, dp);
  int res = max(dp[1][1], dp[1][0]);

  cout << res << "\n";
  return 0;
}
