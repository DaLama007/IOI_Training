#include "bits/stdc++.h"
using namespace std;

vector<int> dp(100005, 0);
int pages[1000];
int price[1000];


int main (int argc, char *argv[]) {
  int n, x; cin>> n >> x;
  
  for (int i = 0; i < n; i++) {
     cin >> price[i];
  }
  for (int i = 0; i < n; i++) {
     cin >> pages[i];
  }

  for (int j = 0; j < n; j++) {
    for (int i = x; i >= price[j]; i--) {
      int curprice = price[j];
      dp[i] = max(pages[j] + dp[i-curprice], dp[i]);
    }
  }

  cout << dp[x] << "\n";
  return 0;
}
