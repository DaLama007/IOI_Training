#include "bits/stdc++.h"
using namespace std;

int MOD = 1e9+7;
int arr[100005];
int main (int argc, char *argv[]) {
  int n,m; cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  dp[0] = 1;

  for (int i = 1; i < n; i++) {
    if (arr[i] == 0) {
      dp[i] = 3-abs(arr[i-1]-arr[i+1])* dp[i-1];
    }
    else{
      dp[i] = dp[i-1];
    }
  }

  cout << dp[n-1] << "\n";

  return 0;
}
